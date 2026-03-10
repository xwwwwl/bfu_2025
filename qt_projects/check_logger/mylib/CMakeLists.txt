cmake_minimum_required(VERSION 3.15)
find_package(Qt6 REQUIRED COMPONENTS Core)

set(PROJECT_NAME mylib)
project("${PROJECT_NAME}")

# Меняем на C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)  # OFF = чистый C++, без расширений

# Проверка поддержки (опционально)
message(STATUS "Setting C++ standard to: ${CMAKE_CXX_STANDARD}")

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_library("${PROJECT_NAME}" STATIC
    inc/logger.hpp
    src/logger.cpp
)

target_include_directories("${PROJECT_NAME}" PUBLIC inc)

target_link_libraries("${PROJECT_NAME}"
    PRIVATE
        Qt6::Core
)

target_compile_definitions("${PROJECT_NAME}" PRIVATE
    $<$<CONFIG:Debug>:QT_DEBUG>
)

# Проверка версии C++ после сборки
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Building with C++ standard: ${CMAKE_CXX_STANDARD}"
)
