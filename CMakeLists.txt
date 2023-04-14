cmake_minimum_required(VERSION 3.17)
project(${PROJECT_NAME} C)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

find_library(SQLITE3_LIBRARY sqlite3 HINTS lib/)
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})

set(PROJECT_DIR ${PROJECT_SOURCE_DIR})
set(CMAKE_C_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(${PROJECT_NAME}
        src/main.c
        src/constant.h
        src/config/database_config.h
        src/config/database_config.c src/view/main_view/intro_view.c src/view/main_view/intro_view.h src/view/main_view/signin_view.c src/view/main_view/signin_view.h src/models/users.c src/models/users.h src/view/main_view/signup_view.c src/view/main_view/signup_view.h src/view/main_view/mainboard_view.c src/view/main_view/mainboard_view.h src/view/components/musicbar.c src/view/components/musicbar.h src/view/components/menu.c src/view/components/menu.h src/view/components/searchBar.c src/view/components/searchBar.h src/models/songs.c src/models/songs.h src/models/playlist.c src/models/playlist.h)

target_link_libraries(${PROJECT_NAME} ${GTK3_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${SQLITE3_LIBRARY})