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

add_executable(music
        src/main.c
        src/constant.h
        src/view/intro.c
        src/view/intro.h
        src/view/main_board.c
        src/view/main_board.h
        src/view/sign_in.c
        src/view/sign_in.h
        src/view/sign_up.c
        src/view/sign_up.h
        src/components/main_menu.c
        src/components/main_menu.h
        src/components/searchBar.h
        src/model/songs.c
        src/model/songs.h
        src/model/user.c
        src/model/user.h
        src/db/connectData.c
        src/db/connectData.h
        src/components/searchBar.h
        src/components/searchBar.css)

target_link_libraries(music ${GTK3_LIBRARIES})
target_link_libraries(music ${SQLITE3_LIBRARY})