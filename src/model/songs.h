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


#endif //MUSIC_SONGS_H
