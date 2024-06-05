cmake_minimum_required(VERSION 3.10)

project(BusinessProject)

# Укажите стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавьте библиотечные цели для ваших классов
add_library(Restaurant src/Restaurant.cpp)
add_library(BusinessMediator src/BusinessMediator.cpp)
add_library(EstateOwner src/EstateOwner.cpp)
add_library(GroceryStore src/GroceryStore.cpp)

# Включите заголовочные файлы для всех библиотек
target_include_directories(Restaurant PUBLIC include)
target_include_directories(BusinessMediator PUBLIC include)
target_include_directories(EstateOwner PUBLIC include)
target_include_directories(GroceryStore PUBLIC include)

# Подключите GoogleTest
add_subdirectory(${CMAKE_SOURCE_DIR}/third_party/googletest EXCLUDE_FROM_ALL)

# Создайте исполняемый файл для тестов
add_executable(tests src/tests.cpp)

# Свяжите исполняемый файл с необходимыми библиотеками
target_link_libraries(tests 
    Restaurant 
    BusinessMediator 
    EstateOwner 
    GroceryStore 
    gtest 
    gtest_main
)

# Включите заголовочные файлы для тестов
target_include_directories(tests PUBLIC include)
