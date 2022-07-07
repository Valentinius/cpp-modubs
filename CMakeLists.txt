cmake_minimum_required(VERSION 3.22)
project(modbus-library-cpp)

set(CMAKE_CXX_STANDARD 14)

#
#add_library(testlib SHARED IMPORTED)
#set_property(TARGET testlib PROPERTY IMPORTED_LOCATION "lib/libmodbus/lib/libmodbus.so*")


file(GLOB_RECURSE PROJECT_SRCS "main.cpp" "src/*.c" "src/*.cpp")

#add_executable(${PROJECT_NAME} main.cpp)

# Add source files to project
add_executable(
        ${PROJECT_NAME}
        ${PROJECT_SRCS}
)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)


# Include project header files
target_include_directories(
        ${PROJECT_NAME}
        PUBLIC include
        PUBLIC include/clients
        PUBLIC include/clients/async
        PUBLIC include/clients/sync
        PUBLIC include/framers
        PUBLIC include/session
        PUBLIC include/utils
)





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