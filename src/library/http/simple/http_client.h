#pragma once

#include "http_client_options.h"

#include <ydb-cpp-sdk/util/datetime/base.h>
#include <src/util/generic/hash.h>
#include <ydb-cpp-sdk/util/generic/yexception.h>
#include <ydb-cpp-sdk/util/network/socket.h>

#include <ydb-cpp-sdk/library/http/io/stream.h>
#include <ydb-cpp-sdk/library/http/misc/httpcodes.h>
#include <src/library/openssl/io/stream.h>

class TNetworkAddress;
class IOutputStream;
class TSocket;

namespace NPrivate {
    class THttpConnection;
}

/*!
 * HTTPS is supported in two modes.
 * HTTPS verification enabled by default in TKeepAliveHttpClient and disabled by default in TSimpleHttpClient.
 * HTTPS verification requires valid private certificate on server side and valid public certificate on client side.
 *
 * For client:
 * Uses builtin certs.
 * Also uses default CA path /etc/ssl/certs/ - can be provided with debian package: ca-certificates.deb.
 * It can be expanded with ENV: SSL_CERT_DIR.
 */

/*!
 * TKeepAliveHttpClient can keep connection alive with HTTP and HTTPS only if you use the same instance of class.
 * It closes connection on every socket/network error and throws error.
 * For example, HTTP code == 500 is NOT error - connection will be still open.
 * It is THREAD UNSAFE because it stores connection state in attributes.
 * If you need thread safe client, look at TSimpleHttpClient
 */

class TKeepAliveHttpClient {
public:
    using THeaders = THashMap<std::string, std::string>;
    using THttpCode = unsigned;

public:
    TKeepAliveHttpClient(const std::string& host,
                         ui32 port,
                         TDuration socketTimeout = TDuration::Seconds(5),
                         TDuration connectTimeout = TDuration::Seconds(30));

    THttpCode DoGet(const std::string_view relativeUrl,
                    IOutputStream* output = nullptr,
                    const THeaders& headers = THeaders(),
                    THttpHeaders* outHeaders = nullptr);

    // builds post request from headers and body
    THttpCode DoPost(const std::string_view relativeUrl,
                     const std::string_view body,
                     IOutputStream* output = nullptr,
                     const THeaders& headers = THeaders(),
                     THttpHeaders* outHeaders = nullptr);

    // builds request with any HTTP method from headers and body
    THttpCode DoRequest(const std::string_view method,
                        const std::string_view relativeUrl,
                        const std::string_view body,
                        IOutputStream* output = nullptr,
                        const THeaders& inHeaders = THeaders(),
                        THttpHeaders* outHeaders = nullptr);

    // requires already well-formed request
    THttpCode DoRequestRaw(const std::string_view raw,
                           IOutputStream* output = nullptr,
                           THttpHeaders* outHeaders = nullptr);

    void DisableVerificationForHttps();
    void SetClientCertificate(const TOpenSslClientIO::TOptions::TClientCert& options);

    void ResetConnection();

    const std::string& GetHost() const {
        return Host;
    }

    ui32 GetPort() const {
        return Port;
    }

private:
    template <class T>
    THttpCode DoRequestReliable(const T& raw,
                                IOutputStream* output,
                                THttpHeaders* outHeaders);

    std::vector<IOutputStream::TPart> FormRequest(std::string_view method, const std::string_view relativeUrl,
                                              std::string_view body,
                                              const THeaders& headers, std::string_view contentLength) const;

    THttpCode ReadAndTransferHttp(THttpInput& input, IOutputStream* output, THttpHeaders* outHeaders) const;

    bool CreateNewConnectionIfNeeded(); // Returns true if now we have a new connection.

private:
    using TVerifyCert = TOpenSslClientIO::TOptions::TVerifyCert;
    using TClientCert = TOpenSslClientIO::TOptions::TClientCert;

    const std::string Host;
    const ui32 Port;
    const TDuration SocketTimeout;
    const TDuration ConnectTimeout;
    const bool IsHttps;

    THolder<NPrivate::THttpConnection> Connection;
    bool IsClosingRequired;
    std::optional<TClientCert> ClientCertificate;
    std::optional<TVerifyCert> HttpsVerification;

private:
    THttpInput* GetHttpInput();

    using TIfResponseRequired = std::function<bool(const THttpInput&)>;
    TIfResponseRequired IfResponseRequired;

    friend class TSimpleHttpClient;
    friend class TRedirectableHttpClient;
};

class THttpRequestException: public yexception {
private:
    int StatusCode;

public:
    THttpRequestException(int statusCode = 0);
    int GetStatusCode() const;
};

