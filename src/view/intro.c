#include <gtk/gtk.h>
#include "src/constant.h"
#include "src/view/sign_in.h"
#include <unistd.h>


void intro_show() {
    // Tạo một cửa sổ mới
    GtkWidget *intro_wid = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request(intro_wid, 1500, 800);
    gtk_window_set_decorated(GTK_WINDOW(intro_wid), FALSE);

    // Đặt tiêu đề cho cửa sổ
    gtk_window_set_title(GTK_WINDOW(intro_wid), "My Window");
    GdkRGBA color;
    gdk_rgba_parse(&color, "#0a0931");
    gtk_widget_override_background_color(intro_wid, GTK_STATE_FLAG_NORMAL, &color);
    // Lấy kích thước màn hình
    GdkScreen *screen = gdk_screen_get_default();


    gtk_window_set_position(GTK_WINDOW(intro_wid), GTK_WIN_POS_CENTER_ALWAYS);

    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("D:/music/assets/logo.png", NULL);

    // Tạo GtkImage để hiển thị ảnh
    GtkWidget *image = gtk_image_new_from_pixbuf(pixbuf);

    // Thêm GtkImage vào window
    gtk_container_add(GTK_CONTAINER(intro_wid), image);

    GtkCssProvider *css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(css_provider, "window { border-radius: 10px; }", -1, NULL);
    GtkStyleContext *context = gtk_widget_get_style_context(GTK_WIDGET(intro_wid));
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    // Hiển thị cửa sổ3
    gtk_widget_show_all(intro_wid);

    g_timeout_add_seconds(2, (GSourceFunc)gtk_widget_destroy, intro_wid);
    g_timeout_add_seconds(2, (GSourceFunc)sign_in, intro_wid);

    // Bắt đầu vòng lặp sự kiện GTK
    gtk_main();
}
