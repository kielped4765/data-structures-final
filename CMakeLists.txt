cmake_minimum_required(VERSION 3.16)

project(AerospaceFlightDataLookup VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(run_app)

target_sources(run_app
    PRIVATE
        src/main.cpp
        src/ChainedHashTable.cpp
)

target_include_directories(run_app
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    
)

target_compile_options(run_app
    PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:/W4 /permissive->
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic>
)