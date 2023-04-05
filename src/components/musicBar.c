//
// Created by ASUS on 4/3/2023.
//
#include "musicBar.h"

GtkWidget *play_button, *stop_button, *back_button, *skip_button;

void play_song(GtkWidget *widget, gpointer data) {
    g_print("Playing song...\n");
    gtk_widget_hide(play_button);
    gtk_widget_show(stop_button);
}

// Callback function for the "Stop" button
void stop_song(GtkWidget *widget, gpointer data) {
    g_print("Stopping song...\n");
    gtk_widget_hide(stop_button);
    gtk_widget_show(play_button);
}

// Callback function for the "Back" button
void back_song(GtkWidget *widget, gpointer data) {
    g_print("Going back to previous song...\n");
}

// Callback function for the "Skip" button
void skip_song(GtkWidget *widget, gpointer data) {
    g_print("Skipping to next song...\n");
}

void on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    // Set the color and thickness of the rectangle border
    cairo_set_source_rgb(cr, 0.5, 0.5, 0.5);
    cairo_set_line_width(cr, 2.0);

    // Draw the rectangle
    cairo_rectangle(cr, 0, 0, 1500, 100);
    cairo_stroke(cr);
}

void create_MusicBar(GtkWidget* window) {
    // Create the fixed container
    GtkWidget* fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);

    // Create the drawing /
    GtkWidget *rect_area = gtk_drawing_area_new();

// Set the dimensions and position of the rectangle
    gtk_widget_set_size_request(rect_area, 1500, 120);
    gtk_fixed_put(GTK_FIXED(fixed), rect_area, 0, 684);
    // Draw the rectangle
    g_signal_connect(rect_area, "draw", G_CALLBACK(on_draw_event), NULL);


    // Create the play button
    play_button = gtk_button_new_with_label("");
    gtk_fixed_put(GTK_FIXED(fixed), play_button, 714, 715);
    gtk_button_set_relief(GTK_BUTTON(play_button), GTK_RELIEF_NONE);
    GdkPixbuf *pixbuf_play = gdk_pixbuf_new_from_file("assets/play_button.svg", NULL);
    GtkImage *image_play = gtk_image_new_from_pixbuf(pixbuf_play);
    gtk_button_set_image(GTK_BUTTON(play_button), GTK_WIDGET(image_play));
    gtk_widget_show(image_play);

// Create the stop button
    stop_button = gtk_button_new_with_label("");
    gtk_fixed_put(GTK_FIXED(fixed), stop_button, 714, 715);
    gtk_button_set_relief(GTK_BUTTON(stop_button), GTK_RELIEF_NONE);
    GdkPixbuf *pixbuf_stop = gdk_pixbuf_new_from_file("assets/stop_button.svg", NULL);
    GtkImage *image_stop = gtk_image_new_from_pixbuf(pixbuf_stop);
    gtk_button_set_image(GTK_BUTTON(stop_button), GTK_WIDGET(image_stop));
    gtk_widget_show(image_stop);

    // Create the back button
    back_button = gtk_button_new_with_label("");
    gtk_fixed_put(GTK_FIXED(fixed), back_button, 650, 715);
    gtk_button_set_relief(GTK_BUTTON(back_button), GTK_RELIEF_NONE);
    GdkPixbuf *pixbuf_back= gdk_pixbuf_new_from_file("assets/backward_button.svg", NULL);
    GtkImage *image_back= gtk_image_new_from_pixbuf(pixbuf_back);
    gtk_button_set_image(GTK_BUTTON(back_button), GTK_WIDGET(image_back));
    gtk_widget_show(image_back);

    // Create the skip button
    skip_button = gtk_button_new_with_label("");
    gtk_fixed_put(GTK_FIXED(fixed), skip_button, 775, 715);
    gtk_button_set_relief(GTK_BUTTON(skip_button), GTK_RELIEF_NONE);
    GdkPixbuf *pixbuf_skip = gdk_pixbuf_new_from_file("assets/forward_button.svg", NULL);
    GtkImage *image_skip = gtk_image_new_from_pixbuf(pixbuf_skip);
    gtk_button_set_image(GTK_BUTTON(skip_button), GTK_WIDGET(image_skip));
    gtk_widget_show(image_skip);

    // Connect the buttons to their callback functions
    g_signal_connect(play_button, "clicked", G_CALLBACK(play_song), NULL);
    g_signal_connect(stop_button, "clicked", G_CALLBACK(stop_song), NULL);
    g_signal_connect(back_button, "clicked", G_CALLBACK(back_song), NULL);
    g_signal_connect(skip_button, "clicked", G_CALLBACK(skip_song), NULL);

    // Add the buttons to a horizontal box and add the box to the fixed container
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_pack_start(GTK_BOX(box), back_button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), play_button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), stop_button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), skip_button, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(fixed), box);

    // Hide the stop button
    gtk_widget_hide(stop_button);
    gtk_main();
}



