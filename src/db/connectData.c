#include "connectData.h"
#include <sqlite3.h>
#include <string.h>
#include<stdio.h>
sqlite3* db;
sqlite3_stmt* stmt;
char *err_msg = 0;
int rc;

int connect()
{
    // Mở kết nối tới cơ sở dữ liệu SQLite
    rc = sqlite3_open("D:/music/src/db/music.db", &db);

    if (rc != SQLITE_OK) {
        printf("Can not access to database: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return LOGIN_FAIL;
    }
    return 0;
}
int check_Sign_in(char username[], char password[])
{
    connect();
    // Truy vấn username và password từ bảng users
    const char* sql = "SELECT * FROM users WHERE username = ? AND password = ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        printf("Error: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return LOGIN_FAIL;
    }

    // Thiết lập giá trị tham số cho truy vấn
    sqlite3_bind_text(stmt, 1, username, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password, -1, SQLITE_STATIC);

    // Thực hiện truy vấn
    rc = sqlite3_step(stmt);

    if (rc == SQLITE_ROW) {
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return LOGIN_OK;
    } else {
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return LOGIN_FAIL;
    }

    // Giải phóng tài nguyên

}

int add_account(char username[], char password[])
{
    connect();
    //truy vấn account
    char* sql = "SELECT * FROM users WHERE username = ? ";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        printf("Error: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return SIGNUP_FAIL;
    }

    // Thiết lập giá trị tham số cho truy vấn
    sqlite3_bind_text(stmt, 1, username, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password, -1, SQLITE_STATIC);

    // Thực hiện truy vấn
    rc = sqlite3_step(stmt);

    //kiểm tra tài khoản đã tồn tại hay chưa
    if (rc == SQLITE_ROW)
    {
        sqlite3_finalize(stmt);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return SIGNUP_FAIL;
    }
    else{

        // thêm account mới vào database
        char *insert_sql = sqlite3_mprintf("INSERT INTO users (user_id,username, password) VALUES ((SELECT COALESCE(MAX(user_id), 0) + 1 FROM users),'%s', '%s');",
                                           username, password);
        rc = sqlite3_exec(db, insert_sql, 0, 0, &err_msg);
        if (rc != SQLITE_OK) {
            printf("SQL error: %s\n", err_msg);
            sqlite3_finalize(stmt);
            sqlite3_free(err_msg);
            sqlite3_close(db);
            return SIGNUP_FAIL;
        } else{
            // đóng database
            sqlite3_finalize(stmt);
            sqlite3_free(err_msg);
            sqlite3_close(db);
            return SIGNUP_OK;
        }
    }

}

int get_list()
{

}
int add_playlist()
{

}
int delete_song_playlist()
{

}
int add_song_playlist()
{

}
int get_found_song()
{

}