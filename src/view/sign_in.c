#include "sign_in.h"
#include "src/db/connectData.h"
#include "src/view/main_board.h"
GtkWidget *username_entry;
GtkWidget *password_entry;
GtkWidget *sign_in_window;
int status_signin =0;
gboolean authenticate_user(const char *username, const char *password) {

    if (check_Signin(username,password) == LOGIN_OK) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int login_clicked(GtkWidget *widget, gpointer data) {
    const char *username = gtk_entry_get_text(GTK_ENTRY(username_entry));
    const char *password = gtk_entry_get_text(GTK_ENTRY(password_entry));
    GtkWidget *dialog;
    if (authenticate_user(username, password)) {
        dialog = gtk_message_dialog_new(NULL,
                                        GTK_DIALOG_MODAL,
                                        GTK_MESSAGE_INFO,
                                        GTK_BUTTONS_OK,
                                        "Đăng nhập thành công!");
        gtk_window_set_decorated(GTK_WINDOW(dialog), FALSE);
        gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
        gtk_dialog_run(GTK_DIALOG(dialog));
        g_timeout_add_seconds(0, (GSourceFunc)gtk_widget_hide, sign_in_window);
        g_timeout_add_seconds(0, (GSourceFunc)main_board_show, sign_in_window);

    } else {
        dialog = gtk_message_dialog_new(NULL,
                                        GTK_DIALOG_MODAL,
                                        GTK_MESSAGE_ERROR,
                                        GTK_BUTTONS_OK,
                                        "Đăng nhập thất bại!");
        gtk_window_set_decorated(GTK_WINDOW(dialog), FALSE);
        gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
        gtk_dialog_run(GTK_DIALOG(dialog));
        g_timeout_add_seconds(0, (GSourceFunc)gtk_widget_destroy, dialog);
        gtk_entry_set_text(username_entry, "");
        gtk_entry_set_text(password_entry, "");
        return 1;
    }


    /* Hủy hộp thoại */
    gtk_widget_destroy(dialog);
}
void sign_in()
{
    // Tạo cửa sổ đăng nhập
    sign_in_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(sign_in_window), "Đăng nhập");
    gtk_container_set_border_width(GTK_CONTAINER(sign_in_window), 10);
    gtk_widget_set_size_request(sign_in_window, 1500, 800);
    g_signal_connect(sign_in_window, "destroy", G_CALLBACK(exit), NULL);

    // Tạo box chứa các widget
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(sign_in_window), box);

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

    gtk_window_set_position(GTK_WINDOW(sign_in_window), GTK_WIN_POS_CENTER_ALWAYS);
    // Hiển thị cửa sổ đăng nhập
    gtk_widget_show_all(sign_in_window);

    // Bắt đầu vòng lặp sự kiện GTK
    gtk_main();
}