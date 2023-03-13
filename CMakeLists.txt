cmake_minimum_required(VERSION 3.24)
project(music C)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})

set(CMAKE_C_STANDARD 11)

add_executable(music src/main.c)
target_link_libraries(music ${GTK3_LIBRARIES})


