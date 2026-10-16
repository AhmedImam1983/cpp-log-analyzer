cmake_minimum_required(VERSION 3.20)

project(cpp-log-analyzer
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(log_analyzer main.cpp)

target_compile_options(log_analyzer PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)
