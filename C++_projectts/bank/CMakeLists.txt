cmake_minimum_required(VERSION 3.15)   # Проверка версии CMake
                                       # Если версия ниже указанной, произойдет аварийный выход.

set(PROJECT_NAME bank)                   # Задать значение PROJECT_NAME
project("${PROJECT_NAME}")            # Установить имя проекта

set(CMAKE_CXX_STANDARD 20)             # Устанавливаем стандарт языка C++20

file(GLOB SOURCE_CPP "*.cpp")


set(SOURCE_FILES                     # Список исходных файлов
    main.cpp
    help_func.cpp
    error.cpp
    command.cpp
    ui.cpp
)

add_executable("${PROJECT_NAME}" ${SOURCE_FILES})  # Создаем исполняемый файл