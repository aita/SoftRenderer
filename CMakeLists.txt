cmake_minimum_required (VERSION 3.0)
project(SoftRenderer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)

include(cmake/stb.cmake)

file(GLOB SOURCES src/*.cc src/*.h)

add_executable(SoftRenderer
    ${SOURCES}
)

target_link_libraries(SoftRenderer
    Eigen3::Eigen
    stb
)
