add_library(SpeedRun
        temporary.cpp
        # linux OS
        linux/temporary.cpp
        # windows OS
        windows/temporary.cpp
        )
add_library(${PROJECT_NAME}::SpeedRun ALIAS SpeedRun)