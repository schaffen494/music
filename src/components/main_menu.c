//
// Created by ADMIN on 3/25/2023.
//

#include "main_menu.h"

static void on_login_clicked(GtkButton *button, gpointer user_data) {
    // Xử lý sự kiện khi người dùng nhấn nút Đăng nhập
}

static void on_register_clicked(GtkButton *button, gpointer user_data) {
    // Xử lý sự kiện khi người dùng nhấn nút Đăng ký
}

static void on_search_clicked(GtkButton *button, gpointer user_data) {
    // Xử lý sự kiện khi người dùng nhấn nút Tìm kiếm
}

void create_menu(GtkWidget *window) {
    GtkWidget *menu_bar;
    GtkWidget *file_menu;
    GtkWidget *file_menu_item;
    GtkWidget *login_menu_item;
    GtkWidget *register_menu_item;
    GtkWidget *search_menu_item;

    // Tạo menu bar
    menu_bar = gtk_menu_bar_new();
    gtk_container_add(GTK_CONTAINER(window), menu_bar);

    // Tạo menu File
    file_menu = gtk_menu_new();
    file_menu_item = gtk_menu_item_new_with_label("File");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(file_menu_item), file_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), file_menu_item);

    // Tạo menu Login
    login_menu_item = gtk_menu_item_new_with_label("Đăng nhập");
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), login_menu_item);
    g_signal_connect(login_menu_item, "activate", G_CALLBACK(on_login_clicked), NULL);

    // Tạo menu Register
    register_menu_item = gtk_menu_item_new_with_label("Đăng ký");
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), register_menu_item);
    g_signal_connect(register_menu_item, "activate", G_CALLBACK(on_register_clicked), NULL);

    // Tạo menu Search
    search_menu_item = gtk_menu_item_new_with_label("Tìm kiếm");
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), search_menu_item);
    g_signal_connect(search_menu_item, "activate", G_CALLBACK(on_search_clicked), NULL);
}