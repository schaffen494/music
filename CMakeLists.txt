cmake_minimum_required(VERSION 3.17)
project(music C)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

find_library(SQLITE3_LIBRARY sqlite3 HINTS lib/)
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})

set(CMAKE_C_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(music src/main.c src/constant.h src/view/intro.c src/view/intro.h src/components/main_menu.c src/components/main_menu.h src/view/ui_init.c src/view/ui_init.h src/model/songs.c src/model/songs.h)

target_link_libraries(music ${GTK3_LIBRARIES})
target_link_libraries(music ${SQLITE3_LIBRARY})