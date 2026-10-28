add_library(kinematics kinematics.cpp)

# Target include directories
target_include_directories(kinematics 
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
)

# Strict warning flags enforced on this target
target_compile_options(kinematics PRIVATE -Wall -Wextra -Werror)
