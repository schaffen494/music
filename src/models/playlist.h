//
// Created by ADMIN on 4/17/2023.
//

#ifndef C_PLAYLIST_H
#define C_PLAYLIST_H
#include <gtk/gtk.h>
#include <sqlite3.h>
#define ADD_OK 0
#define ADD_FAIL 1
#define DELETE_OK 0
#define DELETE_FAIL 1
typedef struct {
    gchar *image_path;
    gchar *playlist_title;
    gchar *quantity;
} Playlist;

extern Playlist playlist[PATH_MAX];
void create_playlist(GtkWidget *list_tmp);
int add_new_playlists(char name[]);
int add_new_song_to_playlist(char name_playlist[],char name_song[]);
int remove_song_out_playlist(char name_playlist[],char name_song[]);
int delete_playlist(char name_playlist[]);

#endif //C_PLAYLIST_H
