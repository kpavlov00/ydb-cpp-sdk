OWNER(
    workfork
)

RESOURCES_LIBRARY()

IF(NOT HOST_OS_LINUX AND NOT HOST_OS_WINDOWS AND NOT HOST_OS_DARWIN)
    MESSAGE(FATAL_ERROR Unsupported platform for YFM tool)
ENDIF()

DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
    YFM_TOOL
    sbr:2614616596 FOR DARWIN-ARM64
    sbr:2614616596 FOR DARWIN
    sbr:2614615780 FOR LINUX
    sbr:2614617315 FOR WIN32
)

END()
