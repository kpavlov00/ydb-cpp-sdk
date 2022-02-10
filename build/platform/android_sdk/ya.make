RESOURCES_LIBRARY() 
 
OWNER(g:mapkit) 
 
IF (NOT OS_ANDROID) 
    MESSAGE(FATAL_ERROR Unsupported platform) 
ENDIF() 
 
IF (HOST_OS_LINUX) 
    # Android SDK for linux: Build-Tools 30.0.3, Platform 30
    DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE( 
        ANDROID_SDK 
        sbr:2564045529 FOR LINUX 
    ) 
    DECLARE_EXTERNAL_RESOURCE(ANDROID_AVD sbr:2563860055) 
ELSE() 
    MESSAGE(FATAL_ERROR Unsupported host platform) 
ENDIF() 
 
END() 
