add_library(SpeedRun
        temporary.cpp
        cache.cpp
        keygen.cpp
        regedit.cpp
        mount_pkgb.cpp
        # date.cpp
        # linux OS
        linux/temporary.cpp
        # windows OS
        windows/temporary.cpp
        windows/cache.cpp
        )
add_library(${PROJECT_NAME}::SpeedRun ALIAS SpeedRun)