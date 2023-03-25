//
// Created by ASUS on 3/22/2023.
//

#ifndef MUSIC_SEARCHBAR_H
#define MUSIC_SEARCHBAR_H
#include <gtk/gtk.h>

#include <gtk/gtk.h>

// Callback function for the search button
void on_search_button_clicked(GtkButton *button, gpointer user_data) {
    // Get the text from the search entry
    GtkEntry *search_entry = (GtkEntry *) user_data;
    const gchar *search_text = gtk_entry_get_text(search_entry);

    // TODO: Use the search_text to search for music in your project
    // and display the results in your application.
}

int main(int argc, char *argv[]) {
    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create a new window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Music Streaming");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a search entry
    GtkWidget *search_entry = gtk_entry_new();
    g_signal_connect(search_entry, "activate", G_CALLBACK(on_search_button_clicked), (gpointer) search_entry);

    // Create a search button
    GtkWidget *search_button = gtk_button_new_with_label("Search");
    g_signal_connect(search_button, "clicked", G_CALLBACK(on_search_button_clicked), (gpointer) search_entry);

    // Create a horizontal box to hold the search entry and search button
    GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_pack_start(GTK_BOX(hbox), search_entry, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), search_button, FALSE, FALSE, 0);

    // Create a vertical box to hold the search box and other widgets
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

    // Add the vbox to the window and show everything
    gtk_container_add(GTK_CONTAINER(window), vbox);

    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(provider,
                                    "entry {\n"
                                    "    background-color: #2c3e50;\n"
                                    "    border: none;\n"
                                    "    color: #fff;\n"
                                    "    padding: 8px 12px;\n"
                                    "    border-radius: 20px;\n"
                                    "    font-size: 14px;\n"
                                    "    font-weight: 400;\n"
                                    "}\n"
                                    "\n"
                                    "entry:focus {\n"
                                    "    outline: none;\n"
                                    "}\n"
                                    "\n"
                                    "button {\n"
                                    "    background-color: #2980b9;\n"
                                    "    color: #fff;\n"
                                    "    padding: 8px 20px;\n"
                                    "    border: none;\n"
                                    "    border-radius: 20px;\n"
                                    "    font-size: 14px;\n"
                                    "    font-weight: 400;\n"
                                    "    cursor: pointer;\n"
                                    "}\n"
                                    "\n"
                                    "button:hover {\n"
                                    "    background-color: #1a5276;\n"
                                    "}\n"
            , -1, NULL);

    // Apply the CSS to the search entry and search button
    GtkStyleContext *context_entry = gtk_widget_get_style_context(search_entry);
    gtk_style_context_add_provider(context_entry, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    GtkStyleContext *context_button = gtk_widget_get_style_context(search_button);
    gtk_style_context_add_provider(context_button, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    gtk_widget_show_all(window);

    // Start the main loop
    gtk_main();

    return 0;
}


#endif //MUSIC_SEARCHBAR_H
