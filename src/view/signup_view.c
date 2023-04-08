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
    gtk_window_set_position(GTK_WINDOW(sign_up_window), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(sign_up_window), FALSE);
    gtk_container_set_border_width(GTK_CONTAINER(sign_up_window), 10);

    GdkRGBA color;
    gdk_rgba_parse(&color, "#3c3f41");
    gtk_widget_override_background_color(sign_up_window, GTK_STATE_FLAG_NORMAL, &color);

    // Tạo layout
    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(sign_up_window), grid);

    // Tạo logo
    GtkWidget *image_logo = gtk_image_new_from_file("assets/logo.png");
    gtk_grid_attach(GTK_GRID(grid), image_logo, 0, 0, 2, 1);

    // Tạo label và entry cho tên đăng nhập
    GtkWidget *label_username = gtk_label_new("Username:");
    username_entry_signup = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), label_username, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), username_entry_signup, 1, 1, 1, 1);

    // Tạo label và entry cho mật khẩu
    GtkWidget *label_password = gtk_label_new("Password:");
    password_entry_signup = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(password_entry_signup), FALSE);
    gtk_grid_attach(GTK_GRID(grid), label_password, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), password_entry_signup, 1, 2, 1, 1);

    // Tạo button đăng nhập
    GtkWidget *button_login = gtk_button_new_with_label("Signup");
    g_signal_connect(button_login, "clicked", G_CALLBACK(sign_up_click), NULL);
    gtk_grid_attach(GTK_GRID(grid), button_login, 0, 3, 1, 1);

    // Nạp file CSS để thiết lập màu cho các phần tử
    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(provider, "src/components/properties/log_in.css", NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                                              GTK_STYLE_PROVIDER(provider),
                                              GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Hiển thị cửa sổ
    gtk_widget_show_all(sign_up_window);

    // Xử lý sự kiện đóng cửa sổ
    g_signal_connect(G_OBJECT(sign_up_window), "destroy", G_CALLBACK(exit), NULL);

    // Chạy vòng lặp GTK
    gtk_main();

}