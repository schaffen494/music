//
// Created by Nhat on 4/5/2023.
//

#ifndef MUSIC_SELECTION_MENU_H
#define MUSIC_SELECTION_MENU_H

#include <gtk/gtk.h>

// Create all widgets for the Selection Menu
void create_selection_menu(GtkWidget *grid)
{
    GtkWidget *menu_box,
              *bottom_box, // Empty box below menu box
              *background_box,
              *avatar,
              *discover_button,
              *follow_button,
              *my_music_button,
              *upload_button;

    // Create a vertical box to contain the menu grid
    menu_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 30);
    gtk_grid_attach(GTK_GRID(grid), menu_box, 0, 1, 1, 1);

    // Create a empty box to occupy the bottom of the selection menu
    bottom_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_grid_attach(GTK_GRID(grid), bottom_box, 0, 2, 1, 1);
    gtk_widget_set_vexpand(bottom_box, TRUE);

    // Create the logo
    avatar = gtk_image_new_from_file("assets\\logo_minimized.png");
    gtk_grid_attach(GTK_GRID(grid), avatar, 0, 0, 1, 1);

    // Create the Discover button
    discover_button = gtk_button_new_with_label("Discover");
    gtk_button_set_relief(GTK_BUTTON(discover_button), GTK_RELIEF_NONE);
    gtk_box_pack_start(GTK_BOX(menu_box), discover_button, FALSE, FALSE, 0);

    // Create the Follow button
    follow_button = gtk_button_new_with_label("Follow");
    gtk_button_set_relief(GTK_BUTTON(follow_button), GTK_RELIEF_NONE);
    gtk_box_pack_start(GTK_BOX(menu_box), follow_button, FALSE, FALSE, 0);

    // Create the My Music button
    my_music_button = gtk_button_new_with_label("My Music");
    gtk_button_set_relief(GTK_BUTTON(my_music_button), GTK_RELIEF_NONE);
    gtk_box_pack_start(GTK_BOX(menu_box), my_music_button, FALSE, FALSE, 0);

    // Create the Upload button
    upload_button = gtk_button_new_with_label("Upload");
    gtk_button_set_relief(GTK_BUTTON(upload_button), GTK_RELIEF_NONE);
    gtk_box_pack_start(GTK_BOX(menu_box), upload_button, FALSE, FALSE, 0);

    // Create a background box
    background_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_name(background_box, "background-box");
    gtk_grid_attach(GTK_GRID(grid), background_box, 0, 0, 1, 3);

    // Load css file
    GtkCssProvider *provider = gtk_css_provider_new();
    GdkDisplay *display = gdk_display_get_default ();
    GdkScreen *screen = gdk_display_get_default_screen (display);
    GError *error = NULL;

    gtk_css_provider_load_from_path(provider, "src\\components\\selection_menu.css", &error);

    if (error)
    {
        g_warning ("%s", error->message);
        g_clear_error (&error);
    }

    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
}
#endif //MUSIC_SELECTION_MENU_H
