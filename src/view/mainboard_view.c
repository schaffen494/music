//
// Created by ADMIN on 4/6/2023.
//

#include "mainboard_view.h"

GtkWidget *main_board_window;
void main_board_show()
{
    main_board_window= gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(main_board_window), "Signup");
    gtk_window_set_position(GTK_WINDOW(main_board_window), GTK_WIN_POS_CENTER);
    gtk_widget_set_size_request(main_board_window, 1500, 800);
    // Hiển thị cửa sổ
    gtk_widget_show_all(main_board_window);

    // Xử lý sự kiện đóng cửa sổ
    g_signal_connect(G_OBJECT(main_board_window), "destroy", G_CALLBACK(exit), NULL);

    // Chạy vòng lặp GTK
    gtk_main();
}