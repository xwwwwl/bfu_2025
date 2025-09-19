cmake_minimum_required(VERSION 3.15) # Проверка версии CMake
				     # Если версия установленной программы страее указанной, произайдет аварийный выход.
set(PROJECT_NAME project_2)	     # Задать значение PROJECT_NAME
project("${PROJECT_NAME}")	     # Установить имя проекта

set(CMAKE_CXX_STANDARD 20)           # Устанавливаем 17 стандарт языка


# Сказать программу, что должен быть исполняемый файл
add_executable("${PROJECT_NAME}" main.cpp)