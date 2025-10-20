cmake_minimum_required(VERSION 3.16)
project(my_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включаем папку с заголовками
include_directories(${PROJECT_SOURCE_DIR}/include)

# Исполняемый файл
add_executable(${PROJECT_NAME} src/main.cpp)

# Тесты (опционально: ctest + GoogleTest, подключите позже)
enable_testing()
