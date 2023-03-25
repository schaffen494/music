//
// Created by ADMIN on 3/25/2023.
//
#ifndef MUSIC_UI_INIT_H
#define MUSIC_UI_INIT_H
#include <gtk/gtk.h>
#include "intro.h"
#include "src/components/main_menu.h"

GtkWidget *window,
        *main_box,
        *start_screen_vbox,
        *start_screen_button,
        *start_screen_label,
        *main_menu_vbox,
        *main_menu_discover_label,
        *main_menu_follow_label,
        *main_music_my_music_label,
        *main_menu_upload_label;

int ui_init(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    // Tạo cửa sổ ứng dụng
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Mystic Melody");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    // Tạo hộp main đựng các hộp khác
    main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), main_box);

    // Tạo các widgets trong từng hộp
    start_screen_init();
    main_menu_init();

    // Kết thúc chương trình khi người dùng đóng cửa sổ
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Hiển thị cửa sổ và các widgets bên trong
    gtk_widget_show_all(window);

    // Ẩn các widgets của box không hoạt động
    gtk_widget_set_visible(main_menu_vbox, 0);

    // Chạy vòng lặp chính của GTK
    gtk_main();

    return 0;
}

/* Work in progress
void load_css(GtkCssProvider *provider)
{
    GFile *css_f;
    css_f = g_file_new_for_path("style.css");
    provider = gtk_css_provider_new();
    gtk_css_provider_load_from_file(provider, css_f, NULL);
}
*/

#endif //MUSIC_UI_INIT_H
