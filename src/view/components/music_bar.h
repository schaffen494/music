//
// Created by ADMIN on 4/16/2023.
//

#ifndef C_MUSIC_BAR_H
#define C_MUSIC_BAR_H
#include <gtk/gtk.h>
extern GtkWidget *button_play_pause,*image_song_avatar , *back_button, *skip_button, *sound_label, *progress_bar, *time_label, *song_label, *artist_label;
extern GtkWidget *image;
extern gboolean is_playing;
extern gdouble progress;
extern gdouble step;
extern gdouble duration;
extern gboolean update_progress_bar(gpointer data);
extern int min,sec;
void music_bar_show();
#endif //C_MUSIC_BAR_H
