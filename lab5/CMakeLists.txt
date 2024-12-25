project(lab5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab5 main.cpp functions.h functions.cpp EulerMethod.h EulerMethod.cpp constants.h two_sided.cpp two_sided.h)