/*!
 * TSimpleHttpClient can NOT keep connection alive.
 * It closes connection after each request.
 * HTTP code < 200 || code >= 300 is error - exception will be thrown.
 * It is THREAD SAFE because it stores only consts.
 */

class TSimpleHttpClient {
protected:
    using TVerifyCert = TKeepAliveHttpClient::TVerifyCert;

    const std::string Host;
    const ui32 Port;
    const TDuration SocketTimeout;
    const TDuration ConnectTimeout;
    bool HttpsVerification = false;

public:
    using THeaders = TKeepAliveHttpClient::THeaders;
    using TOptions = TSimpleHttpClientOptions;

public:
    explicit TSimpleHttpClient(const TOptions& options);

    TSimpleHttpClient(const std::string& host, ui32 port,
                      TDuration socketTimeout = TDuration::Seconds(5), TDuration connectTimeout = TDuration::Seconds(30));

    void EnableVerificationForHttps();

    void DoGet(const std::string_view relativeUrl, IOutputStream* output, const THeaders& headers = THeaders()) const;

    // builds post request from headers and body
    void DoPost(const std::string_view relativeUrl, std::string_view body, IOutputStream* output, const THeaders& headers = THeaders()) const;

    // requires already well-formed post request
    void DoPostRaw(const std::string_view relativeUrl, std::string_view rawRequest, IOutputStream* output) const;

    virtual ~TSimpleHttpClient();

private:
    TKeepAliveHttpClient CreateClient() const;

    virtual void PrepareClient(TKeepAliveHttpClient& cl) const;
    virtual void ProcessResponse(const std::string_view relativeUrl, THttpInput& input, IOutputStream* output, const unsigned statusCode) const;
};

class TRedirectableHttpClient: public TSimpleHttpClient {
public:
    TRedirectableHttpClient(const std::string& host, ui32 port, TDuration socketTimeout = TDuration::Seconds(5),
                            TDuration connectTimeout = TDuration::Seconds(30));

private:
    void PrepareClient(TKeepAliveHttpClient& cl) const override;
    void ProcessResponse(const std::string_view relativeUrl, THttpInput& input, IOutputStream* output, const unsigned statusCode) const override;
};

namespace NPrivate {
    class THttpConnection {
    public:
        THttpConnection(const std::string& host,
                        ui32 port,
                        TDuration sockTimeout,
                        TDuration connTimeout,
                        bool isHttps,
                        const std::optional<TOpenSslClientIO::TOptions::TClientCert>& clientCert,
                        const std::optional<TOpenSslClientIO::TOptions::TVerifyCert>& verifyCert);

        bool IsOk() const {
            return IsNotSocketClosedByOtherSide(Socket);
        }

        template <typename TContainer>
        void Write(const TContainer& request) {
            HttpOut->Write(request.data(), request.size());
            HttpIn = Ssl ? MakeHolder<THttpInput>(Ssl.Get())
                         : MakeHolder<THttpInput>(&SocketIn);
            HttpOut->Flush();
        }

        THttpInput* GetHttpInput() {
            return HttpIn.Get();
        }

    private:
        static TNetworkAddress Resolve(const std::string& host, ui32 port);

        static TSocket Connect(TNetworkAddress& addr,
                               TDuration sockTimeout,
                               TDuration connTimeout,
                               const std::string& host,
                               ui32 port);

    private:
        TNetworkAddress Addr;
        TSocket Socket;
        TSocketInput SocketIn;
        TSocketOutput SocketOut;
        THolder<TOpenSslClientIO> Ssl;
        THolder<THttpInput> HttpIn;
        THolder<THttpOutput> HttpOut;
    };
}

template <class T>
TKeepAliveHttpClient::THttpCode TKeepAliveHttpClient::DoRequestReliable(const T& raw,
                                                                        IOutputStream* output,
                                                                        THttpHeaders* outHeaders) {
    for (int i = 0; i < 2; ++i) {
        const bool haveNewConnection = CreateNewConnectionIfNeeded();
        const bool couldRetry = !haveNewConnection && i == 0; // Actually old connection could be already closed by server,
                                                              // so we should try one more time in this case.
        try {
            Connection->Write(raw);

            THttpCode code = ReadAndTransferHttp(*Connection->GetHttpInput(), output, outHeaders);
            if (!Connection->GetHttpInput()->IsKeepAlive()) {
                IsClosingRequired = true;
            }
            return code;
        } catch (const TSystemError& e) {
            Connection.Reset();
            if (!couldRetry || e.Status() != EPIPE) {
                throw;
            }
        } catch (const THttpReadException&) { // Actually old connection is already closed by server
            Connection.Reset();
            if (!couldRetry) {
                throw;
            }
        } catch (const std::exception&) {
            Connection.Reset();
            throw;
        }
    }
    Y_ABORT(); // We should never be here.
    return 0;
}
