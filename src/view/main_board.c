//
// Created by ADMIN on 3/26/2023.
//

#include "main_board.h"
void main_board_show()
{
    /* create main window */
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(window, 1500, 800);
    GdkRGBA color;
    gdk_rgba_parse(&color, "#0a0931");
    gtk_widget_override_background_color(window, GTK_STATE_FLAG_NORMAL, &color);
    gtk_window_set_title(GTK_WINDOW(window), "Desktop Music Streaming");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    g_signal_connect(window, "destroy", G_CALLBACK(exit), NULL);
    /* create vertical box to hold list and controls */
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), box);

    /* create scrolled window to hold list of songs */
    GtkWidget *scroll = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_box_pack_start(GTK_BOX(box), scroll, TRUE, TRUE, 0);

    /* create list of songs */
    GtkWidget *list = gtk_list_box_new();
    gtk_container_add(GTK_CONTAINER(scroll), list);

    /* create horizontal box to hold add and remove buttons */
    GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_pack_end(GTK_BOX(box), hbox, FALSE, FALSE, 0);

    /* create add button */
    GtkWidget *add_button = gtk_button_new_with_label("Add Song");
    gtk_box_pack_start(GTK_BOX(hbox), add_button, FALSE, FALSE, 0);

    /* create remove button */
    GtkWidget *remove_button = gtk_button_new_with_label("Remove Song");
    gtk_box_pack_start(GTK_BOX(hbox), remove_button, FALSE, FALSE, 0);

    /* create play button */
    GtkWidget *play_button = gtk_button_new_from_icon_name("media-playback-start", GTK_ICON_SIZE_BUTTON);
    gtk_box_pack_end(GTK_BOX(box), play_button, FALSE, FALSE, 0);

    /* create pause button */
    GtkWidget *pause_button = gtk_button_new_from_icon_name("media-playback-pause", GTK_ICON_SIZE_BUTTON);
    gtk_box_pack_end(GTK_BOX(box), pause_button, FALSE, FALSE, 0);

    /* create stop button */
    GtkWidget *stop_button = gtk_button_new_from_icon_name("media-playback-stop", GTK_ICON_SIZE_BUTTON);
    gtk_box_pack_end(GTK_BOX(box), stop_button, FALSE, FALSE, 0);

    /* create label for song information */
    GtkWidget *song_label = gtk_label_new("Now Playing: None");
    gtk_box_pack_end(GTK_BOX(box), song_label, FALSE, FALSE, 0);

    /* create label for song duration */
    GtkWidget *duration_label = gtk_label_new("Duration: 00:00");
    gtk_box_pack_end(GTK_BOX(box), duration_label, FALSE, FALSE, 0);

    /* create image for song cover */
    GtkWidget *cover_image = gtk_image_new();
    gtk_box_pack_start(GTK_BOX(box), cover_image, FALSE, FALSE, 0);

    /* show all widgets */
    gtk_widget_show_all(window);

    gtk_main();
}

