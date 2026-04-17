cmake_minimum_required(VERSION 3.16)
project(csvstat LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()
add_compile_options(-Wall -Wextra -Wpedantic)

add_library(csvstat_lib STATIC
    src/parser.cpp
    src/stats.cpp
    src/report.cpp
)
target_include_directories(csvstat_lib PUBLIC src)

add_executable(csvstat src/main.cpp)
target_link_libraries(csvstat PRIVATE csvstat_lib)

enable_testing()
include(FetchContent)
FetchContent_Declare(Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.5.4)
FetchContent_MakeAvailable(Catch2)
add_subdirectory(tests)
