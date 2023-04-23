#include "intro_view.h"
#include "src/config/database_config.h"
#include "src/view/sign_in_view.h"
GtkWidget *intro_win,*logo_intro;
GdkPixbuf *access_intro_logo;
GtkCssProvider *css_intro;

void load_css_intro()
{
    //set name for intro_window
    gtk_widget_set_name(intro_win,"intro-window");

    //apply css for intro_window
    css_intro = gtk_css_provider_new ();
    get_path("src\\view\\properties\\intro.css");
    GFile *file = g_file_new_for_path (path_file);
    GError *error = NULL;
    gtk_css_provider_load_from_file (css_intro, file, &error);
    if (error != NULL) {
        g_warning ("Error loading CSS file: %s", error->message);
        g_clear_error (&error);
    }
    GtkStyleContext *context = gtk_widget_get_style_context (intro_win);
    gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER (css_intro), GTK_STYLE_PROVIDER_PRIORITY_USER);

}
void set_properties()
{
    //set attribute
    gtk_widget_set_size_request(intro_win, 500, 500);
    gtk_window_set_decorated(GTK_WINDOW(intro_win), FALSE);
    gtk_window_set_position(GTK_WINDOW(intro_win), GTK_WIN_POS_CENTER_ALWAYS);

    get_path("assets\\logo.png");

    //show logo app
    access_intro_logo = gdk_pixbuf_new_from_file(path_file, NULL);
    logo_intro = gtk_image_new_from_pixbuf(access_intro_logo);
    gtk_container_add(GTK_CONTAINER(intro_win), logo_intro);
}
void intro_show()
{

    //Init intro window
    intro_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    set_properties();

    load_css_intro();

    //show intro_window
    gtk_widget_show_all(intro_win);

    //change intro_window
    g_timeout_add_seconds(1, (GSourceFunc)gtk_widget_destroy, intro_win);
    g_timeout_add_seconds(1, (GSourceFunc)sign_in_show, intro_win);

    gtk_main();
}