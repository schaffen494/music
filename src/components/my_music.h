//
// Created by Nhat on 4/11/2023.
//

#ifndef MY_MUSIC_H
#define MY_MUSIC_H

#include <gtk/gtk.h>

GtkWidget *my_music_label,
          *my_music_hbox;

void create_my_music_tab(GtkWidget *my_music_sub_fixed)
{
    // Tạo label my music
    my_music_label = gtk_label_new("My music");
    gtk_widget_set_name(my_music_label, "my_music_label");
    gtk_fixed_put(GTK_FIXED(my_music_sub_fixed), my_music_label, 350, 150);

    // Tạo các nút song, playlist, album
    my_music_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_fixed_put(GTK_FIXED(my_music_sub_fixed), my_music_hbox, 350, 220);
    GtkWidget *song = gtk_button_new_with_label("Song"),
              *playlist = gtk_button_new_with_label("Playlist"),
              *album = gtk_button_new_with_label("Album");
    gtk_button_set_relief(song, GTK_RELIEF_NONE);
    gtk_button_set_relief(playlist, GTK_RELIEF_NONE);
    gtk_button_set_relief(album, GTK_RELIEF_NONE);
    gtk_widget_set_name(song, "main_buttons");
    gtk_widget_set_name(playlist, "main_buttons");
    gtk_widget_set_name(album, "main_buttons");
    gtk_box_pack_start(GTK_BOX(my_music_hbox), song, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(my_music_hbox), playlist, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(my_music_hbox), album, FALSE, FALSE, 0);

    //Load file css
    GtkCssProvider *provider = gtk_css_provider_new();
    GtkStyleContext *my_music_label_context,
                    *song_button_context,
                    *playlist_button_context,
                    *album_button_context;
    GError *error = NULL;

    gtk_css_provider_load_from_path(provider, "src\\properties\\my_music.css", &error);
    if (error)
    {
        g_warning ("%s", error->message);
        g_clear_error (&error);
    }

    my_music_label_context = gtk_widget_get_style_context(my_music_label);
    song_button_context = gtk_widget_get_style_context(song);
    playlist_button_context = gtk_widget_get_style_context(playlist);
    album_button_context = gtk_widget_get_style_context(album);

    gtk_style_context_add_provider(my_music_label_context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    gtk_style_context_add_provider(song_button_context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    gtk_style_context_add_provider(playlist_button_context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    gtk_style_context_add_provider(album_button_context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
}

void hide_my_music_tab()
{
    gtk_widget_hide(my_music_label);
    gtk_widget_hide(my_music_hbox);
}

void show_my_music_tab()
{
    gtk_widget_show(my_music_label);
    gtk_widget_show(my_music_hbox);
}
#endif //MY_MUSIC_H