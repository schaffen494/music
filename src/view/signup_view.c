//
// Created by ADMIN on 4/6/2023.
//

#include "signup_view.h"
#include "src/models/users.h"
#include "src/view/mainboard_view.h"
GtkWidget *username_entry_signup;
GtkWidget *password_entry_signup;
GtkWidget *sign_up_window;

gboolean authenticate_user_sign_up(const char *username, const char *password)
{

    if (add_account(username,password) == SIGNUP_OK) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int sign_up_click(GtkWidget *widget, gpointer data)
{
    const char *username = gtk_entry_get_text(GTK_ENTRY(username_entry_signup));
    const char *password = gtk_entry_get_text(GTK_ENTRY(password_entry_signup));
    GtkWidget *dialog;
    if (authenticate_user_sign_up(username, password)) {
        dialog = gtk_message_dialog_new(NULL,
                                        GTK_DIALOG_MODAL,
                                        GTK_MESSAGE_INFO,
                                        GTK_BUTTONS_OK,
                                        "Đăng k thành công!");
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
        gtk_entry_set_text(username_entry_signup, "");
        gtk_entry_set_text(password_entry_signup, "");
        return 1;
    }


    /* Hủy hộp thoại */
    gtk_widget_destroy(dialog);
}
void sign_up_show()
{
    // Tạo cửa sổ
    sign_up_window= gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(sign_up_window), "Signup");
    gtk_window_set_decorated(GTK_WINDOW(sign_up_window), FALSE);
    gtk_window_set_default_size(GTK_WINDOW(sign_up_window), 500,700);
    gtk_window_set_position(GTK_WINDOW(sign_up_window), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(sign_up_window), FALSE);
    gtk_container_set_border_width(GTK_CONTAINER(sign_up_window), 10);


    GdkRGBA color;
    gdk_rgba_parse(&color, "#3c3f41");
    gtk_widget_override_background_color(sign_up_window, GTK_STATE_FLAG_NORMAL, &color);


    // Tạo fixed container để set vị trí của các Widget
    GtkWidget* fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(sign_up_window), fixed);

    // Tạo logo
    GtkWidget *image_logo = gtk_image_new_from_file("assets/sign_in_logo.png");
    gtk_fixed_put(GTK_FIXED(fixed), image_logo, 165, 20);

    // Tạo label và entry cho tên đăng nhập
    GtkWidget *label_username = gtk_label_new("Username:");
    gtk_widget_set_name(label_username, "label_username");
    username_entry_signup= gtk_entry_new();
    gtk_widget_set_size_request(username_entry_signup, 400, 30);
    gtk_widget_set_name(username_entry_signup, "username_entry_login");
    gtk_fixed_put(GTK_FIXED(fixed), label_username, 40, 222);
    gtk_fixed_put(GTK_FIXED(fixed), username_entry_signup, 40, 250);

    // Tạo label và entry cho mật khẩu
    GtkWidget *label_password = gtk_label_new("Password:");
    gtk_widget_set_name(label_password, "label_password");
    password_entry_signup = gtk_entry_new();
    gtk_widget_set_size_request(password_entry_signup, 400, 30);
    gtk_entry_set_visibility(GTK_ENTRY(password_entry_signup), FALSE);
    gtk_fixed_put(GTK_FIXED(fixed), label_password, 40, 320);
    gtk_fixed_put(GTK_FIXED(fixed), password_entry_signup, 40, 350);


    // Tạo button đăng ký
    GtkWidget *button_register = gtk_button_new_with_label("Register");
    gtk_widget_set_name(button_register, "button_register");
    g_signal_connect(button_register, "clicked", G_CALLBACK(sign_up_click), NULL);
    gtk_widget_set_size_request(button_register, 400, 30);
    gtk_fixed_put(GTK_FIXED(fixed), button_register, 40, 450);

    // Thêm các buttons vào một hình chữ nhật
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(box), label_username, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), username_entry_signup, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), label_password, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), password_entry_signup, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(box), button_register, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(fixed), box);

    //Load file css
    GtkCssProvider *provider = gtk_css_provider_new();
    GdkDisplay *display = gdk_display_get_default ();
    GdkScreen *screen = gdk_display_get_default_screen (display);
    GError *error = NULL;

    gtk_css_provider_load_from_path(provider, "D:\\mystic_melody\\src\\properties\\sign_in.css", &error);
    if (error)
    {
        g_warning ("%s", error->message);
        g_clear_error (&error);
    }
    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    // Hiển thị cửa sổ
    gtk_widget_show_all(sign_up_window);

    // Xử lý sự kiện đóng cửa sổ
    g_signal_connect(G_OBJECT(sign_up_window), "destroy", G_CALLBACK(exit), NULL);

    // Chạy vòng lặp GTK
    gtk_main();

}