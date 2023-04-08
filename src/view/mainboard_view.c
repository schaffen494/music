//
// Created by ADMIN on 4/6/2023.
//

#include "mainboard_view.h"
#include "src/components/selection_menu.h"
#include "src/components/play_music_taskbar.h"

GtkWidget *main_board_window;
void main_board_show()
{
    // Create a window
    GtkWidget *main_board_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(main_board_window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(main_board_window), 1500, 800);
    gtk_window_set_title(GTK_WINDOW(main_board_window), "Mystic melody");

    GdkRGBA color;
    gdk_rgba_parse(&color, "#1e1e1e");
    gtk_widget_override_background_color(main_board_window, GTK_STATE_FLAG_NORMAL, &color);
    // Create the main grid to contain the selection menu, the background, and the new grids
    GtkWidget *main_grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(main_board_window), main_grid);

    // Create the original grid
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_attach(GTK_GRID(main_grid), grid, 0, 0, 1, 1);

    create_selection_menu(grid);
    init_play_music_taskbar(grid);

    gtk_widget_show_all(main_board_window);
    gtk_main();
}