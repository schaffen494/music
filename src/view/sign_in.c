//
// Created by ADMIN on 3/26/2023.
//
#include "sign_in.h"
GtkWidget *username_entry;
GtkWidget *password_entry;
gboolean authenticate_user(const char *username, const char *password) {
    if (strcmp(username, "lap") == 0 && strcmp(password, "123") == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void login_clicked(GtkWidget *widget, gpointer data) {
    const char *username = gtk_entry_get_text(GTK_ENTRY(username_entry));
    const char *password = gtk_entry_get_text(GTK_ENTRY(password_entry));

    if (authenticate_user(username, password)) {
        g_print("Successful %s\n", username);
    } else {
        g_print("Fail\n");
    }
}
void sign_in()
{
    // Tạo cửa sổ đăng nhập
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Đăng nhập");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 300, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Tạo box chứa các widget
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), box);

    // Tạo ô nhập liệu tên đăng nhập
    GtkWidget *username_label = gtk_label_new("Tên đăng nhập:");
    gtk_box_pack_start(GTK_BOX(box), username_label, FALSE, FALSE, 0);

    username_entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(box), username_entry, FALSE, FALSE, 0);

    // Tạo ô nhập liệu mật khẩu
    GtkWidget *password_label = gtk_label_new("Mật khẩu:");
    gtk_box_pack_start(GTK_BOX(box), password_label, FALSE, FALSE, 0);

    password_entry = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(password_entry), FALSE);
    gtk_box_pack_start(GTK_BOX(box), password_entry, FALSE, FALSE, 0);

    // Tạo nút đăng nhập
    GtkWidget *login_button = gtk_button_new_with_label("Đăng nhập");
    g_signal_connect(login_button, "clicked", G_CALLBACK(login_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(box), login_button, FALSE, FALSE, 0);

    // Hiển thị cửa sổ đăng nhập
    gtk_widget_show_all(window);

    // Bắt đầu vòng lặp sự kiện GTK
    gtk_main();
}
