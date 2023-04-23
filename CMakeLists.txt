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
        src/main.c src/config/database_config.c src/config/database_config.h src/view/intro_view.c src/view/intro_view.h src/view/components/menu.c src/view/components/menu.h src/view/components/music_bar.c src/view/components/music_bar.h src/view/components/search_bar.c src/view/components/search_bar.h src/view/sign_in_view.c src/view/sign_in_view.h src/models/users.c src/models/users.h src/control/sign_in_control.c src/control/sign_in_control.h src/view/main_board_view.c src/view/main_board_view.h src/view/sign_up_view.c src/view/sign_up_view.h src/control/sign_up_control.c src/control/sign_up_control.h src/control/main_board_control.c src/control/main_board_control.h src/models/songs.c src/models/songs.h src/models/playlist.c src/models/playlist.h src/view/components/upload.c src/view/components/upload.h "src/view/components/add_playlist.c" "src/view/components/add_playlist.h")
target_link_libraries(${PROJECT_NAME} ${GTK3_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${SQLITE3_LIBRARY})