//
// Created by ADMIN on 4/12/2023.
//

#include "searchBar.h"

#include <gtk/gtk.h>


int searchBar(GtkWidget *fixed) {

    // Tạo entry widget
    GtkWidget *entry = gtk_entry_new();
    gtk_widget_set_size_request(entry, 463, 37);
    gtk_fixed_put(GTK_FIXED(fixed), entry, 410, 30);

    // Khởi tạo nút bỏ qua bài hát hiện tại
    GtkWidget *search = gtk_button_new_with_label("");
    gtk_fixed_put(GTK_FIXED(fixed), search, 820, 30);
    gtk_button_set_relief(GTK_BUTTON(search), GTK_RELIEF_NONE);
    GdkPixbuf *pixbuf_skip = gdk_pixbuf_new_from_file("assets/search_icon.svg", NULL);
    GtkImage *image_skip = gtk_image_new_from_pixbuf(pixbuf_skip);
    gtk_button_set_image(GTK_BUTTON(search), GTK_WIDGET(image_skip));
    gtk_widget_show(image_skip);

    // Khởi tạo nút log out
    GtkWidget *logout = gtk_button_new_with_label("");
    gtk_fixed_put(GTK_FIXED(fixed), logout, 1220, 30);
    gtk_button_set_relief(GTK_BUTTON(logout), GTK_RELIEF_NONE);
    GdkPixbuf *pixbuf_skip1 = gdk_pixbuf_new_from_file("assets/logout.svg", NULL);
    GtkImage *image_skip1 = gtk_image_new_from_pixbuf(pixbuf_skip1);
    gtk_button_set_image(GTK_BUTTON(logout), GTK_WIDGET(image_skip1));
    gtk_widget_show(image_skip1);

    return 0;
}