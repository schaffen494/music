cmake_minimum_required(VERSION 3.24)
project(music C)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})

set(MYSQL_CONNECTOR_C_DIR "C:/Program Files/MySQL/MySQL Connector C 6.1")
include_directories(${MYSQL_CONNECTOR_C_DIR}/include)
link_directories(${MYSQL_CONNECTOR_C_DIR}/lib)



set(CMAKE_C_STANDARD 11)
set(MYSQL_LIBRARIES ${MYSQL_LIBRARY})

add_executable(music src/main.c)
target_link_libraries(music ${GTK3_LIBRARIES})
target_link_libraries(music ${MYSQL_CONNECTOR_C_DIR}/lib/libmysql.lib)


