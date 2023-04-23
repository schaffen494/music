//
// Created by ADMIN on 4/16/2023.
//

#include "search_bar.h"
#include "src/view/main_board_view.h"
#include "src/control/main_board_control.h"
GtkWidget *entry_search_bar;

void  search_bar_show()
{
    // Tạo entry widget
    entry_search_bar = gtk_entry_new();
    gtk_widget_set_size_request(entry_search_bar, 463, 37);
    gtk_fixed_put(GTK_FIXED(main_board_fixed), entry_search_bar, 410, 30);


    GtkWidget *search = gtk_button_new_with_label("");
    gtk_fixed_put(GTK_FIXED(main_board_fixed), search, 820, 30);
    gtk_button_set_relief(GTK_BUTTON(search), GTK_RELIEF_NONE);
    GdkPixbuf *pixbuf_skip = gdk_pixbuf_new_from_file("assets/search_icon.svg", NULL);
    GtkImage *image_skip = gtk_image_new_from_pixbuf(pixbuf_skip);
    gtk_button_set_image(GTK_BUTTON(search), GTK_WIDGET(image_skip));
    gtk_widget_show(image_skip);

    g_signal_connect(search, "clicked", G_CALLBACK(search_song), NULL);

    // Khởi tạo nút log out
    GtkWidget *logout = gtk_button_new_with_label("");
    gtk_fixed_put(GTK_FIXED(main_board_fixed), logout, 1360, 10);
    gtk_button_set_relief(GTK_BUTTON(logout), GTK_RELIEF_NONE);
    GdkPixbuf *pixbuf_skip1 = gdk_pixbuf_new_from_file("assets/logout.svg", NULL);
    GtkImage *image_skip1 = gtk_image_new_from_pixbuf(pixbuf_skip1);
    gtk_button_set_image(GTK_BUTTON(logout), GTK_WIDGET(image_skip1));
    gtk_widget_show(image_skip1);

    GtkWidget *exit_button = gtk_button_new_with_label("");
    gtk_fixed_put(GTK_FIXED(main_board_fixed), exit_button, 1420, 0);
    gtk_button_set_relief(GTK_BUTTON(logout), GTK_RELIEF_NONE);
    GdkPixbuf *pixbuf_skip2 = gdk_pixbuf_new_from_file("assets/exit_logo.svg", NULL);
    GtkImage *image_skip2 = gtk_image_new_from_pixbuf(pixbuf_skip2);
    gtk_button_set_image(GTK_BUTTON(exit_button), GTK_WIDGET(image_skip2));
    gtk_widget_show(image_skip2);
    gtk_button_set_relief(GTK_BUTTON(exit_button), GTK_RELIEF_NONE);
    g_signal_connect(logout, "clicked", G_CALLBACK(logout_click), NULL);
    g_signal_connect(exit_button, "clicked", G_CALLBACK(exit), NULL);
}