//
// Created by Nhat on 4/5/2023.
//

#ifndef MUSIC_SELECTION_MENU_H
#define MUSIC_SELECTION_MENU_H

#include <gtk/gtk.h>
void on_draw_menu(GtkWidget *widget, cairo_t *cr, gpointer user_data);

void create_selection_menu(GtkWidget *fixed) {

    // Tạo một hình chữ nhật để chứa toàn bộ Widget
    GtkWidget *rect_area = gtk_drawing_area_new();
    // Set size và vị trí cho hình chữ nhật
    gtk_widget_set_size_request(rect_area,300 , 663);
    gtk_fixed_put(GTK_FIXED(fixed), rect_area, 0, 0);
    // bắt đầu vẽ hình chữ nhật
    g_signal_connect(rect_area, "draw", G_CALLBACK(on_draw_menu), NULL);

    // Khởi tạo nút Expore
    GtkWidget *explore = gtk_button_new_with_label("Explore");
    gtk_fixed_put(GTK_FIXED(fixed), explore, 0, 170);
    gtk_widget_set_size_request(explore, 300, 50);
    gtk_button_set_relief(GTK_BUTTON(explore), GTK_RELIEF_NONE);

    // Khởi tạo nút My Music
    GtkWidget *my_music = gtk_button_new_with_label("My music");
    gtk_fixed_put(GTK_FIXED(fixed), my_music, 0, 215);
    gtk_widget_set_size_request(my_music, 300, 50);
    gtk_button_set_relief(GTK_BUTTON(my_music), GTK_RELIEF_NONE);

    // Khởi tạo nút Upload
    GtkWidget *upload = gtk_button_new_with_label("Upload");
    gtk_fixed_put(GTK_FIXED(fixed), upload, 0, 260);
    gtk_widget_set_size_request(upload, 300, 50);
    gtk_button_set_relief(GTK_BUTTON(upload), GTK_RELIEF_NONE);

    // Thêm các buttons vào một hình chữ nhật
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(box), explore, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), my_music, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), upload, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(fixed), box);

    // Khởi tạo Logo của app ở đỉnh của selection menu
    GtkWidget *logo = gtk_image_new_from_file("assets/header_logo.png");
    gtk_fixed_put(GTK_FIXED(fixed), logo, 50, 0);

    // Khởi tạo các icon của từng mục
    GtkWidget *explore_icon = gtk_image_new_from_file("assets/explore_icon.png");
    gtk_fixed_put(GTK_FIXED(fixed), explore_icon, 65, 184);
    GtkWidget *my_music_icon = gtk_image_new_from_file("assets/my_music_icon.png");
    gtk_fixed_put(GTK_FIXED(fixed), my_music_icon, 65, 229);
    GtkWidget *upload_icon = gtk_image_new_from_file("assets/upload_icon.png");
    gtk_fixed_put(GTK_FIXED(fixed), upload_icon, 65, 274);

    //Load file css
    GtkCssProvider *provider = gtk_css_provider_new();
    GtkStyleContext *explore_context,
            *my_music_context,
            *upload_context;
    GError *error = NULL;

    gtk_css_provider_load_from_path(provider, "src\\properties\\selection_menu.css", &error);
    if (error)
    {
        g_warning ("%s", error->message);
        g_clear_error (&error);
    }

    explore_context = gtk_widget_get_style_context(explore);
    my_music_context = gtk_widget_get_style_context(my_music);
    upload_context = gtk_widget_get_style_context(upload);

    gtk_style_context_add_provider(explore_context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    gtk_style_context_add_provider(my_music_context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    gtk_style_context_add_provider(upload_context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
}

void on_draw_menu(GtkWidget *widget, cairo_t *cr, gpointer user_data) {

    // Chỉnh màu cho background của hcn
    cairo_set_source_rgb(cr, 41/255.0, 40/255.0, 40/255.0); // fill color

    // Bắt đầu vẽ hcn
    cairo_rectangle(cr, 0, 0, 300, 680);
    cairo_fill_preserve(cr); // fill the rectangle
    cairo_stroke(cr); // draw the border
}
#endif //MUSIC_SELECTION_MENU_H
