OWNER(trenin17)
RESOURCES_LIBRARY()
INCLUDE(${ARCADIA_ROOT}/build/platform/java/jdk/resources.inc)

DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
    JDK13
    ${JDK13_DARWIN} FOR DARWIN
    ${JDK13_LINUX} FOR LINUX
    ${JDK13_WINDOWS} FOR WIN32
)

IF(OS_DARWIN)
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK13 ${JDK13_DARWIN})
ELSEIF(OS_LINUX)
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK13 ${JDK13_LINUX})
ELSEIF(OS_WINDOWS)
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK13 ${JDK13_WINDOWS})
ENDIF()

IF(SANITIZER_TYPE == "address")
    IF(HOST_OS_LINUX)
        DECLARE_EXTERNAL_RESOURCE(JDK_FOR_TESTS ${JDK13_LINUX_ASAN})
    ELSE()
        MESSAGE(FATAL_ERROR Unsupported platform for JDK13 with asan)
    ENDIF()
ENDIF()

END()
