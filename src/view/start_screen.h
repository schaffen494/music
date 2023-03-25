//
// Created by Nhat on 3/22/2023.
//

#ifndef MUSIC_START_SCREEN_H
#define MUSIC_START_SCREEN_H
#include <gtk/gtk.h>

extern GtkWidget *window,
                 *main_box,
                 *start_screen_vbox,
                 *start_screen_button,
                 *start_screen_label,
                 *main_menu_vbox;

void open_main_menu();

// Khởi tạo các widgets trong start screen
void start_screen_init()
{
    // Tạo hộp đựng các widget
    start_screen_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(main_box), start_screen_vbox);

    // Tạo nhãn welcome
    start_screen_label = gtk_label_new("Welcome to Music Streaming App!");
    gtk_box_pack_start(GTK_BOX(start_screen_vbox), start_screen_label, FALSE, FALSE, 0);

    // Tạo một nút bấm
    start_screen_button = gtk_button_new_with_label("Play");
    gtk_box_pack_start(GTK_BOX(start_screen_vbox), start_screen_button, FALSE, FALSE, 0);
    g_signal_connect(G_OBJECT(start_screen_button), "clicked", G_CALLBACK(open_main_menu), NULL);
}

// Đóng vbox của start screen và mở vbox của main menu
void open_main_menu()
{
    gtk_widget_set_visible(start_screen_vbox, 0);
    gtk_widget_set_visible(main_menu_vbox, 1);
}

#endif //MUSIC_START_SCREEN_H
