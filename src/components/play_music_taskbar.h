//
// Created by ADMIN on 4/8/2023.
//

#ifndef C_PLAY_MUSIC_TASKBAR_H
#define C_PLAY_MUSIC_TASKBAR_H
#include <gtk/gtk.h>

static void play_pause_button_clicked(GtkButton *button, gpointer data) {
    // Xử lý khi nút play/pause được nhấn
}

static void next_button_clicked(GtkButton *button, gpointer data) {
    // Xử lý khi nút next được nhấn
}

static void prev_button_clicked(GtkButton *button, gpointer data) {
    // Xử lý khi nút prev được nhấn
}
void init_play_music_taskbar(GtkWidget *grid)
{
    GtkWidget *toolbar = gtk_toolbar_new();
    gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);
    gtk_widget_set_size_request(GTK_WIDGET(toolbar), 1200, 100);
    gtk_grid_attach(GTK_GRID(grid), toolbar, 1, 3, 1, 1);

    GtkToolItem *prev_button = gtk_tool_button_new(NULL, "Prev");
    GtkWidget *prev_icon = gtk_image_new_from_file("prev.png");
    gtk_tool_button_set_icon_widget(GTK_TOOL_BUTTON(prev_button), prev_icon);
    g_signal_connect(G_OBJECT(prev_button), "clicked", G_CALLBACK(prev_button_clicked), NULL);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), prev_button, -1);

    GtkToolItem *play_pause_button = gtk_tool_button_new(NULL, "Play/Pause");
    GtkWidget *play_pause_icon = gtk_image_new_from_file("play_pause.png");
    gtk_tool_button_set_icon_widget(GTK_TOOL_BUTTON(play_pause_button), play_pause_icon);
    g_signal_connect(G_OBJECT(play_pause_button), "clicked", G_CALLBACK(play_pause_button_clicked), NULL);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), play_pause_button, -1);

    GtkToolItem *next_button = gtk_tool_button_new(NULL, "Next");
    GtkWidget *next_icon = gtk_image_new_from_file("next.png");
    gtk_tool_button_set_icon_widget(GTK_TOOL_BUTTON(next_button), next_icon);
    g_signal_connect(G_OBJECT(next_button), "clicked", G_CALLBACK(next_button_clicked), NULL);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), next_button, -1);

    GtkWidget *title_label = gtk_label_new("Title");
    GtkToolItem *title_item = gtk_tool_item_new();
    gtk_container_add(GTK_CONTAINER(title_item), title_label);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), title_item, -1);

    GtkWidget *artist_label = gtk_label_new("Artist");
    GtkToolItem *artist_item = gtk_tool_item_new();
    gtk_container_add(GTK_CONTAINER(artist_item), artist_label);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), artist_item, -1);

    GtkWidget *progress_bar = gtk_progress_bar_new();
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress_bar), 0.5);
    GtkToolItem *progress_item = gtk_tool_item_new();
    gtk_container_add(GTK_CONTAINER(progress_item), progress_bar);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), progress_item, -1);

    GtkWidget *volume_label = gtk_label_new("Volume");
    GtkToolItem *volume_item = gtk_tool_item_new();
    gtk_container_add(GTK_CONTAINER(volume_item), volume_label);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), volume_item, -1);

    GtkWidget *volume_bar = gtk_progress_bar_new();
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(volume_bar), 0.8);
    GtkToolItem *volume_bar_item = gtk_tool_item_new();
    gtk_container_add(GTK_CONTAINER(volume_bar_item), volume_bar);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), volume_bar_item, -1);
}
#endif //C_PLAY_MUSIC_TASKBAR_H
