#ifndef MUSIC_SIGN_IN_H
#define MUSIC_SIGN_IN_H

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>
#include "connectData.h"

int sign_in(char user[], char pass[], char direct[]) {

    sqlite3 *db;
    sqlite3_stmt *stmt;
    int rc;

    rc = sqlite3_open(direct, &db);
    if (rc != SQLITE_OK) {
        printf( "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    rc = sqlite3_prepare_v2(db, "SELECT pass FROM account WHERE user=?", -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        printf( "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Set the artist name parameter
    rc = sqlite3_bind_text(stmt, 1, "lap", -1, SQLITE_STATIC);
    if (rc != SQLITE_OK) {
        printf( "Failed to bind parameter: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    // Execute the SELECT statement
    rc = sqlite3_step(stmt);
    while (rc == SQLITE_ROW) {
        // Get the song name and artist name
        const char *song_name = (const char*)sqlite3_column_text(stmt,0);

        printf("%s\n", song_name);
        rc = sqlite3_step(stmt);
    }

    // Finalize the SELECT statement
    sqlite3_finalize(stmt);

    // Close the database
    sqlite3_close(db);

    return 0;
}

#endif //MUSIC_SIGN_IN_H
