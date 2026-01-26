cmake_minimum_required(VERSION 3.15)   # Проверка версии CMake
                                       # Если версия ниже указанной, произойдет аварийный выход.

set(PROJECT_NAME tm)                   # Задать значение PROJECT_NAME
project("${PROJECT_NAME}")            # Установить имя проекта

set(CMAKE_CXX_STANDARD 20)             # Устанавливаем стандарт языка C++20




set(SOURCE_FILES                     # Список исходных файлов
    main.cpp
    src/error.cpp          
    src/command.cpp
    src/help_func.cpp
    src/storage.cpp  
    src/save_tasks.cpp       
    src/storage.cpp              
    src/task_logic.cpp                
    src/ui.cpp       
)

add_executable("${PROJECT_NAME}" ${SOURCE_FILES})  # Создаем исполняемый файл