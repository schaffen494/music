//
// Created by ADMIN on 3/26/2023.
//

#include "main_board.h"
void main_board_show()
{

    // Tạo cửa sổ
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Zing MP3");
    gtk_window_set_default_size(GTK_WINDOW(window), 1500, 800);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    g_signal_connect(window, "destroy", G_CALLBACK(exit), NULL);

    // Tạo thanh menu
    GtkWidget *menubar = gtk_menu_bar_new();
    GtkWidget *filemenu = gtk_menu_new();
    GtkWidget *editmenu = gtk_menu_new();
    GtkWidget *viewmenu = gtk_menu_new();
    GtkWidget *helpmenu = gtk_menu_new();

    GtkWidget *file = gtk_menu_item_new_with_label("File");
    GtkWidget *edit = gtk_menu_item_new_with_label("Edit");
    GtkWidget *view = gtk_menu_item_new_with_label("View");
    GtkWidget *help = gtk_menu_item_new_with_label("Help");

    GtkWidget *new_playlist = gtk_menu_item_new_with_label("New Playlist");
    GtkWidget *open_file = gtk_menu_item_new_with_label("Open File");
    GtkWidget *exit = gtk_menu_item_new_with_label("Exit");

    GtkWidget *play_pause = gtk_menu_item_new_with_label("Play/Pause");
    GtkWidget *next_track = gtk_menu_item_new_with_label("Next Track");
    GtkWidget *previous_track = gtk_menu_item_new_with_label("Previous Track");

    GtkWidget *volume_up = gtk_menu_item_new_with_label("Volume Up");
    GtkWidget *volume_down = gtk_menu_item_new_with_label("Volume Down");

    GtkWidget *about = gtk_menu_item_new_with_label("About");

    gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), new_playlist);
    gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), open_file);
    gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), exit);

    gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), play_pause);
    gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), next_track);
    gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), previous_track);

    gtk_menu_shell_append(GTK_MENU_SHELL(viewmenu), volume_up);
    gtk_menu_shell_append(GTK_MENU_SHELL(viewmenu), volume_down);

    gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), about);

    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), file);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), edit);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), view);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(file), filemenu);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(edit), editmenu);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(view), viewmenu);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);

    // Tạo thanh phát nhạc
    GtkWidget *player = gtk_toolbar_new();
    gtk_toolbar_set_style(GTK_TOOLBAR(player), GTK_TOOLBAR_ICONS);

    GtkToolItem *play_pause_button = gtk_tool_button_new_from_stock(GTK_STOCK_MEDIA_PLAY);
    GtkToolItem *next_track_button = gtk_tool_button_new_from_stock(GTK_STOCK_MEDIA_NEXT);

    GtkToolItem *previous_track_button = gtk_tool_button_new_from_stock(GTK_STOCK_MEDIA_PREVIOUS);


    gtk_toolbar_insert(GTK_TOOLBAR(player), play_pause_button, -1);
    gtk_toolbar_insert(GTK_TOOLBAR(player), next_track_button, -1);
    gtk_toolbar_insert(GTK_TOOLBAR(player), previous_track_button, -1);


// Tạo header có thanh tìm kiếm
    GtkWidget *header = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

    GtkWidget *search_entry = gtk_search_entry_new();
    GtkWidget *search_icon = gtk_image_new_from_icon_name("edit-find-symbolic", GTK_ICON_SIZE_SMALL_TOOLBAR);

    gtk_box_pack_start(GTK_BOX(header), search_entry, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(header), search_icon, FALSE, FALSE, 0);

// Tạo button account và setting
    GtkWidget *account_button = gtk_button_new_from_icon_name("user-symbolic", GTK_ICON_SIZE_SMALL_TOOLBAR);
    GtkWidget *setting_button = gtk_button_new_from_icon_name("preferences-system-symbolic", GTK_ICON_SIZE_SMALL_TOOLBAR);

// Sắp xếp các thành phần UI vào cửa sổ
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), player, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), header, FALSE, FALSE, 0);
    gtk_box_pack_end(GTK_BOX(vbox), account_button, FALSE, FALSE, 0);
    gtk_box_pack_end(GTK_BOX(vbox), setting_button, FALSE, FALSE, 0);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER_ALWAYS);

// Hiển thị cửa sổ và chạy vòng lặp chính của GTK
    gtk_widget_show_all(window);
    gtk_main();

}

