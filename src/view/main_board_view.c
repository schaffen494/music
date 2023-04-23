//
// Created by ADMIN on 4/17/2023.
//

#include "src/view/main_board_view.h"
#include "src/view/components/menu.h"
#include "src/view/components/music_bar.h"
#include "src/view/components/search_bar.h"

#include "src/control/main_board_control.h"

GtkWidget *main_board_win;
GtkWidget* main_board_fixed;
GtkWidget *scrolled_window ,*explorer_button,*list,*list_tmp,
        *my_music_button,*playlist_button,*add_song_button,
        *add_playlist_button,*header_logo,*explore_icon,
        *my_music_icon,*upload_icon,*rect_area,*tab_label;

void set_main_board_properties()
{
    gtk_window_set_decorated(GTK_WINDOW(main_board_win), FALSE);
    gtk_window_set_position(GTK_WINDOW(main_board_win), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(main_board_win), 1500, 800);
    gtk_window_set_title(GTK_WINDOW(main_board_win), "Mystic melody");

    GdkRGBA color_main_board;
    gdk_rgba_parse(&color_main_board, "#1f1f1e");
    gtk_widget_override_background_color(main_board_win, GTK_STATE_FLAG_NORMAL, &color_main_board);

    main_board_fixed = gtk_fixed_new();

    gtk_container_add(GTK_CONTAINER(main_board_win), main_board_fixed);


    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_widget_set_size_request(scrolled_window, 1020, 510);
    gtk_fixed_put(GTK_FIXED(main_board_fixed), scrolled_window, 400, 170);

    menu_show();

    music_bar_show();

    search_bar_show();

    list = gtk_list_box_new();
    gtk_container_add(GTK_CONTAINER(scrolled_window), list);

    //Đăng ký callback cho sự kiện row-selected
    g_signal_connect(list, "row-selected", G_CALLBACK(selected), NULL);
    g_signal_connect(list, "row-activated", G_CALLBACK(selected), NULL);

    GdkColor color_list;
    gdk_color_parse("#1e1f1f", &color_list);
    gtk_widget_modify_bg(list, GTK_STATE_NORMAL, &color_list);
    gtk_widget_show_all(main_board_fixed);

    GdkRGBA color1  ;
    gdk_rgba_parse(&color1, "white");

    tab_label = gtk_label_new("Explore");
    gtk_widget_override_color(tab_label, GTK_STATE_NORMAL, &color1);
    gtk_fixed_put(GTK_FIXED(main_board_fixed), tab_label, 410, 100);

    // Lấy layout của label
    PangoLayout *layout = gtk_label_get_layout(GTK_LABEL(tab_label));

    // Thay đổi kích thước và độ đậm của label
    PangoFontDescription *font_desc = pango_font_description_new();
    pango_font_description_set_weight(font_desc, PANGO_WEIGHT_BOLD);
    pango_font_description_set_size(font_desc, 24 * PANGO_SCALE);
    pango_layout_set_font_description(layout, font_desc);
}

void main_board_show()
{
    main_board_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    set_main_board_properties();

    gtk_widget_show_all(main_board_win);

    tab_explorer_click();

    gtk_main();
}
