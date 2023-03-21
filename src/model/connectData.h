#ifndef MUSIC_CONNECTDATA_H
#define MUSIC_CONNECTDATA_H

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

// check connect with database
int connectData(char *direct, char *notification, int *status) {
    sqlite3 *db;
    char *dbm = direct;

    int rc = sqlite3_open(dbm, &db);
    if (rc != SQLITE_OK) {
        strcpy(notification, "Cannot open database");
        sqlite3_close(db);
        return 1;
    }

    strcpy(notification, "Connection is successful!");
    sqlite3_close(db);
    printf("12");
    return 0;
}

#endif //MUSIC_CONNECTDATA_H
