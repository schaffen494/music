//
// Created by ADMIN on 4/8/2023.
//

#ifndef C_SONGS_H
#define C_SONGS_H
#include "src/constant.h"
#include <gtk/gtk.h>
#include <sqlite3.h>
typedef struct {
    gchar *image_path;
    gchar *song_title;
    gchar *artist;
    gchar *times;
} Song;
extern int so_bai_hat;
extern Song songs[PATH_MAX];
void create_list_song(GtkWidget *list);
int explorer();
int my_music_create(GtkWidget *list);
void play_music();
#endif //C_SONGS_H
