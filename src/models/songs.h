//
// Created by ADMIN on 4/17/2023.
//

#ifndef C_SONGS_H
#define C_SONGS_H
#include <gtk/gtk.h>
#include <sqlite3.h>
#define ADD_OK 0
#define ADD_FAIL 1

typedef struct {
    gchar *image_path;
    gchar *song_title;
    gchar *artist;
    gchar *times;
} Song;

extern int so_bai_hat;
extern Song found[PATH_MAX];
extern Song my_song[PATH_MAX];
extern Song explorer[PATH_MAX];
extern Song song_in_playlist[PATH_MAX];
extern char curr_playlist_name[PATH_MAX];
extern char curr_song_name[PATH_MAX],curr_artist_name[PATH_MAX];
extern int time_curr;
void create_list_song(char name_song[]);
void create_list_song_explorer();
void create_list_song_my_music();
void create_list_song_in_playlist();
int find_song(char name_song[]);
int add_song(char name[],char artist[],char user[]);
#endif //C_SONGS_H
