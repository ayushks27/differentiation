cmake_minimum_required(VERSION 3.15)

project(Differentiation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES
    src/*.cpp
)

add_executable(differentiation ${SOURCES})

target_include_directories(differentiation PRIVATE
    src
    src/third_party/crow
    src/third_party/json/single_include
    src/third_party/asio
)

target_compile_definitions(differentiation PRIVATE
    ASIO_STANDALONE
)

if (WIN32)
    target_link_libraries(differentiation
        ws2_32
        mswsock
    )
endif()

