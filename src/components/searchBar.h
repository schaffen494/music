#include <gtk/gtk.h>

static void search_button_clicked(GtkButton *button, gpointer user_data) {
    GtkEntry *search_entry = GTK_ENTRY(user_data);
    const char *search_text = gtk_entry_get_text(search_entry);
    // Perform search with the search_text
    g_print("%s\n", search_text);
}

static void on_search_activate(GtkEntry *entry, gpointer user_data) {
    const gchar *text = gtk_entry_get_text(entry);
    // Perform search operation using the text entered in the search entry
    g_print("%s \n", text);
}

// Callback function for the search button

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Create a new window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Music Streaming");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a search entry
    GtkWidget *search_entry = gtk_entry_new();
    g_signal_connect(search_entry, "activate", G_CALLBACK(on_search_activate), NULL);

    // Create the search button
    GtkWidget *search_button = gtk_button_new();
    gtk_widget_set_halign(search_button, GTK_ALIGN_CENTER);
    gtk_button_set_always_show_image(GTK_BUTTON(search_button), TRUE);
    gtk_button_set_image(GTK_BUTTON(search_button), gtk_image_new_from_icon_name("edit-find-symbolic", GTK_ICON_SIZE_BUTTON));
    g_signal_connect(search_button, "clicked", G_CALLBACK(search_button_clicked), search_entry);

    // Create a horizontal box to hold the search entry and search button
    GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_pack_start(GTK_BOX(hbox), search_entry, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), search_button, FALSE, FALSE, 0);
    gtk_box_set_center_widget(GTK_BOX(hbox), search_entry);
    gtk_box_set_spacing(GTK_BOX(hbox), 10);

    // Create a vertical box to hold the search box and other widgets
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

    // Add the vbox to the window and show everything
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Load the CSS
    GtkCssProvider *provider = gtk_css_provider_new();
    GError *error = NULL;

    if (!gtk_css_provider_load_from_path(provider, "C:\\Users\\ASUS\\CLionProjects\\music\\src\\components\\searchBar.css", &error)) {
        g_warning("Failed to load CSS file: %s", error->message);
        g_clear_error(&error);
    }

    GtkStyleContext *context_entry = gtk_widget_get_style_context(search_entry);
    gtk_style_context_add_provider(context_entry, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    GtkStyleContext *context_button = gtk_widget_get_style_context(search_button);
    gtk_style_context_add_provider(context_button, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    gtk_widget_show_all(window);

    // Start the main loop
    gtk_main();

    return 0;
}
