#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

void copy_file(const char *src_path, const char *dest_path)
{
    FILE *src_file, *dest_file;
    char buffer[1024];
    size_t bytes_read;

    src_file = fopen(src_path, "rb");
    dest_file = fopen(dest_path, "wb");

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes_read, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
    exit(0);
}

void button_clicked(GtkWidget *widget, gpointer data)
{
    const char *src_path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(data));
    const char *dest_path = "D:\\music\\src\\db\\sound\\file.mp3";

    copy_file(src_path, dest_path);

    gtk_label_set_text(GTK_LABEL(gtk_label_new("")), "File copied!");
}

int main(int argc, char *argv[])
{
    GtkWidget *window, *grid, *filechooser, *button, *label;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Copy MP3 File");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 100);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    filechooser = gtk_file_chooser_button_new("Select a File", GTK_FILE_CHOOSER_ACTION_OPEN);
    gtk_grid_attach(GTK_GRID(grid), filechooser, 0, 0, 1, 1);

    button = gtk_button_new_with_label("Copy File");
    g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), filechooser);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 1, 1);

    label = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 2, 1, 1);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
