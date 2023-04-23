//
// Created by ADMIN on 4/16/2023.
//

#ifndef C_SIGN_IN_CONTROL_H
#define C_SIGN_IN_CONTROL_H
#include <gtk/gtk.h>
extern char user_id[PATH_MAX];
extern GtkWidget *password_entry_login,*username_entry_login;

int sign_in_button_click(GtkWidget *widget, gpointer data);

void sign_in_exit_button_click();

void sign_in_sign_up_button_click();

#endif //C_SIGN_IN_CONTROL_H
