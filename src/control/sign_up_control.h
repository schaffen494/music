//
// Created by ADMIN on 4/17/2023.
//

#ifndef C_SIGN_UP_CONTROL_H
#define C_SIGN_UP_CONTROL_H
#include <gtk/gtk.h>
extern GtkWidget *sign_up_win,*username_entry_signup,*password_entry_signup;
int sign_up_button_click(GtkWidget *widget, gpointer data);
void sign_up_exit_button_click();
#endif //C_SIGN_UP_CONTROL_H
