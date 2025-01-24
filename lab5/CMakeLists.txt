project(lab5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug) 

add_executable(lab5 main.cpp functions.h functions.cpp EulerMethod.h EulerMethod.cpp constants.h two_sided_Runge_Kutta.cpp two_sided_Runge_Kutta.h)