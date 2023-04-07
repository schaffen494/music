#ifndef C_DATABASE_CONFIG_H
#define C_DATABASE_CONFIG_H
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include<sqlite3.h>
#include <stdlib.h>
extern char absolute_path[PATH_MAX];
extern char absolute_project[PATH_MAX];
void set_path();
#endif //C_DATABASE_CONFIG_H
