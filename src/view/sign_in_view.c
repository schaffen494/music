//
// Created by ADMIN on 4/16/2023.
//

#include "sign_in_view.h"
#include "src/config/database_config.h"
#include "src/control/sign_in_control.h"

GtkWidget *sign_in_win,
*username_entry_login,
*label_username_sign_in,
*image_logo_sign_in,
*label_password_sign_in,
*button_login_sign_in,
*button_register_sign_in,
*button_exit_sign_in;
GtkWidget *password_entry_login;
GtkWidget *sign_in_fixed;


void load_css_sign_in()
{
    //set name for intro_window
    gtk_widget_set_name(sign_in_win,"sign-in-window");
    gtk_widget_set_name(label_username_sign_in, "label_username");
    gtk_widget_set_name(username_entry_login, "username_entry_login");
    gtk_widget_set_name(label_password_sign_in, "label_password");
    gtk_widget_set_name(password_entry_login, "password_entry_login");


    // Tạo CSS provider từ file
    GtkCssProvider *css_sign_in;
    GdkDisplay *display;
    GdkScreen *screen;

    css_sign_in = gtk_css_provider_new();
    get_path("src\\view\\properties\\sign_in.css");
    gtk_css_provider_load_from_path(css_sign_in,path_file , NULL);

    // Lấy display và screen
    display = gdk_display_get_default();
    screen = gdk_display_get_default_screen(display);

    // Áp dụng CSS cho màn hình hiện tại
    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(css_sign_in), GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Lấy GtkStyleContext của cửa sổ
    GtkStyleContext *context = gtk_widget_get_style_context(sign_in_win);

    // Áp dụng CSS cho cửa sổ
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(css_sign_in), GTK_STYLE_PROVIDER_PRIORITY_USER);


}
void set_sign_in_properties()
{
    //set attribute
    gtk_window_set_decorated(GTK_WINDOW(sign_in_win), FALSE);
    gtk_window_set_title(GTK_WINDOW(sign_in_win), "Login");
    gtk_window_set_default_size(GTK_WINDOW(sign_in_win), 500,700);
    gtk_window_set_position(GTK_WINDOW(sign_in_win), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(sign_in_win), FALSE);
    gtk_container_set_border_width(GTK_CONTAINER(sign_in_win), 10);


    // Tạo fixed container để set vị trí của các Widget
    sign_in_fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(sign_in_win), sign_in_fixed);


    // Tạo logo
    image_logo_sign_in = gtk_image_new_from_file("assets/sign_in_logo.png");
    gtk_fixed_put(GTK_FIXED(sign_in_fixed), image_logo_sign_in, 165, 20);


    // Tạo label và entry cho tên đăng nhập
    label_username_sign_in = gtk_label_new("Username:");
    username_entry_login = gtk_entry_new();
    gtk_widget_set_size_request(username_entry_login, 400, 30);
    gtk_fixed_put(GTK_FIXED(sign_in_fixed), label_username_sign_in, 40, 222);
    gtk_fixed_put(GTK_FIXED(sign_in_fixed), username_entry_login, 40, 250);


    // Tạo label và entry cho mật khẩu
    label_password_sign_in = gtk_label_new("Password:");
    password_entry_login = gtk_entry_new();
    gtk_widget_set_size_request(password_entry_login, 400, 30);
    gtk_entry_set_visibility(GTK_ENTRY(password_entry_login), FALSE);
    gtk_fixed_put(GTK_FIXED(sign_in_fixed), label_password_sign_in, 40, 320);
    gtk_fixed_put(GTK_FIXED(sign_in_fixed), password_entry_login, 40, 350);


    // Tạo button đăng nhập
    button_login_sign_in = gtk_button_new_with_label("Login");
    g_signal_connect(button_login_sign_in, "clicked", G_CALLBACK(sign_in_button_click), NULL);
    // Tạo một GdkColor mới đại diện cho màu xám

    // Tạo button đăng ký
    button_register_sign_in = gtk_button_new_with_label("Register");
    g_signal_connect(button_register_sign_in, "clicked", G_CALLBACK(sign_in_sign_up_button_click), NULL);

    button_exit_sign_in = gtk_button_new_with_label("Exit");
    g_signal_connect(button_exit_sign_in, "clicked", G_CALLBACK(sign_in_exit_button_click), NULL);

    gtk_widget_set_size_request(button_login_sign_in, 400, 30);
    gtk_widget_set_size_request(button_register_sign_in, 400, 30);
    gtk_widget_set_size_request(button_exit_sign_in, 400, 30);

    gtk_fixed_put(GTK_FIXED(sign_in_fixed), button_login_sign_in, 40, 400);
    gtk_fixed_put(GTK_FIXED(sign_in_fixed), button_register_sign_in, 40, 450);
    gtk_fixed_put(GTK_FIXED(sign_in_fixed), button_exit_sign_in, 40, 500);
}
void sign_in_show()
{
    //Init sign in window
    sign_in_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    set_sign_in_properties();
    load_css_sign_in();


    // show window
    gtk_widget_show_all(sign_in_win);

    gtk_main();

}
