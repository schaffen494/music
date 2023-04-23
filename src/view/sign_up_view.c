//
// Created by ADMIN on 4/17/2023.
//

#include "sign_up_view.h"
#include "src/control/sign_up_control.h"
GtkWidget *username_entry_signup;
GtkWidget *password_entry_signup;
GtkWidget *sign_up_win,*sign_up_fixed,
        *button_register_register,*label_password_regis,
        *image_logo_regis,*label_username_regis,*button_exit_sign_up;

void load_sign_up_css()
{
    //Load file css
    GtkCssProvider *provider = gtk_css_provider_new();
    GdkDisplay *display = gdk_display_get_default ();
    GdkScreen *screen = gdk_display_get_default_screen (display);
    GError *error = NULL;

    gtk_css_provider_load_from_path(provider, "src\\view\\properties\\sign_up.css", &error);
    if (error)
    {
        g_warning ("%s", error->message);
        g_clear_error (&error);
    }
    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);


}
void set_sign_up_properties()
{
    gtk_window_set_title(GTK_WINDOW(sign_up_win), "Signup");
    gtk_window_set_decorated(GTK_WINDOW(sign_up_win), FALSE);
    gtk_window_set_default_size(GTK_WINDOW(sign_up_win), 500,700);
    gtk_window_set_position(GTK_WINDOW(sign_up_win), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(sign_up_win), FALSE);
    gtk_container_set_border_width(GTK_CONTAINER(sign_up_win), 10);

    GdkRGBA color;
    gdk_rgba_parse(&color, "#3c3f41");
    gtk_widget_override_background_color(sign_up_win, GTK_STATE_FLAG_NORMAL, &color);


    // Tạo fixed container để set vị trí của các Widget
    sign_up_fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(sign_up_win), sign_up_fixed);

    // Tạo logo
    image_logo_regis = gtk_image_new_from_file("assets/sign_in_logo.png");
    gtk_fixed_put(GTK_FIXED(sign_up_fixed), image_logo_regis, 165, 20);

    // Tạo label và entry cho tên đăng nhập
    label_username_regis = gtk_label_new("Username:");
    gtk_widget_set_name(label_username_regis, "label_username");
    username_entry_signup= gtk_entry_new();
    gtk_widget_set_size_request(username_entry_signup, 400, 30);
    gtk_widget_set_name(username_entry_signup, "username_entry_signup");
    gtk_fixed_put(GTK_FIXED(sign_up_fixed), label_username_regis, 40, 222);
    gtk_fixed_put(GTK_FIXED(sign_up_fixed), username_entry_signup, 40, 250);

    // Tạo label và entry cho mật khẩu
    label_password_regis = gtk_label_new("Password:");
    gtk_widget_set_name(label_password_regis, "label_password");
    password_entry_signup = gtk_entry_new();
    gtk_widget_set_size_request(password_entry_signup, 400, 30);
    gtk_entry_set_visibility(GTK_ENTRY(password_entry_signup), FALSE);
    gtk_widget_set_name(password_entry_signup, "password_entry_signup");
    gtk_fixed_put(GTK_FIXED(sign_up_fixed), label_password_regis, 40, 320);
    gtk_fixed_put(GTK_FIXED(sign_up_fixed), password_entry_signup, 40, 350);


    // Tạo button đăng ký
    button_register_register = gtk_button_new_with_label("Register");
    gtk_widget_set_name(button_register_register, "button_register");
    //g_signal_connect(button_register_register, "clicked", G_CALLBACK(sign_up_click), NULL);
    gtk_widget_set_size_request(button_register_register, 400, 30);
    gtk_fixed_put(GTK_FIXED(sign_up_fixed),button_register_register, 40, 400);
    g_signal_connect(button_register_register, "clicked", G_CALLBACK(sign_up_button_click), NULL);

    button_exit_sign_up = gtk_button_new_with_label("Exit");
    g_signal_connect(button_exit_sign_up, "clicked", G_CALLBACK(sign_up_exit_button_click), NULL);
    gtk_widget_set_size_request(button_exit_sign_up, 400, 30);
    gtk_fixed_put(GTK_FIXED(sign_up_fixed), button_exit_sign_up, 40, 450);

}
void sign_up_show()
{
    // Tạo cửa sổ
    sign_up_win= gtk_window_new(GTK_WINDOW_TOPLEVEL);

    set_sign_up_properties();
    load_sign_up_css();
    // Hiển thị cửa sổ
    gtk_widget_show_all(sign_up_win);

    // Chạy vòng lặp GTK
    gtk_main();
}
