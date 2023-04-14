//
// Created by ADMIN on 4/13/2023.
//

#include "signin_view.h"
#include "src/models/users.h"
#include "src/view/main_view/signup_view.h"
#include "src/view/main_view/mainboard_view.h"
GtkWidget *username_entry_login,*label_username,*image_logo,*label_password,*button_login,*button_register;
GtkWidget *password_entry_login;
GtkWidget *sign_in_window;
GtkWidget* fixed1;
GtkCssProvider *provider_sign_in;
GdkDisplay *display;
GdkScreen *screen;
GError *error;
gboolean authenticate_user(const char *username, const char *password)
{

    if (check_sign_in(username,password) == LOGIN_OK) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int login_clicked(GtkWidget *widget, gpointer data) {
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
        g_timeout_add_seconds(0, (GSourceFunc)main_board_show, sign_in_window);
        gtk_entry_set_text(username_entry_login, "");
        gtk_entry_set_text(password_entry_login, "");
        return 1;
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
            gtk_entry_set_text(username_entry_login, "");
            gtk_entry_set_text(password_entry_login, "");
            return 1;
        }

    }

    /* Hủy hộp thoại */
    gtk_widget_destroy(dialog);
}

int signup_clicked(GtkWidget *widget, gpointer data)
{
    g_timeout_add_seconds(0, (GSourceFunc)gtk_widget_hide, sign_in_window);
    g_timeout_add_seconds(0, (GSourceFunc)sign_up_show, sign_in_window);
}

void sign_in_show(){

    // init sign_in_window
    sign_in_window= gtk_window_new(GTK_WINDOW_TOPLEVEL);


    //set attribute
    gtk_window_set_decorated(GTK_WINDOW(sign_in_window), FALSE);
    gtk_window_set_title(GTK_WINDOW(sign_in_window), "Login");
    gtk_window_set_default_size(GTK_WINDOW(sign_in_window), 500,700);
    gtk_window_set_position(GTK_WINDOW(sign_in_window), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(sign_in_window), FALSE);
    gtk_container_set_border_width(GTK_CONTAINER(sign_in_window), 10);


    // Tạo fixed container để set vị trí của các Widget
    fixed1 = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(sign_in_window), fixed1);


    // Tạo logo
    image_logo = gtk_image_new_from_file("assets/sign_in_logo.png");
    gtk_fixed_put(GTK_FIXED(fixed1), image_logo, 165, 20);


    // Tạo label và entry cho tên đăng nhập
    label_username = gtk_label_new("Username:");
    username_entry_login= gtk_entry_new();
    gtk_widget_set_size_request(username_entry_login, 400, 30);
    gtk_fixed_put(GTK_FIXED(fixed1), label_username, 40, 222);
    gtk_fixed_put(GTK_FIXED(fixed1), username_entry_login, 40, 250);


    // Tạo label và entry cho mật khẩu
    label_password = gtk_label_new("Password:");
    password_entry_login = gtk_entry_new();
    gtk_widget_set_size_request(password_entry_login, 400, 30);
    gtk_entry_set_visibility(GTK_ENTRY(password_entry_login), FALSE);
    gtk_fixed_put(GTK_FIXED(fixed1), label_password, 40, 320);
    gtk_fixed_put(GTK_FIXED(fixed1), password_entry_login, 40, 350);


    // Tạo button đăng nhập
    button_login = gtk_button_new_with_label("Login");
    g_signal_connect(button_login, "clicked", G_CALLBACK(login_clicked), NULL);

    // Tạo button đăng ký
    GtkWidget *button_register = gtk_button_new_with_label("Register");
    g_signal_connect(button_register, "clicked", G_CALLBACK(signup_clicked), NULL);
    gtk_widget_set_size_request(button_login, 400, 30);
    gtk_widget_set_size_request(button_register, 400, 30);
    gtk_fixed_put(GTK_FIXED(fixed1), button_login, 40, 400);
    gtk_fixed_put(GTK_FIXED(fixed1), button_register, 40, 450);



    //set name for intro_window
    gtk_widget_set_name(sign_in_window,"sign-in-window");
    gtk_widget_set_name(label_username, "label_username");
    gtk_widget_set_name(username_entry_login, "username_entry_login");
    gtk_widget_set_name(label_password, "label_password");
    gtk_widget_set_name(password_entry_login, "password_entry_login");
    gtk_widget_set_name(button_login, "button_login");
    gtk_widget_set_name(button_register, "button_register");

    //apply css for intro_window
    GtkCssProvider *provider = gtk_css_provider_new ();
    GFile *file = g_file_new_for_path ("src/view/properties/sign_in.css");
    GError *error = NULL;
    gtk_css_provider_load_from_file (provider, file, &error);
    if (error != NULL) {
        g_warning ("Error loading CSS file: %s", error->message);
        g_clear_error (&error);
    }
    GtkStyleContext *context = gtk_widget_get_style_context (sign_in_window);
    GtkStyleContext *context1 = gtk_widget_get_style_context (label_username);
    GtkStyleContext *context2 = gtk_widget_get_style_context (username_entry_login);
    GtkStyleContext *context3 = gtk_widget_get_style_context (label_password);
    GtkStyleContext *context4 = gtk_widget_get_style_context (password_entry_login);
    GtkStyleContext *context5 = gtk_widget_get_style_context (button_login);
    GtkStyleContext *context6 = gtk_widget_get_style_context (button_register);
    gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER (provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_provider (context1, GTK_STYLE_PROVIDER (provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_provider (context2, GTK_STYLE_PROVIDER (provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_provider (context3, GTK_STYLE_PROVIDER (provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_provider (context4, GTK_STYLE_PROVIDER (provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_provider (context5, GTK_STYLE_PROVIDER (provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_add_provider (context6, GTK_STYLE_PROVIDER (provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    // show window
    gtk_widget_show_all(sign_in_window);

    // event to close window
    g_signal_connect(G_OBJECT(sign_in_window), "destroy", G_CALLBACK(exit), NULL);

    gtk_main();

}