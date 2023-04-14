//
// Created by ASUS on 4/3/2023.
//
#include "musicBar.h"
#include <gtk/gtk.h>
#include "src/models/songs.h"
#include "src/view/components/menu.h"
GtkWidget *play_button, *stop_button, *back_button, *skip_button, *sound_label, *progress_bar, *time_label, *song_label, *artist_label;
gboolean is_playing = 0;
GtkWidget *image;
gdouble progress = 0.0;
gint elapsed_seconds = 0;
gint song_duration = 300; // in seconds
gdouble stored_progress_global = 0.0;
gint stored_elapsed_seconds_global = 0;

void toggle_stop_button();
void play_song(GtkWidget *widget, gpointer data);
void stop_song(GtkWidget *widget, gpointer data);
void on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data);
gboolean update_progress_bar(gpointer data);

void create_MusicBar(GtkWidget* fixed) {

    // Tạo một hình chữ nhật để chứa toàn bộ Widget
    GtkWidget *rect_area = gtk_drawing_area_new();
    // Set size và vị trí cho hình chữ nhật
    gtk_widget_set_size_request(rect_area, 1500, 140);
    gtk_fixed_put(GTK_FIXED(fixed), rect_area, 0, 680);
    // bắt đầu vẽ hình chữ nhật
    g_signal_connect(rect_area, "draw", G_CALLBACK(on_draw_event), NULL);

    // Khởi tạo nút chạy nhạc
    play_button = gtk_button_new_with_label("");
    gtk_fixed_put(GTK_FIXED(fixed), play_button, 714, 715);
    gtk_button_set_relief(GTK_BUTTON(play_button), GTK_RELIEF_NONE);
    GdkPixbuf *pixbuf_play = gdk_pixbuf_new_from_file("assets/play_button.svg", NULL);
    GtkImage *image_play = gtk_image_new_from_pixbuf(pixbuf_play);
    gtk_button_set_image(GTK_BUTTON(play_button), GTK_WIDGET(image_play));


    // Khởi tạo nút dừng nhạc
    stop_button = gtk_button_new_with_label("");
    gtk_fixed_put(GTK_FIXED(fixed), stop_button, 714, 715);
    gtk_button_set_relief(GTK_BUTTON(stop_button), GTK_RELIEF_NONE);
    GdkPixbuf *pixbuf_stop = gdk_pixbuf_new_from_file("assets/stop_button.svg", NULL);
    GtkImage *image_stop = gtk_image_new_from_pixbuf(pixbuf_stop);
    gtk_button_set_image(GTK_BUTTON(stop_button), GTK_WIDGET(image_stop));
    gtk_widget_show(image_stop);



    GdkRGBA color;
    gdk_rgba_parse(&color, "#ffffff");

    // Kết nối buttons với callback của nó. Khi mà ấn vào button thì dữ liệu trả về sẽ là gì... (Đại loại là vậy)
    g_signal_connect(play_button, "clicked", G_CALLBACK(play_song), NULL);
    g_signal_connect(stop_button, "clicked", G_CALLBACK(stop_song), NULL);



    // Khởi tạo widget cho việc chứa ảnh của bài hát
    image = gtk_image_new_from_file("assets/OIP.jpg");
    gtk_widget_set_name(image, "song-poster");
    gtk_fixed_put(GTK_FIXED(fixed), image, 36, 687);


    // Create progress bar
    progress_bar = gtk_progress_bar_new();
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress_bar), progress);
    gtk_widget_set_size_request(progress_bar, 560, 10);
    gtk_fixed_put(GTK_FIXED(fixed), progress_bar,450, 769);

    // Create time label
    time_label = gtk_label_new(NULL);
    gtk_widget_override_color(time_label, GTK_STATE_FLAG_NORMAL, &color);
    gtk_label_set_text(GTK_LABEL(time_label), "00:00");
    gtk_fixed_put(GTK_FIXED(fixed), time_label,400, 765);
    // Hide stop button initially
    gtk_widget_hide(stop_button);
    // Update progress every 10ms
    g_timeout_add(10, update_progress_bar, NULL);

    // Tạo lable để chứ tên bài hát và tên nghệ sĩ
    song_label = gtk_label_new(song_name_tmp);
    gtk_widget_override_color(song_label, GTK_STATE_FLAG_NORMAL, &color);
    gtk_fixed_put(GTK_FIXED(fixed), song_label, 210, 710);
    gtk_widget_set_name(song_label, "song-label");

    artist_label = gtk_label_new(artist_name_tmp);
    gtk_widget_override_color(artist_label, GTK_STATE_FLAG_NORMAL, &color);
    gtk_fixed_put(GTK_FIXED(fixed), artist_label, 210, 740);
    gtk_widget_set_name(artist_label, "artist-label");
    gtk_widget_hide(stop_button);
}

void toggle_stop_button() {
    if (is_playing) {
        play_music(song_name_tmp);
        gtk_widget_hide(play_button);
        gtk_widget_show(stop_button);
    } else {
        stop_music();
        gtk_widget_hide(stop_button);
        gtk_widget_show(play_button);
    }
}

void stop_song(GtkWidget *widget, gpointer data) {
    is_playing = FALSE;
    toggle_stop_button();

    // Store the elapsed time and progress in variables
    stored_elapsed_seconds_global = song_duration * progress;
    stored_progress_global = progress;

    // Reset progress and elapsed time variables
    progress = 0.0;
    elapsed_seconds = 0;

    // Update progress bar with stored progress value
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress_bar), stored_progress_global);

    // Update time label with stored elapsed time
    gchar *time_str = g_strdup_printf("%02d:%02d", stored_elapsed_seconds_global / 60, stored_elapsed_seconds_global % 60);
    gtk_label_set_text(GTK_LABEL(time_label), time_str);
    g_free(time_str);
}

void play_song(GtkWidget *widget, gpointer data) {
    if (!is_playing) {
        play_music();
        if (stored_elapsed_seconds_global >= song_duration) { // Reset progress and elapsed time if song has ended
            progress = 0.0;
            elapsed_seconds = 0;
            gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress_bar), progress);
            gchar *time_str = g_strdup_printf("%02d:%02d", 0, 0);
            gtk_label_set_text(GTK_LABEL(time_label), time_str);
            g_free(time_str);
        } else if (stored_elapsed_seconds_global > 0) { // Resume from stored progress and elapsed time
            progress = stored_progress_global;
            elapsed_seconds = stored_elapsed_seconds_global;

            // Update progress bar with stored progress value
            gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress_bar), progress);

            // Update time label with stored elapsed time
            gint minutes = elapsed_seconds / 60;
            gint seconds = elapsed_seconds % 60;
            gchar *time_str = g_strdup_printf("%02d:%02d", minutes, seconds);
            gtk_label_set_text(GTK_LABEL(time_label), time_str);
            g_free(time_str);
        }
        is_playing = TRUE;
    } else {
        is_playing = FALSE;
    }
    toggle_stop_button();
}

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
        gint seconds = elapsed_seconds % 60;
        gchar *time_str = g_strdup_printf("%02d:%02d", minutes, seconds);
        gtk_label_set_text(GTK_LABEL(time_label), time_str);
        g_free(time_str);

        // Stop playback at end of song
        if (elapsed_seconds >= song_duration) {
            is_playing = FALSE;
            toggle_stop_button();
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



