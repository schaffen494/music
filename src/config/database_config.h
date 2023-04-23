#ifndef C_DATABASE_CONFIG_H
#define C_DATABASE_CONFIG_H
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include<sqlite3.h>
#include <stdlib.h>
#include <string.h>
extern char absolute_path[PATH_MAX];
extern char absolute_project[PATH_MAX];
extern char path_file[PATH_MAX];
void set_path();

void get_path(char name_file[]);
#endif //C_DATABASE_CONFIG_H
