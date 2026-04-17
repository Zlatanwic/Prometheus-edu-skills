cmake_minimum_required(VERSION 3.16)
project(wordfreq LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

add_compile_options(-Wall -Wextra -Wpedantic)

# ----- library with student code -----
add_library(wordfreq_lib STATIC
    src/wordfreq.cpp
)
target_include_directories(wordfreq_lib PUBLIC src)

# ----- CLI binary -----
add_executable(wordfreq src/main.cpp)
target_link_libraries(wordfreq PRIVATE wordfreq_lib)

# ----- tests -----
enable_testing()
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.5.4
)
FetchContent_MakeAvailable(Catch2)

add_subdirectory(tests)
