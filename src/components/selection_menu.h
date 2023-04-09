//
// Created by Nhat on 4/5/2023.
//

#ifndef MUSIC_SELECTION_MENU_H
#define MUSIC_SELECTION_MENU_H

#include <gtk/gtk.h>
void on_draw_menu(GtkWidget *widget, cairo_t *cr, gpointer user_data);
// Create all widgets for the Selection Menu
void create_selection_menu(GtkWidget *fixed) {

    // Tạo một hình chữ nhật để chứa toàn bộ Widget
    GtkWidget *rect_area = gtk_drawing_area_new();
    // Set size và vị trí cho hình chữ nhật
    gtk_widget_set_size_request(rect_area,300 , 640);
    gtk_fixed_put(GTK_FIXED(fixed), rect_area, 0, 0);
    // bắt đầu vẽ hình chữ nhật
    g_signal_connect(rect_area, "draw", G_CALLBACK(on_draw_menu), NULL);

    // Khởi tạo nút chạy nhạc
    GtkWidget *explore = gtk_button_new_with_label("Explore");
    gtk_fixed_put(GTK_FIXED(fixed), explore, 0, 150);
    gtk_widget_set_size_request(explore, 300, 50);
    gtk_button_set_relief(GTK_BUTTON(explore), GTK_RELIEF_NONE);

    // Khởi tạo nút dừng nhạc
    GtkWidget *my_music = gtk_button_new_with_label("My music");
    gtk_fixed_put(GTK_FIXED(fixed), my_music, 0, 195);
    gtk_widget_set_size_request(my_music, 300, 50);
    gtk_button_set_relief(GTK_BUTTON(my_music), GTK_RELIEF_NONE);


    // Khởi tạo nút quay lại bài hát trước đó
    GtkWidget *upload = gtk_button_new_with_label("Upload");
    gtk_fixed_put(GTK_FIXED(fixed), upload, 0, 240);
    gtk_widget_set_size_request(upload, 300, 50);
    gtk_button_set_relief(GTK_BUTTON(upload), GTK_RELIEF_NONE);

    // Thêm các buttons vào một hình chữ nhật
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(box), explore, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), my_music, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), upload, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(fixed), box);

    // Khởi tạo widget cho việc chứa ảnh của bài hát
    GtkWidget *image = gtk_image_new_from_file("assets/header_logo.png");
    gtk_widget_set_name(image, "song-poster");
    gtk_fixed_put(GTK_FIXED(fixed), image, 20, 0);


    //Load file css
    GtkCssProvider *provider = gtk_css_provider_new();
    GdkDisplay *display = gdk_display_get_default ();
    GdkScreen *screen = gdk_display_get_default_screen (display);
    GError *error = NULL;

    gtk_css_provider_load_from_path(provider, "D:\\mystic_melody\\src\\properties\\style.css", &error);
    if (error)
    {
        g_warning ("%s", error->message);
        g_clear_error (&error);
    }
    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

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