//
// Created by ASUS on 4/3/2023.
//
#include "musicBar.h"

GtkWidget *play_button, *stop_button, *back_button, *skip_button, *sound_label, *progress_bar, *time_label, *song_label, *artist_label;
gboolean is_playing = 0;
gdouble progress = 0.0;
gint elapsed_seconds = 0;
gint song_duration = 300; // in seconds
gdouble stored_progress_global = 0.0;
gint stored_elapsed_seconds_global = 0;

void toggle_stop_button();
void play_song(GtkWidget *widget, gpointer data);
void stop_song(GtkWidget *widget, gpointer data);
void back_song(GtkWidget *widget, gpointer data);
void skip_song(GtkWidget *widget, gpointer data);
void on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data);
void draw_image(GtkWidget *widget, cairo_t *cr, gpointer data);
static void on_sound_value_changed(GtkWidget *widget, gpointer data);
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
    gtk_widget_show(image_play);

    // Khởi tạo nút dừng nhạc
    stop_button = gtk_button_new_with_label("");
    gtk_fixed_put(GTK_FIXED(fixed), stop_button, 714, 715);
    gtk_button_set_relief(GTK_BUTTON(stop_button), GTK_RELIEF_NONE);
    GdkPixbuf *pixbuf_stop = gdk_pixbuf_new_from_file("assets/stop_button.svg", NULL);
    GtkImage *image_stop = gtk_image_new_from_pixbuf(pixbuf_stop);
    gtk_button_set_image(GTK_BUTTON(stop_button), GTK_WIDGET(image_stop));
    gtk_widget_show(image_stop);

    // Khởi tạo nút quay lại bài hát trước đó
    back_button = gtk_button_new_with_label("");
    gtk_fixed_put(GTK_FIXED(fixed), back_button, 650, 715);
    gtk_button_set_relief(GTK_BUTTON(back_button), GTK_RELIEF_NONE);
    GdkPixbuf *pixbuf_back= gdk_pixbuf_new_from_file("assets/backward_button.svg", NULL);
    GtkImage *image_back= gtk_image_new_from_pixbuf(pixbuf_back);
    gtk_button_set_image(GTK_BUTTON(back_button), GTK_WIDGET(image_back));
    gtk_widget_show(image_back);

    // Khởi tạo nút bỏ qua bài hát hiện tại
    skip_button = gtk_button_new_with_label("");
    gtk_fixed_put(GTK_FIXED(fixed), skip_button, 775, 715);
    gtk_button_set_relief(GTK_BUTTON(skip_button), GTK_RELIEF_NONE);
    GdkPixbuf *pixbuf_skip = gdk_pixbuf_new_from_file("assets/forward_button.svg", NULL);
    GtkImage *image_skip = gtk_image_new_from_pixbuf(pixbuf_skip);
    gtk_button_set_image(GTK_BUTTON(skip_button), GTK_WIDGET(image_skip));
    gtk_widget_show(image_skip);

    // Kết nối buttons với callback của nó. Khi mà ấn vào button thì dữ liệu trả về sẽ là gì... (Đại loại là vậy)
    g_signal_connect(play_button, "clicked", G_CALLBACK(play_song), NULL);
    g_signal_connect(stop_button, "clicked", G_CALLBACK(stop_song), NULL);
    g_signal_connect(back_button, "clicked", G_CALLBACK(back_song), NULL);
    g_signal_connect(skip_button, "clicked", G_CALLBACK(skip_song), NULL);

    // Thêm các buttons vào một hình chữ nhật
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_pack_start(GTK_BOX(box), back_button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), stop_button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), play_button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), skip_button, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(fixed), box);

    // Khởi tạo widget cho việc chứa ảnh của bài hát
    GtkWidget *image = gtk_image_new_from_file("assets/OIP.jpg");
    gtk_widget_set_name(image, "song-poster");
    gtk_fixed_put(GTK_FIXED(fixed), image, 36, 687);
    // Khởi tạo thanh điều chỉnh âm thanh
    GtkAdjustment *adjustment = gtk_adjustment_new(50.0, 0.0, 100.0, 1.0, 10.0, 0.0);
    GtkWidget *scale = gtk_scale_new(GTK_ORIENTATION_HORIZONTAL, GTK_ADJUSTMENT(adjustment));
    gtk_widget_set_size_request(scale, 200, -1);
    gtk_fixed_put(GTK_FIXED(fixed), scale, 1280, 720);
    gtk_widget_set_hexpand(scale, TRUE);
    gtk_scale_set_draw_value(GTK_SCALE(scale), FALSE);

    // Tạo một cái label để hiển thị giá trị của âm thanh
    GtkWidget *label = gtk_label_new(NULL);
    gtk_fixed_put(GTK_FIXED(fixed), label, 1170, 725);
    gchar *label_text = g_strdup_printf("Sound: %.2f", gtk_range_get_value(GTK_RANGE(scale)));
    gtk_label_set_text(GTK_LABEL(label), label_text);
    g_free(label_text);
    // Add scale và label vào box
    gtk_box_pack_start(GTK_BOX(box), scale, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    // Khi tương tác bằng cách kéo thả thì giá trị sẽ thay đổi
    g_signal_connect(scale, "value-changed", G_CALLBACK(on_sound_value_changed), label);


    // Create progress bar
    progress_bar = gtk_progress_bar_new();
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress_bar), progress);
    gtk_widget_set_size_request(progress_bar, 560, 10);
    gtk_fixed_put(GTK_FIXED(fixed), progress_bar,450, 769);

    // Create time label
    time_label = gtk_label_new(NULL);
    gtk_label_set_text(GTK_LABEL(time_label), "00:00");
    gtk_fixed_put(GTK_FIXED(fixed), time_label,400, 765);
    // Hide stop button initially
    gtk_widget_hide(stop_button);
    // Update progress every 10ms
    g_timeout_add(10, update_progress_bar, NULL);

    // Tạo lable để chứ tên bài hát và tên nghệ sĩ
    song_label = gtk_label_new("Song Name");
    gtk_fixed_put(GTK_FIXED(fixed), song_label, 210, 710);
    gtk_widget_set_name(song_label, "song-label");

    artist_label = gtk_label_new("Artist Name");
    gtk_fixed_put(GTK_FIXED(fixed), artist_label, 210, 740);
    gtk_widget_set_name(artist_label, "artist-label");

    //Load file css
    GtkCssProvider *provider = gtk_css_provider_new();
    GdkDisplay *display = gdk_display_get_default ();
    GdkScreen *screen = gdk_display_get_default_screen (display);
    GError *error = NULL;

    gtk_css_provider_load_from_path(provider, "D:\\mystic_melody\\src\\properties\\musicBar.css", &error);
    if (error)
    {
        g_warning ("%s", error->message);
        g_clear_error (&error);
    }
    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
}

void toggle_stop_button() {
    if (is_playing) {
        gtk_widget_hide(play_button);
        gtk_widget_show(stop_button);
    } else {
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

void back_song(GtkWidget *widget, gpointer data) {
    g_print("Going back to previous song...\n");
}

void skip_song(GtkWidget *widget, gpointer data) {
    g_print("Skipping to next song...\n");
}

void on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {

    // Chỉnh màu cho background của hcn
    cairo_set_source_rgb(cr, 25/255.0, 25/255.0, 24/255.0);// fill color

    // Bắt đầu vẽ hcn
    cairo_rectangle(cr, 0, 0, 1500, 140);
    cairo_fill_preserve(cr); // fill the rectangle
}

static void on_sound_value_changed(GtkWidget *range, gpointer data) {
    // Lấy giá trị âm thanh hiện tại
    gdouble sound_value = gtk_range_get_value(range);

    // Update lable để lấy giá trị hiện tại của âm thanh
    gchar *label_text = g_strdup_printf("Sound: %.0f", sound_value);
    gtk_label_set_text(GTK_LABEL(data), label_text);
    g_free(label_text);
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



