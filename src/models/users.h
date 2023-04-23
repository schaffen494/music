//
// Created by ADMIN on 4/16/2023.
//

#ifndef C_USERS_H
#define C_USERS_H
#include <limits.h>
#include <sqlite3.h>
#include<stdio.h>
#define LOGIN_OK 0
#define LOGIN_FAIL 1
#define SIGNUP_OK 0
#define SIGNUP_FAIL 1
extern char username_current[PATH_MAX];

int check_sign_in(char username[],char password[]);
int add_account(char username[], char password[]);
#endif //C_USERS_H
