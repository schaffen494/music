//
// Created by ADMIN on 3/26/2023.
//
#include "sign_up.h"
#include "src/view/main_board.h"
#include "src/db/connectData.h"

GtkWidget *username_entry1;
GtkWidget *password_entry1;
GtkWidget *sign_up_window;

gboolean authenticate_user1(const char *username, const char *password) {

    if (add_account(username,password) == SIGNUP_OK) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int signup_clicked(GtkWidget *widget, gpointer data) {
    const char *username = gtk_entry_get_text(GTK_ENTRY(username_entry1));
    const char *password = gtk_entry_get_text(GTK_ENTRY(password_entry1));
    GtkWidget *dialog;
    if (authenticate_user1(username, password)==TRUE) {
        dialog = gtk_message_dialog_new(NULL,
                                        GTK_DIALOG_MODAL,
                                        GTK_MESSAGE_INFO,
                                        GTK_BUTTONS_OK,
                                        "Đăng ký thành công!");
        gtk_window_set_decorated(GTK_WINDOW(dialog), FALSE);
        gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
        gtk_dialog_run(GTK_DIALOG(dialog));
        g_timeout_add_seconds(0, (GSourceFunc)gtk_widget_hide, sign_up_window);
        g_timeout_add_seconds(0, (GSourceFunc)main_board_show, sign_up_window);

    } else {
        dialog = gtk_message_dialog_new(NULL,
                                        GTK_DIALOG_MODAL,
                                        GTK_MESSAGE_ERROR,
                                        GTK_BUTTONS_OK,
                                        "Đăng ký thất bại!");
        gtk_window_set_decorated(GTK_WINDOW(dialog), FALSE);
        gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
        gtk_dialog_run(GTK_DIALOG(dialog));
        g_timeout_add_seconds(0, (GSourceFunc)gtk_widget_destroy, dialog);
        gtk_entry_set_text(username_entry1, "");
        gtk_entry_set_text(password_entry1, "");
        return 1;
    }


    /* Hủy hộp thoại */
    gtk_widget_destroy(dialog);
}
void signup_show()
{
    // Tạo cửa sổ đăng nhập
    sign_up_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(sign_up_window), "Đăng nhập");
    gtk_container_set_border_width(GTK_CONTAINER(sign_up_window), 10);
    gtk_widget_set_size_request(sign_up_window, 1500, 800);
    g_signal_connect(sign_up_window, "destroy", G_CALLBACK(exit), NULL);

    // Tạo box chứa các widget
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(sign_up_window), box);

    // Tạo ô nhập liệu tên đăng nhập
    GtkWidget *username_label = gtk_label_new("Tên đăng nhập:");
    gtk_box_pack_start(GTK_BOX(box), username_label, FALSE, FALSE, 0);

    username_entry1 = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(box), username_entry1, FALSE, FALSE, 0);

    // Tạo ô nhập liệu mật khẩu
    GtkWidget *password_label = gtk_label_new("Mật khẩu:");
    gtk_box_pack_start(GTK_BOX(box), password_label, FALSE, FALSE, 0);

    password_entry1 = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(password_entry1), FALSE);
    gtk_box_pack_start(GTK_BOX(box), password_entry1, FALSE, FALSE, 0);

    // Tạo nút đăng nhập
    GtkWidget *login_button = gtk_button_new_with_label("Đăng nhập");
    g_signal_connect(login_button, "clicked", G_CALLBACK(signup_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(box), login_button, FALSE, FALSE, 0);

    gtk_window_set_position(GTK_WINDOW(sign_up_window), GTK_WIN_POS_CENTER_ALWAYS);
    // Hiển thị cửa sổ đăng nhập
    gtk_widget_show_all(sign_up_window);

    // Bắt đầu vòng lặp sự kiện GTK
    gtk_main();
}