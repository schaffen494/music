cmake_minimum_required(VERSION 3.17)
project(music C)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

find_library(SQLITE3_LIBRARY sqlite3 HINTS lib/)
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})

set(CMAKE_C_STANDARD 11)

add_executable(music src/main.c src/view/ui_init.h src/view/main_menu.h src/view/start_screen.h src/controller/sign_in.h src/model/db_signin.h src/controller/end.h src/controller/sign_out.h src/model/db_songs.h)
target_link_libraries(music ${GTK3_LIBRARIES})
target_link_libraries(music ${SQLITE3_LIBRARY})
