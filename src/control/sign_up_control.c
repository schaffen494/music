//
// Created by ADMIN on 4/17/2023.
//

#include "sign_up_control.h"
#include "src/view/sign_up_view.h"
#include "src/models/users.h"
#include "src/view/sign_in_view.h"

void sign_up_exit_button_click() {
    exit(0);
}

gboolean authenticate_user_sign_up(const char *username, const char *password) {

    if (add_account(username, password) == SIGNUP_OK) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int sign_up_button_click(GtkWidget *widget, gpointer data) {
    const char *username = gtk_entry_get_text(GTK_ENTRY(username_entry_signup));
    const char *password = gtk_entry_get_text(GTK_ENTRY(password_entry_signup));
    GtkWidget *dialog;
    if (strlen(username) == 0 || strlen(password) == 0) {
        dialog = gtk_message_dialog_new(NULL,
                                        GTK_DIALOG_MODAL,
                                        GTK_MESSAGE_INFO,
                                        GTK_BUTTONS_OK,
                                        "Please enter username & password!");
        gtk_window_set_decorated(GTK_WINDOW(dialog), FALSE);
        gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
        gtk_dialog_run(GTK_DIALOG(dialog));
        g_timeout_add_seconds(0, (GSourceFunc)gtk_widget_destroy, dialog);
        gtk_entry_set_text(username_entry_signup, "");
        gtk_entry_set_text(password_entry_signup, "");
        return 0;
    }
    else
    {
        if (authenticate_user_sign_up(username, password)) {
            dialog = gtk_message_dialog_new(NULL,
                                            GTK_DIALOG_MODAL,
                                            GTK_MESSAGE_INFO,
                                            GTK_BUTTONS_OK,
                                            "Đăng ký thành công!");
            gtk_window_set_decorated(GTK_WINDOW(dialog), FALSE);
            gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
            gtk_dialog_run(GTK_DIALOG(dialog));
            g_timeout_add_seconds(0, (GSourceFunc) gtk_widget_hide, sign_up_win);
            g_timeout_add_seconds(0, (GSourceFunc) sign_in_show, sign_up_win);

        } else {
            dialog = gtk_message_dialog_new(NULL,
                                            GTK_DIALOG_MODAL,
                                            GTK_MESSAGE_ERROR,
                                            GTK_BUTTONS_OK,
                                            "Đăng ký thất bại!");
            gtk_window_set_decorated(GTK_WINDOW(dialog), FALSE);
            gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
            gtk_dialog_run(GTK_DIALOG(dialog));
            g_timeout_add_seconds(0, (GSourceFunc) gtk_widget_destroy, dialog);
            gtk_entry_set_text(username_entry_signup, "");
            gtk_entry_set_text(password_entry_signup, "");
            return 0;
        }
    }

    /* Hủy hộp thoại */
    gtk_widget_destroy(dialog);
}
