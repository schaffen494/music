//
// Created by ADMIN on 4/16/2023.
//

#include "music_bar.h"
#include "src/view/main_board_view.h"
#include "src/control/main_board_control.h"
GtkWidget *button_play_pause,*image_song_avatar , *back_button, *skip_button, *sound_label, *progress_bar, *time_label, *song_label, *artist_label;
gboolean is_playing = 0;
GtkWidget *image;
gdouble progress = 0.0;
gint elapsed_seconds = 0;
gint song_duration = 300; // in seconds
gdouble stored_progress_global = 0.0;
gint stored_elapsed_seconds_global = 0;
int min,sec;

void on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {

    // Chỉnh màu cho background của hcn
    cairo_set_source_rgb(cr, 25/255.0, 24/255.0, 25/255.0);// fill color

    // Bắt đầu vẽ hcn
    cairo_rectangle(cr, 0, 0, 1500, 140);
    cairo_fill_preserve(cr); // fill the rectangle
}
gboolean update_progress_bar(gpointer data) {
    if (is_playing) {
        // Update progress
        progress += 0.00006;
        gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress_bar), progress);

        // Update elapsed time
        elapsed_seconds = progress * song_duration;
        gint minutes = elapsed_seconds / 60;
        min = (int)min;
        gint seconds = elapsed_seconds % 60;
        sec = (int)seconds;
        gchar *time_str = g_strdup_printf("%02d:%02d", minutes, seconds);
        gtk_label_set_text(GTK_LABEL(time_label), time_str);
        g_free(time_str);

        // Stop playback at end of song
        if (elapsed_seconds >= song_duration) {
            is_playing = FALSE;
            progress = 0.0;
            elapsed_seconds = 0;
            gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress_bar), progress);
            time_str = g_strdup_printf("%02d:%02d", 0, 0);
            gtk_label_set_text(GTK_LABEL(time_label), time_str);
            g_free(time_str);
        }
    }
    return TRUE;
}
void set_music_bar_properties()
{
    // Tạo một hình chữ nhật để chứa toàn bộ Widget
    GtkWidget *rect_area = gtk_drawing_area_new();
    // Set size và vị trí cho hình chữ nhật
    gtk_widget_set_size_request(rect_area, 1500, 140);
    gtk_fixed_put(GTK_FIXED(main_board_fixed), rect_area, 0, 680);
    // bắt đầu vẽ hình chữ nhật
    g_signal_connect(rect_area, "draw", G_CALLBACK(on_draw_event), NULL);

    GdkRGBA color;
    gdk_rgba_parse(&color, "#ffffff");

    // Tạo label để chứ tên bài hát và tên nghệ sĩ
    song_label = gtk_label_new("Name of song");
    gtk_widget_override_color(song_label, GTK_STATE_FLAG_NORMAL, &color);
    gtk_fixed_put(GTK_FIXED(main_board_fixed), song_label, 170, 710);
    gtk_widget_set_name(song_label, "song-label");

    artist_label = gtk_label_new("Artist");
    gtk_widget_override_color(artist_label, GTK_STATE_FLAG_NORMAL, &color);
    gtk_fixed_put(GTK_FIXED(main_board_fixed), artist_label, 170, 740);
    gtk_widget_set_name(artist_label, "artist-label");

    // Create a new button
    button_play_pause = gtk_toggle_button_new();
    gtk_button_set_relief(GTK_BUTTON(button_play_pause), GTK_RELIEF_NONE);


    // Create a new image and set it to the play icon
    image = gtk_image_new_from_file("assets\\play_button.svg");
    gtk_button_set_image(GTK_BUTTON(button_play_pause), image);
    gtk_fixed_put(GTK_FIXED(main_board_fixed), button_play_pause, 900, 715);

    // Khởi tạo widget cho việc chứa ảnh của bài hát
    image_song_avatar = gtk_image_new_from_file("assets/OIP.jpg");
    gtk_widget_set_name(image_song_avatar, "song-poster");
    gtk_fixed_put(GTK_FIXED(main_board_fixed), image_song_avatar, 36, 690);

    // Create progress bar
    progress_bar = gtk_progress_bar_new();
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress_bar), progress);
    gtk_widget_set_size_request(progress_bar, 560, 10);
    gtk_fixed_put(GTK_FIXED(main_board_fixed), progress_bar,636, 769);

    // Create time label
    time_label = gtk_label_new(NULL);
    gtk_widget_override_color(time_label, GTK_STATE_FLAG_NORMAL, &color);
    gtk_label_set_text(GTK_LABEL(time_label), "00:00");
    gtk_fixed_put(GTK_FIXED(main_board_fixed), time_label,586, 765);

    // Update progress every 10ms
    g_timeout_add(10, update_progress_bar, NULL);

    // Connect the "toggled" signal to the callback function
    g_signal_connect(button_play_pause, "toggled", G_CALLBACK(on_button_toggled), NULL);

    GtkWidget *add_button = gtk_button_new_with_label("");
    gtk_fixed_put(GTK_FIXED(main_board_fixed), add_button, 1300, 730);
    gtk_widget_set_size_request(add_button, 50, 50);
    gtk_button_set_relief(GTK_BUTTON(add_button), GTK_RELIEF_NONE);
    // Thêm các icon của từng mục
    GtkWidget *add_icon = gtk_image_new_from_file("assets/add_logo.svg");
    gtk_fixed_put(GTK_FIXED(main_board_fixed), add_icon, 1300, 730);
    g_signal_connect(add_button, "clicked", G_CALLBACK(add_song_to_playlist), NULL);

    GtkWidget *remove_button = gtk_button_new_with_label("");
    gtk_fixed_put(GTK_FIXED(main_board_fixed),remove_button, 1380, 730);
    gtk_widget_set_size_request(remove_button, 50, 50);
    gtk_button_set_relief(GTK_BUTTON(remove_button), GTK_RELIEF_NONE);
    // Thêm các icon của từng mục
    GtkWidget *remove_icon = gtk_image_new_from_file("assets/remove_logo.svg");
    gtk_fixed_put(GTK_FIXED(main_board_fixed), remove_icon, 1380, 730);
    g_signal_connect(remove_button, "clicked", G_CALLBACK(remove_song_to_playlist), NULL);
}
void music_bar_show()
{
    set_music_bar_properties();
}