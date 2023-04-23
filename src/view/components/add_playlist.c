//
// Created by ADMIN on 4/18/2023.
//

#include "add_playlist.h"
#include "src/view/main_board_view.h"
#include "src/control/main_board_control.h"
GtkWidget *label_name_playlist, *entry_name_playlist,
        *label_image_playlist, *image_playlist,
        *add_playlist_fixed,*playlist_add_button,*add_playlist_fixed;

void add_playlist_show()
{
    GdkRGBA color_upload;
    gdk_rgba_parse(&color_upload, "white");
    add_playlist_fixed = gtk_fixed_new();
    gtk_fixed_put(GTK_FIXED(main_board_fixed), add_playlist_fixed, 0, 0);

    label_name_playlist = gtk_label_new("Name of playlist:");
    gtk_fixed_put(GTK_FIXED(add_playlist_fixed), label_name_playlist, 410, 150);
    gtk_widget_override_color(label_name_playlist , GTK_STATE_NORMAL, &color_upload);

    entry_name_playlist = gtk_entry_new();
    gtk_widget_set_size_request( entry_name_playlist , 200, -1);
    gtk_fixed_put(GTK_FIXED(add_playlist_fixed),  entry_name_playlist , 410, 200);

    label_image_playlist = gtk_label_new("Select Image:");
    gtk_fixed_put(GTK_FIXED(add_playlist_fixed), label_image_playlist, 410, 250);
    gtk_widget_override_color(label_image_playlist, GTK_STATE_NORMAL, &color_upload);

    image_playlist = gtk_file_chooser_button_new("Select Image File", GTK_FILE_CHOOSER_ACTION_OPEN);
    gtk_widget_set_size_request(image_playlist, 200, -1);
    gtk_fixed_put(GTK_FIXED(add_playlist_fixed), image_playlist, 410, 300);


    playlist_add_button = gtk_button_new_with_label("Add playlist");
    gtk_widget_set_size_request(playlist_add_button, 80, 35);
    gtk_fixed_put(GTK_FIXED(add_playlist_fixed), playlist_add_button, 410, 350);
    g_signal_connect(playlist_add_button, "clicked", G_CALLBACK(add_new_playlist), NULL);

    gtk_widget_show_all(main_board_fixed);
}