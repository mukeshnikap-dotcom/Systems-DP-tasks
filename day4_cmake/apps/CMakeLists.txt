add_executable(ackermann_app main.cpp)

# Link the internal kinematics library
target_link_libraries(ackermann_app PRIVATE kinematics)

# Strict warning flags enforced on the app
target_compile_options(ackermann_app PRIVATE -Wall -Wextra -Werror)
