#ifndef SONGS_H
#define SONGS_H
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

struct song{
    char *name;
    char *artist;
    char *avatar;
};

int add_song(char name[], char artist[], char direct[], int *status) {

    sqlite3 *db;
    char *err_msg = 0;
    int rc;

    // Open the database file
    rc = sqlite3_open(direct, &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Prepare the SQL statement
    const char *sql = "INSERT INTO songs (name, artist) VALUES (?, ?)";
    sqlite3_stmt *stmt;

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, artist, -1, SQLITE_STATIC);

    // Execute the statement
    rc = sqlite3_step(stmt);

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    // Clean up
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}

int delete_songs(char name[], char artist[], char direct[], int *status)
{
    sqlite3 *db;
    char *err_msg = 0;
    int rc;

    // Open the database file
    rc = sqlite3_open(direct, &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Prepare the SQL statement
    const char *sql = "DELETE FROM songs WHERE name = ?";
    sqlite3_stmt *stmt;

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);

    // Execute the statement
    rc = sqlite3_step(stmt);

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    // Clean up
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}
#endif