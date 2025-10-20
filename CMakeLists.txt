cmake_minimum_required(VERSION 3.16)
project(my_project LANGUAGES CXX)

# C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Папка с заголовками (если есть include/)
include_directories(${PROJECT_SOURCE_DIR}/include)

# Два исполняемых файла
add_executable(1 src/1.cpp)
add_executable(2  src/2.cpp)
add_executable(3  src/3.cpp)
add_executable(4  src/4.cpp)
add_executable(5  src/4.cpp)

# Кладём бинарники в build/bin
set_target_properties(1 2 3 4 5 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# (опционально) включить инфраструктуру тестов
enable_testing()
