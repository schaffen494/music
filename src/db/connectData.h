#ifndef MUSIC_CONNECT_DATA_H
#define MUSIC_CONNECT_DATA_H
#include <sqlite3.h>
#include <string.h>
#include<stdio.h>
#define LOGIN_OK 0
#define LOGIN_FAIL 1
#define SIGNUP_OK 0
#define SIGNUP_FAIL 1

int check_Sign_in(char username[], char password[]);

int add_account(char username[], char password[]);
#endif //MUSIC_CONNECT_DATA_H
