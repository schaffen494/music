//
// Created by ADMIN on 4/6/2023.
//

#include "mainboard_view.h"
#include "src/components/selection_menu.h"
#include "src/components/musicBar.h"
#include "src/components/my_music.h"

GtkWidget *main_board_window;
void main_board_show()
{
    // Create a window
    GtkWidget *main_board_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(main_board_window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(main_board_window), 1500, 800);
    gtk_window_set_title(GTK_WINDOW(main_board_window), "Mystic melody");

    GdkRGBA color;
    gdk_rgba_parse(&color, "#1f1f1e");
    gtk_widget_override_background_color(main_board_window, GTK_STATE_FLAG_NORMAL, &color);

    // Tạo fixed container để set vị trí của các Widget
    GtkWidget* fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(main_board_window), fixed);

    // Tạo selection menu
    create_selection_menu(fixed);

    // Tạo music bar
    create_MusicBar(fixed);

    // Tạo tab my music
    GtkWidget *my_music_sub_fixed = gtk_fixed_new();
    gtk_fixed_put(GTK_FIXED(fixed), my_music_sub_fixed, 0, 0);
    create_my_music_tab(my_music_sub_fixed);

    // Xử lý sự kiện đóng cửa sổ
    g_signal_connect(G_OBJECT(main_board_window), "destroy", G_CALLBACK(exit), NULL);

    gtk_widget_show_all(main_board_window);
    hide_my_music_tab();
    gtk_main();
}