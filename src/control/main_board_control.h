//
// Created by ADMIN on 4/17/2023.
//

#ifndef C_MAIN_BOARD_CONTROL_H
#define C_MAIN_BOARD_CONTROL_H
#include <gtk/gtk.h>

void search_song();
void on_button_toggled(GtkToggleButton *togglebutton, gpointer data);
void logout_click();
void tab_explorer_click();
void tab_my_music_click();
void tab_playlist_click();
void upload();
void add_playlist();
void selected(GtkListBox *listbox, GtkListBoxRow *row, gpointer user_data);
void upload_new_song(GtkWidget *widget, gpointer data);
extern void play_music();
void copy_file(const char *src_path, const char *dest_path);
void add_new_playlist();
void add_song_to_playlist();
void remove_song_to_playlist();
#endif //C_MAIN_BOARD_CONTROL_H
