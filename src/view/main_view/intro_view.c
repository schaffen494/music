//
// Created by ADMIN on 4/13/2023.
//

#include "intro_view.h"
#include "src/view/main_view/signin_view.h"
GtkWidget *intro_window,*logo_intro;
GdkPixbuf *pixbuf;
GtkCssProvider *provider;
void load_css_intro()
{
    //set name for intro_window
    gtk_widget_set_name(intro_window,"intro-window");

    //apply css for intro_window
    provider = gtk_css_provider_new ();
    GFile *file = g_file_new_for_path ("src/view/properties/intro.css");
    GError *error = NULL;
    gtk_css_provider_load_from_file (provider, file, &error);
    if (error != NULL) {
        g_warning ("Error loading CSS file: %s", error->message);
        g_clear_error (&error);
    }
    GtkStyleContext *context = gtk_widget_get_style_context (intro_window);
    gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER (provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

}
void set_properties()
{
//set attribute
    gtk_widget_set_size_request(intro_window, 500, 500);
    gtk_window_set_decorated(GTK_WINDOW(intro_window), FALSE);
    gtk_window_set_position(GTK_WINDOW(intro_window), GTK_WIN_POS_CENTER_ALWAYS);

    //show logo app
    pixbuf = gdk_pixbuf_new_from_file("assets/logo.png", NULL);
    logo_intro = gtk_image_new_from_pixbuf(pixbuf);
    gtk_container_add(GTK_CONTAINER(intro_window), logo_intro);
}
void intro_show()
{
    // init intro_window
    intro_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    set_properties();
    load_css_intro();

    //show intro_window
    gtk_widget_show_all(intro_window);
    // release GTK CSS provider
    g_object_unref (provider);
    //change intro_window
    g_timeout_add_seconds(2, (GSourceFunc)gtk_widget_destroy, intro_window);
    g_timeout_add_seconds(2, (GSourceFunc)sign_in_show, intro_window);
    gtk_main();
}