#ifndef MUSIC_DB_SIGNIN_H
#define MUSIC_DB_SIGNIN_H
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>
#include "connectData.h"
int db_signin(char user[], char pass[], char direct[],int *status) {

    sqlite3 *db;
    sqlite3_stmt *stmt;
    int rc;

    rc = sqlite3_open(direct, &db);
    if (rc != SQLITE_OK) {
        printf( "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        *status= 1;
        return 3;
    }

    rc = sqlite3_prepare_v2(db, "SELECT pass FROM account WHERE user=?", -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        printf( "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        *status= 1;
        return 2;
    }

    // Set the artist name parameter
    rc = sqlite3_bind_text(stmt, 1, user, -1, SQLITE_STATIC);
    if (rc != SQLITE_OK) {
        printf( "Failed to bind parameter: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        *status= 1;
        return 1;
    }

    // Execute the SELECT statement
    rc = sqlite3_step(stmt);
    int dem=0;
    while (rc == SQLITE_ROW) {
        // Get the song name and artist name
        char *password = (char*)sqlite3_column_text(stmt,0);
        printf("%s\n", password);
        dem++;
        rc = sqlite3_step(stmt);
    }

    // Finalize the SELECT statement
    sqlite3_finalize(stmt);

    // Close the database
    sqlite3_close(db);
    if(dem==0)
    {
        *status= 1;
    }
    else
    {
        *status= 0;
    }
    return 0;
}

#endif //MUSIC_DB_SIGNIN_H
