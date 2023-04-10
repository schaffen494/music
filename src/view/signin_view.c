#include "signin_view.h"
#include "src/models/users.h"
#include "src/view/mainboard_view.h"
#include "src/view/signup_view.h"
GtkWidget *username_entry_login;
GtkWidget *password_entry_login;
GtkWidget *sign_in_window;

gboolean authenticate_user(const char *username, const char *password)
{

    if (check_sign_in(username,password) == LOGIN_OK) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int login_clicked(GtkWidget *widget, gpointer data) {
    const char *username = gtk_entry_get_text(GTK_ENTRY(username_entry_login));
    const char *password = gtk_entry_get_text(GTK_ENTRY(password_entry_login));
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
        gtk_entry_set_text(username_entry_login, "");
        gtk_entry_set_text(password_entry_login, "");
        return 1;
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

    // Tạo cửa sổ
    sign_in_window= gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_decorated(GTK_WINDOW(sign_in_window), FALSE);
    gtk_window_set_title(GTK_WINDOW(sign_in_window), "Login");
    gtk_window_set_default_size(GTK_WINDOW(sign_in_window), 500,700);
    gtk_window_set_position(GTK_WINDOW(sign_in_window), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(sign_in_window), FALSE);
    gtk_container_set_border_width(GTK_CONTAINER(sign_in_window), 10);

    GdkRGBA color;
    gdk_rgba_parse(&color, "#3c3f41");
    gtk_widget_override_background_color(sign_in_window, GTK_STATE_FLAG_NORMAL, &color);


    // Tạo fixed container để set vị trí của các Widget
    GtkWidget* fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(sign_in_window), fixed);

    // Tạo logo
    GtkWidget *image_logo = gtk_image_new_from_file("assets/sign_in_logo.png");
    gtk_fixed_put(GTK_FIXED(fixed), image_logo, 165, 20);

    // Tạo label và entry cho tên đăng nhập
    GtkWidget *label_username = gtk_label_new("Username:");
    gtk_widget_set_name(label_username, "label_username");
    username_entry_login= gtk_entry_new();
    gtk_widget_set_size_request(username_entry_login, 400, 30);
    gtk_widget_set_name(username_entry_login, "username_entry_login");
    gtk_fixed_put(GTK_FIXED(fixed), label_username, 40, 222);
    gtk_fixed_put(GTK_FIXED(fixed), username_entry_login, 40, 250);

    // Tạo label và entry cho mật khẩu
    GtkWidget *label_password = gtk_label_new("Password:");
    gtk_widget_set_name(label_password, "label_password");
    password_entry_login = gtk_entry_new();
    gtk_widget_set_size_request(password_entry_login, 400, 30);
    gtk_entry_set_visibility(GTK_ENTRY(password_entry_login), FALSE);
    gtk_fixed_put(GTK_FIXED(fixed), label_password, 40, 320);
    gtk_fixed_put(GTK_FIXED(fixed), password_entry_login, 40, 350);

    // Tạo button đăng nhập
    GtkWidget *button_login = gtk_button_new_with_label("Login");
    gtk_widget_set_name(button_login, "button_login");
    g_signal_connect(button_login, "clicked", G_CALLBACK(login_clicked), NULL);

    // Tạo button đăng ký
    GtkWidget *button_register = gtk_button_new_with_label("Register");
    gtk_widget_set_name(button_register, "button_register");
    g_signal_connect(button_register, "clicked", G_CALLBACK(signup_clicked), NULL);
    gtk_widget_set_size_request(button_login, 400, 30);
    gtk_widget_set_size_request(button_register, 400, 30);
    gtk_fixed_put(GTK_FIXED(fixed), button_login, 40, 400);
    gtk_fixed_put(GTK_FIXED(fixed), button_register, 40, 450);

    // Thêm các buttons vào một hình chữ nhật
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(box), label_username, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), username_entry_login, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), label_password, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), password_entry_login, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(box), button_login, FALSE, FALSE, 0);
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
    gtk_widget_show_all(sign_in_window);

    // Xử lý sự kiện đóng cửa sổ
    g_signal_connect(G_OBJECT(sign_in_window), "destroy", G_CALLBACK(exit), NULL);

    // Chạy vòng lặp GTK
    gtk_main();

}