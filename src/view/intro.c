#include <gtk/gtk.h>
#include "src/constant.h"
void intro_show() {
    // Tạo một cửa sổ mới
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_decorated(GTK_WINDOW(window), FALSE);
    // Đặt tiêu đề cho cửa sổ
    gtk_window_set_title(GTK_WINDOW(window), "My Window");
    GdkRGBA color;
    gdk_rgba_parse(&color, "#0a0931");
    gtk_widget_override_background_color(window, GTK_STATE_FLAG_NORMAL, &color);
    // Lấy kích thước màn hình
    GdkScreen *screen = gdk_screen_get_default();
    gint width = gdk_screen_get_width(screen);
    gint height = gdk_screen_get_height(screen);

    // Đặt kích thước của cửa sổ là 1/3 chiều rộng và cao của màn hình
    gint window_width = width_app;
    gint window_height = height_app;
    gtk_window_set_default_size(GTK_WINDOW(window), window_width, window_height);

    // Đặt cửa sổ ở giữa màn hình
    gint x = (width - window_width) / 2;
    gint y = (height - window_height) / 2;
    gtk_window_move(GTK_WINDOW(window), x, y);

    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("D:/music/assets/logo.png", NULL);

    // Tạo GtkImage để hiển thị ảnh
    GtkWidget *image = gtk_image_new_from_pixbuf(pixbuf);

    // Thêm GtkImage vào window
    gtk_container_add(GTK_CONTAINER(window), image);

    // Hiển thị cửa sổ
    gtk_widget_show_all(window);

    // Bắt đầu vòng lặp sự kiện GTK
    gtk_main();
}
