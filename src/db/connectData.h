//
// Created by ADMIN on 3/26/2023.
//

#ifndef MUSIC_CONNECTDATA_H
#define MUSIC_CONNECTDATA_H
#include <sqlite3.h>
#include <string.h>
#include<stdio.h>
#define LOGIN_OK 0
#define LOGIN_FAIL 1
#define SIGNUP_FAIL 1
int check_Signin(char username[], char password[]);

int set_account();
#endif //MUSIC_CONNECTDATA_H
