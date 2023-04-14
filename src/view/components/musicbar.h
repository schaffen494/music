//
// Created by ASUS on 4/3/2023.
//

#ifndef MUSIC_MUSICBAR_H
#define MUSIC_MUSICBAR_H
#include <gtk/gtk.h>
#include <glib.h>
#include <glib-object.h>
#include <math.h>

extern GtkWidget  *time_label, *song_label, *artist_label,*image;

void create_MusicBar(GtkWidget* fixed);

#endif //MUSIC_MUSICBAR_H