//
// Created by ADMIN on 4/16/2023.
//

#include "sign_in_control.h"
#include "src/view/sign_in_view.h"
#include "src/view/sign_up_view.h"
#include "src/models/users.h"
#include "src/view/main_board_view.h"

char user_id[PATH_MAX];
gboolean authenticate_user(const char username[], const char password[])
{

    if (check_sign_in(username,password) == LOGIN_OK) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int sign_in_button_click(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog;
    const char *username = gtk_entry_get_text(GTK_ENTRY(username_entry_login));
    const char *password = gtk_entry_get_text(GTK_ENTRY(password_entry_login));


    if( strlen(username)==0 || strlen(password)==0)
    {
        dialog = gtk_message_dialog_new(NULL,
                                        GTK_DIALOG_MODAL,
                                        GTK_MESSAGE_INFO,
                                        GTK_BUTTONS_OK,
                                        "Please enter username & password!");
        gtk_window_set_decorated(GTK_WINDOW(dialog), FALSE);
        gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
        gtk_dialog_run(GTK_DIALOG(dialog));
        g_timeout_add_seconds(0, (GSourceFunc)gtk_widget_destroy, dialog);
        gtk_entry_set_text(username_entry_login, "");
        gtk_entry_set_text(password_entry_login, "");
        return 0;
    }
    else
    {

        if (authenticate_user(username, password)) {
            dialog = gtk_message_dialog_new(NULL,
                                            GTK_DIALOG_MODAL,
                                            GTK_MESSAGE_INFO,
                                            GTK_BUTTONS_OK,
                                            "Đăng nhập thành công!");
            gtk_window_set_decorated(GTK_WINDOW(dialog), FALSE);
            gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
            gtk_dialog_run(GTK_DIALOG(dialog));
            strcpy(user_id,username);
            g_timeout_add_seconds(0, (GSourceFunc)gtk_widget_destroy, sign_in_win);
            g_timeout_add_seconds(0, (GSourceFunc)main_board_show, main_board_win);

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
            gtk_entry_set_text(username_entry_login, "");
            gtk_entry_set_text(password_entry_login, "");
            return 0;
        }

    }
    /* Hủy hộp thoại */
    gtk_widget_destroy(dialog);
}

void sign_in_exit_button_click()
{
    exit(0);
}
void sign_in_sign_up_button_click()
{
    g_timeout_add_seconds(0, (GSourceFunc)gtk_widget_destroy, sign_in_win);
    g_timeout_add_seconds(0, (GSourceFunc)sign_up_show, sign_in_win);
}