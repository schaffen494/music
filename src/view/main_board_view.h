//
// Created by ADMIN on 4/17/2023.
//

#ifndef C_MAIN_BOARD_VIEW_H
#define C_MAIN_BOARD_VIEW_H
#include <gtk/gtk.h>

extern GtkWidget *main_board_win;
extern GtkWidget *main_board_fixed;
extern GtkWidget *scrolled_window ,*explorer_button,*list,
        *my_music_button,*playlist_button,*add_song_button,
        *add_playlist_button,*header_logo,*explore_icon,
        *my_music_icon,*upload_icon,*rect_area,*tab_label,*list_tmp;
extern int selected_row_index ;

void main_board_show();

#endif //C_MAIN_BOARD_VIEW_H
