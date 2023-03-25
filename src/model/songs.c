//
// Created by ADMIN on 3/25/2023.
//

#include "songs.h"
#include<stdlib.h>
#include<stdio.h>
#include<sqlite3.h>

int add_song(sqlite3 *db, Song *song) {
    char *err_msg = 0;
    char sql[200];

    sprintf(sql, "INSERT INTO Song (Title, Artist, Year, Album) VALUES ('%s', '%s', %d, '%s')",
            song->title, song->artist, song->year, song->album);

    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        return 0;
    }

    printf("Song added successfully\n");
    return 1;
}

int get_song()
{

}