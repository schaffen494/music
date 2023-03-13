#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>


int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Spotify");
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    GtkWidget *label_logo = gtk_label_new("Spotify Logo");
    gtk_grid_attach(GTK_GRID(grid), label_logo, 0, 0, 2, 1);

    GtkWidget *entry_search = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry_search, 2, 0, 4, 1);

    GtkWidget *listbox = gtk_list_box_new();
    gtk_grid_attach(GTK_GRID(grid), listbox, 0, 1, 6, 6);

    GtkWidget *label_song = gtk_label_new("Song Name");
    gtk_list_box_insert(GTK_LIST_BOX(listbox), label_song, 0);

    GtkWidget *label_artist = gtk_label_new("Artist Name");
    gtk_list_box_insert(GTK_LIST_BOX(listbox), label_artist, 1);

    GtkWidget *button_play = gtk_button_new_with_label("Play");
    gtk_grid_attach(GTK_GRID(grid), button_play, 0, 7, 1, 1);

    GtkWidget *button_pause = gtk_button_new_with_label("Pause");
    gtk_grid_attach(GTK_GRID(grid), button_pause, 1, 7, 1, 1);

    GtkWidget *button_next = gtk_button_new_with_label("Next");
    gtk_grid_attach(GTK_GRID(grid), button_next, 2, 7, 1, 1);

    GtkWidget *button_previous = gtk_button_new_with_label("Previous");
    gtk_grid_attach(GTK_GRID(grid), button_previous, 3, 7, 1, 1);

    GtkWidget *progressbar = gtk_progress_bar_new();
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progressbar), 0.5);
    gtk_grid_attach(GTK_GRID(grid), progressbar, 4, 7, 2, 1);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

