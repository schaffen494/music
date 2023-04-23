//
// Created by ADMIN on 4/16/2023.
//

#include "menu.h"
#include "src/view/main_board_view.h"
#include "src/control/main_board_control.h"

void on_draw_menu(GtkWidget *widget, cairo_t *cr, gpointer user_data) {

    // Chỉnh màu cho background của hcn
    cairo_set_source_rgb(cr, 41/255.0, 40/255.0, 40/255.0); // fill color

    // Bắt đầu vẽ hcn
    cairo_rectangle(cr, 0, 0, 300, 680);
    cairo_fill_preserve(cr); // fill the rectangle
    cairo_stroke(cr); // draw the border
}

void load_menu_css()
{
    //Load file css
    GtkCssProvider *provider = gtk_css_provider_new();
    GtkStyleContext *explore_context,
            *playlist_context,
            *my_music_context,
            *upload_context,
            *add_playlist_context;
    GError *error = NULL;

    gtk_css_provider_load_from_path(provider, "src\\view\\properties\\menu.css", &error);
    if (error)
    {
        g_warning ("%s", error->message);
        g_clear_error (&error);
    }

    explore_context = gtk_widget_get_style_context(explorer_button);
    my_music_context = gtk_widget_get_style_context(my_music_button);
    playlist_context  = gtk_widget_get_style_context(playlist_button);
    add_playlist_context = gtk_widget_get_style_context(add_playlist_button);
    upload_context = gtk_widget_get_style_context(add_song_button);

    gtk_style_context_add_provider(explore_context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    gtk_style_context_add_provider(my_music_context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    gtk_style_context_add_provider(upload_context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    gtk_style_context_add_provider(add_playlist_context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    gtk_style_context_add_provider(playlist_context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
}

void set_menu_properties()
{
    // Tạo một hình chữ nhật để chứa toàn bộ Widget
    rect_area = gtk_drawing_area_new();
    // Set size và vị trí cho hình chữ nhật
    gtk_widget_set_size_request(rect_area,300 , 680);
    gtk_fixed_put(GTK_FIXED(main_board_fixed), rect_area, 0, 0);
    // bắt đầu vẽ hình chữ nhật
    g_signal_connect(rect_area, "draw", G_CALLBACK(on_draw_menu), NULL);

    // Khởi tạo nút Explore
    explorer_button = gtk_button_new_with_label("Explore");
    gtk_fixed_put(GTK_FIXED(main_board_fixed), explorer_button, 0, 170);
    gtk_widget_set_size_request(explorer_button, 300, 50);
    gtk_button_set_relief(GTK_BUTTON(explorer_button), GTK_RELIEF_NONE);

    // Khởi tạo nút My Music
    my_music_button = gtk_button_new_with_label("My music");
    gtk_fixed_put(GTK_FIXED(main_board_fixed), my_music_button, 0, 215);
    gtk_widget_set_size_request(my_music_button, 300, 50);
    gtk_button_set_relief(GTK_BUTTON(my_music_button), GTK_RELIEF_NONE);

    // Khởi tạo nút Playlist
    playlist_button = gtk_button_new_with_label("Playlist");
    gtk_fixed_put(GTK_FIXED(main_board_fixed), playlist_button, 0, 260);
    gtk_widget_set_size_request(playlist_button, 300, 50);
    gtk_button_set_relief(GTK_BUTTON(playlist_button), GTK_RELIEF_NONE);

    // Khởi tạo nút upload
    add_song_button = gtk_button_new_with_label("Upload");
    gtk_fixed_put(GTK_FIXED(main_board_fixed), add_song_button, 0, 580);
    gtk_widget_set_size_request(add_song_button, 300, 50);
    gtk_button_set_relief(GTK_BUTTON(add_song_button), GTK_RELIEF_NONE);

    // Khởi tạo nút Playlist
    add_playlist_button = gtk_button_new_with_label("Add Playlist");
    gtk_fixed_put(GTK_FIXED(main_board_fixed), add_playlist_button, 0, 630);
    gtk_widget_set_size_request(add_playlist_button, 300, 50);
    gtk_button_set_relief(GTK_BUTTON(add_playlist_button), GTK_RELIEF_NONE);

    // Add event clicked cho từng nút
    g_signal_connect(explorer_button, "clicked", G_CALLBACK(tab_explorer_click), NULL);
    g_signal_connect(my_music_button, "clicked", G_CALLBACK(tab_my_music_click), NULL);
    g_signal_connect(playlist_button, "clicked", G_CALLBACK(tab_playlist_click), NULL);
    g_signal_connect(add_song_button, "clicked", G_CALLBACK(upload), NULL);
    g_signal_connect(add_playlist_button, "clicked", G_CALLBACK(add_playlist), NULL);

    // Khởi tạo Logo của app ở đỉnh của selection menu
    header_logo = gtk_image_new_from_file("assets/header_logo.png");
    gtk_fixed_put(GTK_FIXED(main_board_fixed), header_logo, 20, 0);

    // Thêm các icon của từng mục
    explore_icon = gtk_image_new_from_file("assets/explore_icon.png");
    gtk_fixed_put(GTK_FIXED(main_board_fixed), explore_icon, 65, 184);
    my_music_icon = gtk_image_new_from_file("assets/my_music_icon.png");
    gtk_fixed_put(GTK_FIXED(main_board_fixed), my_music_icon, 65, 229);
    upload_icon = gtk_image_new_from_file("assets/upload_icon.png");
    gtk_fixed_put(GTK_FIXED(main_board_fixed), upload_icon, 65, 274);

}

void menu_show()
{
    set_menu_properties();

    load_menu_css();
}
