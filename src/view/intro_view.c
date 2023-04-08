#include "intro_view.h"
#include <stdio.h>
#include "src/constant.h"
#include "src/view/signin_view.h"

void intro_show()
{
    // Tạo một cửa sổ mới
    GtkWidget *intro_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    //đặt các thuộc tính
    gtk_widget_set_size_request(intro_window, 500, 500);
    gtk_window_set_decorated(GTK_WINDOW(intro_window), FALSE);

    GdkRGBA color;
    gdk_rgba_parse(&color, "#3c3f41");
    gtk_widget_override_background_color(intro_window, GTK_STATE_FLAG_NORMAL, &color);



    gtk_window_set_position(GTK_WINDOW(intro_window), GTK_WIN_POS_CENTER_ALWAYS);
    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("D:/music/assets/logo.png", NULL);

    // Tạo GtkImage để hiển thị ảnh
    GtkWidget *image = gtk_image_new_from_pixbuf(pixbuf);

    // Thêm GtkImage vào window
    gtk_container_add(GTK_CONTAINER(intro_window), image);

    //Bo góc window
    GtkCssProvider *css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(css_provider, "window { border-radius: 10px; }", -1, NULL);
    GtkStyleContext *context = gtk_widget_get_style_context(GTK_WIDGET(intro_window));
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Hiển thị cửa sổ intro
    gtk_widget_show_all(intro_window);

    //chuyển qua window sign in và end window hiện tại
    g_timeout_add_seconds(2, (GSourceFunc)gtk_widget_destroy, intro_window);
    g_timeout_add_seconds(2, (GSourceFunc)sign_in_show, intro_window);

    // Bắt đầu vòng lặp sự kiện GTK
    gtk_main();
}
