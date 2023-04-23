//
// Created by ADMIN on 4/18/2023.
//

#include "upload.h"
#include "src/view/main_board_view.h"
#include "src/control/main_board_control.h"
GtkWidget *label_song_upload, *entry_song_upload;
GtkWidget *label_artist_upload, *entry_artist_upload;
GtkWidget *label_image_upload, *image_file_upload;
GtkWidget *label_music_upload, *music_file_upload;
GtkWidget *upload_button,*upload_fixed;

void upload_show()
{
    GdkRGBA color_upload;
    gdk_rgba_parse(&color_upload, "white");
    upload_fixed = gtk_fixed_new();
    gtk_fixed_put(GTK_FIXED(main_board_fixed), upload_fixed, 0, 0);

    label_song_upload = gtk_label_new("Song Name:");
    gtk_fixed_put(GTK_FIXED(upload_fixed), label_song_upload, 410, 150);
    gtk_widget_override_color(label_song_upload , GTK_STATE_NORMAL, &color_upload);

    entry_song_upload = gtk_entry_new();
    gtk_widget_set_size_request(entry_song_upload, 200, -1);
    gtk_fixed_put(GTK_FIXED(upload_fixed), entry_song_upload, 410, 200);


    label_artist_upload = gtk_label_new("Artist:");
    gtk_fixed_put(GTK_FIXED(upload_fixed), label_artist_upload, 410, 250);
    gtk_widget_override_color(label_artist_upload, GTK_STATE_NORMAL, &color_upload);

    entry_artist_upload = gtk_entry_new();
    gtk_widget_set_size_request(entry_artist_upload, 200, -1);
    gtk_fixed_put(GTK_FIXED(upload_fixed), entry_artist_upload, 410, 300);

    label_image_upload = gtk_label_new("Select Image:");
    gtk_fixed_put(GTK_FIXED(upload_fixed), label_image_upload, 410, 350);
    gtk_widget_override_color(label_image_upload, GTK_STATE_NORMAL, &color_upload);

    image_file_upload = gtk_file_chooser_button_new("Select Image File", GTK_FILE_CHOOSER_ACTION_OPEN);
    gtk_widget_set_size_request(image_file_upload, 200, -1);
    gtk_fixed_put(GTK_FIXED(upload_fixed), image_file_upload, 410, 400);

    label_music_upload = gtk_label_new("Select Music:");
    gtk_fixed_put(GTK_FIXED(upload_fixed), label_music_upload, 410, 450);
    gtk_widget_override_color(label_music_upload, GTK_STATE_NORMAL, &color_upload);

    music_file_upload = gtk_file_chooser_button_new("Select Music File", GTK_FILE_CHOOSER_ACTION_OPEN);
    gtk_widget_set_size_request(music_file_upload, 200, -1);
    gtk_fixed_put(GTK_FIXED(upload_fixed), music_file_upload, 410, 500);

    upload_button = gtk_button_new_with_label("Upload");
    gtk_widget_set_size_request(upload_button, 80, 35);
    gtk_fixed_put(GTK_FIXED(upload_fixed), upload_button, 410, 550);
    g_signal_connect(upload_button, "clicked", G_CALLBACK(upload_new_song), NULL);

    gtk_widget_show_all(main_board_fixed);
}