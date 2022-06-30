cmake_minimum_required(VERSION 3.22)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

#
#add_library(testlib SHARED IMPORTED)
#set_property(TARGET testlib PROPERTY IMPORTED_LOCATION "lib/libmodbus/lib/libmodbus.so*")

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(untitled1 main.cpp)
target_link_libraries(untitled1 PRIVATE Threads::Threads)


# Libmodbus library
#include(modbus.cmake)
#
## Find all source files with file extension .c/.cpp inside src folder
#file(GLOB_RECURSE PROJECT_SRCS "main.cpp" "src/*.c" "src/*.cpp")
#
## Add source files to project
#add_executable(
#        ${PROJECT_NAME}
#        ${PROJECT_SRCS}
#)
#
## Include project header files
#target_include_directories(
#        ${PROJECT_NAME}
#        PUBLIC include
#)
#
#target_link_libraries(
#        ${PROJECT_NAME}
#        PRIVATE modbus
#)