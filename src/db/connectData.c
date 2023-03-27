//
// Created by ADMIN on 3/26/2023.
//

#include "connectData.h"
#include <sqlite3.h>
#include <string.h>
#include<stdio.h>
#define LOGIN_OK 0
#define LOGIN_FAIL 1
int check_Signin(char username[], char password[])
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc;


    // Mở kết nối tới cơ sở dữ liệu SQLite
    rc = sqlite3_open("D:/music/src/db/music.db", &db);

    if (rc != SQLITE_OK) {
        printf("Can not access to database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // Truy vấn username và password từ bảng users
    const char* sql = "SELECT * FROM users WHERE username = ? AND password = ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        printf("Error: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // Thiết lập giá trị tham số cho truy vấn
    char* user_name = username;
    char* pass_word = password;
    sqlite3_bind_text(stmt, 1, username, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password, -1, SQLITE_STATIC);

    // Thực hiện truy vấn
    rc = sqlite3_step(stmt);

    if (rc == SQLITE_ROW) {
        return LOGIN_OK;
    } else {
        return LOGIN_FAIL;
    }

    // Giải phóng tài nguyên
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
