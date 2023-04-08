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
    // Tạo thanh phát nhạc
    GtkWidget *player = gtk_toolbar_new();
    gtk_toolbar_set_style(GTK_TOOLBAR(player), GTK_TOOLBAR_ICONS);

    GtkToolItem *play_pause_button = gtk_tool_button_new_from_stock(GTK_STOCK_MEDIA_PLAY);
    GtkToolItem *next_track_button = gtk_tool_button_new_from_stock(GTK_STOCK_MEDIA_NEXT);

    GtkToolItem *previous_track_button = gtk_tool_button_new_from_stock(GTK_STOCK_MEDIA_PREVIOUS);


    gtk_toolbar_insert(GTK_TOOLBAR(player), play_pause_button, -1);
    gtk_toolbar_insert(GTK_TOOLBAR(player), next_track_button, -1);
    gtk_toolbar_insert(GTK_TOOLBAR(player), previous_track_button, -1);
    gtk_grid_attach(GTK_GRID(grid), player, 1, 3, 1, 1);
}
#endif //C_PLAY_MUSIC_TASKBAR_H
