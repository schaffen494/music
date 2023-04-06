//
// Created by ADMIN on 3/25/2023.
//

#include "main_menu.h"
#include "searchBar.h"
#include "selection_menu.h"

static void delete_all_children_of_container(GtkWidget *content_grid)
{
    GList *children_list = gtk_container_get_children(GTK_CONTAINER(content_grid));
    int i = 0;

    for (; i < g_list_length(children_list); i++)
    {
        gtk_container_remove(GTK_CONTAINER(content_grid), g_list_nth_data(children_list, i));
    }
}

static void on_login_clicked(GtkButton *button, gpointer user_data)
{
    // Xử lý sự kiện khi người dùng nhấn nút Đăng nhập
}

static void on_register_clicked(GtkButton *button, gpointer user_data) {
    // Xử lý sự kiện khi người dùng nhấn nút Đăng ký
}

static void on_search_clicked(GtkButton *button, gpointer user_data) {
    // Xử lý sự kiện khi người dùng nhấn nút Tìm kiếm
    create_Searchbar(user_data);
}

void create_menu(GtkWidget *window) {
    GtkWidget *content_grid;
    GtkWidget *menu_bar;
    GtkWidget *file_menu;
    GtkWidget *file_menu_item;
    GtkWidget *login_menu_item;
    GtkWidget *register_menu_item;
    GtkWidget *search_menu_item;
    GtkWidget *selection_menu_item;

    // Tạo content grid
    content_grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), content_grid);

    // Tạo selection menu
    create_selection_menu(content_grid);

    // Tạo menu bar
    menu_bar = gtk_menu_bar_new();
    gtk_grid_attach(GTK_GRID(content_grid), menu_bar, 1, 0, 1, 1);

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
    g_signal_connect(search_menu_item, "activate", G_CALLBACK(on_search_clicked), window);
}