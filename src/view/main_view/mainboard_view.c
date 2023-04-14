//
// Created by ADMIN on 4/13/2023.
//

#include "mainboard_view.h"
#include "src/view/components/musicbar.h"
#include "src/view/components/menu.h"
#include "src/view/components/searchBar.h"
#include <stdio.h>
GtkWidget *main_board_window;
GtkWidget* fixed;
void main_board_show()
{
    // Create a window
    main_board_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_decorated(GTK_WINDOW(main_board_window), FALSE);
    gtk_window_set_position(GTK_WINDOW(main_board_window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(main_board_window), 1500, 800);
    gtk_window_set_title(GTK_WINDOW(main_board_window), "Mystic melody");


    GdkRGBA color;
    gdk_rgba_parse(&color, "#1f1f1e");
    gtk_widget_override_background_color(main_board_window, GTK_STATE_FLAG_NORMAL, &color);

    // Tạo fixed container để set vị trí của các Widget
    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(main_board_window), fixed);

    create_MusicBar(fixed);
    menu_show();
    searchBar(fixed);

    // Xử lý sự kiện đóng cửa sổ
    g_signal_connect(G_OBJECT(main_board_window), "destroy", G_CALLBACK(exit), NULL);
    gtk_widget_show_all(main_board_window);
    gtk_main();
}