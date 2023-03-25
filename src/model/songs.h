//
// Created by ADMIN on 3/25/2023.
//

#ifndef MUSIC_SONGS_H
#define MUSIC_SONGS_H
#include<stdio.h>
#include<sqlite3.h>
typedef struct {
    int id;
    char title[50];
    char artist[50];
    int year;
    char album[50];
} Song;

int add_song(sqlite3 *db, Song *song);

int get_song();

#endif //MUSIC_SONGS_H
