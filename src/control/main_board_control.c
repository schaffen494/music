//
// Created by ADMIN on 4/17/2023.
//

#include "main_board_control.h"
#include "src/view/sign_in_view.h"
#include "src/view/components/menu.h"
#include "src/view/components/music_bar.h"
#include "src/view/components/search_bar.h"
#include "src/view/main_board_view.h"
#include "src/view/components/upload.h"
#include "src/view/components/add_playlist.h"
#include "src/models/songs.h"
#include "src/models/playlist.h"
#include "src/view/main_board_view.h"
#include <string.h>
#include <sndfile.h>
#include "src/config/database_config.h"
#include "src/view/components/music_bar.h"
#include "src/control/sign_in_control.h"

#include <windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")
int tab_previous,tab_curr;
int upload_status,add_playlist_status;
static int stt = -1; // Khởi tạo giá trị ban đầu cho biến stt
GtkWidget *choose_playlist,*entry;

void refresh_tab()
{
    if(upload_status==1)
    {
        gtk_widget_destroy(upload_fixed);
        upload_status=0;
    }
    if(add_playlist_status==1)
    {
        gtk_widget_destroy(add_playlist_fixed);
        add_playlist_status=0;
    }

}

void stop_music()
{
    // Đóng tập tin nhạc
    mciSendString("close music", NULL, 0, NULL);
}

void play_music()
{

    gtk_toggle_button_set_active(button_play_pause,TRUE);
    is_playing = 1;
    // Đóng tập tin nhạc
    mciSendString("close music", NULL, 0, NULL);

    char music[PATH_MAX];
    strcpy(music,"open \"");
    strcat(music,absolute_project);
    strcat(music,"\\database\\sound\\");
    strcat(music,curr_song_name);
    strcat(music,".mp3");
    strcat(music,"\" type mpegvideo alias music");

    // Mở tập tin nhạc
    mciSendString(music, NULL, 0, NULL);

    char cont[PATH_MAX],pn[PATH_MAX];

    int tg = min*60+sec;
    tg=tg*1000;

    sprintf(cont, "%d", tg);

    strcpy(pn,"seek music to ");
    strcat(pn,cont);
    // Tua đến thời điểm
    mciSendString(pn, NULL, 0, NULL);

    // Tiếp tục phát nhạc
    mciSendString("play music", NULL, 0, NULL);

}

void selected(GtkListBox *listbox, GtkListBoxRow *row, gpointer user_data)
{

    if(tab_curr==1)
    {
        // Lấy vị trí của dòng được chọn
        const int stt = gtk_list_box_row_get_index(row);

        strcpy(curr_song_name,explorer[stt].song_title);
        strcpy(curr_artist_name,explorer[stt].artist);
        gtk_label_set_text(song_label,curr_song_name);
        gtk_label_set_text(artist_label,curr_artist_name);

        char song_image[PATH_MAX];
        strcpy(song_image,"database\\avatar_songs\\");
        strcat(song_image,curr_song_name);
        strcat(song_image,".jpg");
        gtk_image_set_from_file(image_song_avatar, song_image);
        progress=0;
        min =0;
        sec =0;
        play_music(curr_song_name);
    }
    if(tab_curr==2)
    {
        // Lấy vị trí của dòng được chọn
        gint index = gtk_list_box_row_get_index(row);
        int stt = (int)index;
        strcpy(curr_song_name,my_song[stt].song_title);
        strcpy(curr_artist_name,my_song[stt].artist);
        gtk_label_set_text(song_label,curr_song_name);
        gtk_label_set_text(artist_label,curr_artist_name);

        char song_image[PATH_MAX];
        strcpy(song_image,"database\\avatar_songs\\");
        strcat(song_image,curr_song_name);
        strcat(song_image,".jpg");
        gtk_image_set_from_file(image_song_avatar, song_image);
        progress=0;
        min =0;
        sec =0;
        play_music(curr_song_name);
    }
    if(tab_curr==3)
    {
        // Lấy vị trí của dòng được chọn
        gint index = gtk_list_box_row_get_index(row);
        int stt = (int)index;
        strcpy(curr_playlist_name,playlist[stt].playlist_title);

        GdkRGBA color_tab_label;
        gdk_rgba_parse(&color_tab_label, "white");

        // Thay đổi nội dung label
        gtk_label_set_text(GTK_LABEL(tab_label), "Songs in playlist");
        gtk_widget_override_color(tab_label, GTK_STATE_NORMAL, &color_tab_label);
        // Lấy layout của label
        PangoLayout *layout = gtk_label_get_layout(GTK_LABEL(tab_label));

        // Thay đổi kích thước và độ đậm của label
        PangoFontDescription *font_desc = pango_font_description_new();
        pango_font_description_set_weight(font_desc, PANGO_WEIGHT_BOLD);
        pango_font_description_set_size(font_desc, 24 * PANGO_SCALE);
        pango_layout_set_font_description(layout, font_desc);

        create_list_song_in_playlist(list);

        gtk_widget_show_all(scrolled_window);
    }

}

void search_song()
{
    tab_previous=tab_curr;
    tab_curr=0;

    GdkRGBA color_tab_label;
    gdk_rgba_parse(&color_tab_label, "white");
    // Thay đổi nội dung label
    gtk_label_set_text(GTK_LABEL(tab_label), "Song found");
    gtk_widget_override_color(tab_label, GTK_STATE_NORMAL, &color_tab_label);
    // Lấy layout của label
    PangoLayout *layout = gtk_label_get_layout(GTK_LABEL(tab_label));

    // Thay đổi kích thước và độ đậm của label
    PangoFontDescription *font_desc = pango_font_description_new();
    pango_font_description_set_weight(font_desc, PANGO_WEIGHT_BOLD);
    pango_font_description_set_size(font_desc, 24 * PANGO_SCALE);
    pango_layout_set_font_description(layout, font_desc);

    const char *name_of_song= gtk_entry_get_text(GTK_ENTRY(entry_search_bar));
    gtk_container_foreach(GTK_CONTAINER(list), (GtkCallback)gtk_widget_destroy, NULL);

    create_list_song(name_of_song);

    gtk_widget_show_all(scrolled_window);
}

void tab_explorer_click()
{
    tab_previous=tab_curr;
    tab_curr=1;
    refresh_tab();
    GdkRGBA color_tab_label;
    gdk_rgba_parse(&color_tab_label, "white");

    // Thay đổi nội dung label
    gtk_label_set_text(GTK_LABEL(tab_label), "Explorer");
    gtk_widget_override_color(tab_label, GTK_STATE_NORMAL, &color_tab_label);
    // Lấy layout của label
    PangoLayout *layout = gtk_label_get_layout(GTK_LABEL(tab_label));

    // Thay đổi kích thước và độ đậm của label
    PangoFontDescription *font_desc = pango_font_description_new();
    pango_font_description_set_weight(font_desc, PANGO_WEIGHT_BOLD);
    pango_font_description_set_size(font_desc, 24 * PANGO_SCALE);
    pango_layout_set_font_description(layout, font_desc);
    gtk_container_foreach(GTK_CONTAINER(list), (GtkCallback)gtk_widget_destroy, NULL);

    create_list_song_explorer(list);

    gtk_widget_show_all(scrolled_window);
}

void tab_my_music_click()
{
    tab_previous=tab_curr;
    tab_curr=2;
    refresh_tab();
    GdkRGBA color_tab_label;
    gdk_rgba_parse(&color_tab_label, "white");

    // Thay đổi nội dung label
    gtk_label_set_text(GTK_LABEL(tab_label), "My Music");
    gtk_widget_override_color(tab_label, GTK_STATE_NORMAL, &color_tab_label);
    // Lấy layout của label
    PangoLayout *layout = gtk_label_get_layout(GTK_LABEL(tab_label));

    // Thay đổi kích thước và độ đậm của label
    PangoFontDescription *font_desc = pango_font_description_new();
    pango_font_description_set_weight(font_desc, PANGO_WEIGHT_BOLD);
    pango_font_description_set_size(font_desc, 24 * PANGO_SCALE);
    pango_layout_set_font_description(layout, font_desc);
    gtk_container_foreach(GTK_CONTAINER(list), (GtkCallback)gtk_widget_destroy, NULL);

    create_list_song_my_music(list);

    gtk_widget_show_all(scrolled_window);

}

void tab_playlist_click()
{
    tab_previous=tab_curr;
    tab_curr=3;


    GdkRGBA color_tab_label;
    gdk_rgba_parse(&color_tab_label, "white");

    // Thay đổi nội dung label
    gtk_label_set_text(GTK_LABEL(tab_label), "Playlist");
    gtk_widget_override_color(tab_label, GTK_STATE_NORMAL, &color_tab_label);
    // Lấy layout của label
    PangoLayout *layout = gtk_label_get_layout(GTK_LABEL(tab_label));

    // Thay đổi kích thước và độ đậm của label
    PangoFontDescription *font_desc = pango_font_description_new();
    pango_font_description_set_weight(font_desc, PANGO_WEIGHT_BOLD);
    pango_font_description_set_size(font_desc, 24 * PANGO_SCALE);
    pango_layout_set_font_description(layout, font_desc);
    gtk_container_foreach(GTK_CONTAINER(list), (GtkCallback)gtk_widget_destroy, NULL);

    create_playlist(list);
    refresh_tab();
    gtk_widget_show_all(scrolled_window);
}

void upload()
{
    tab_previous=tab_curr;
    tab_curr=4;

    GdkRGBA color_tab_label;
    gdk_rgba_parse(&color_tab_label, "white");

    // Thay đổi nội dung label
    gtk_label_set_text(GTK_LABEL(tab_label), "Upload");
    gtk_widget_override_color(tab_label, GTK_STATE_NORMAL, &color_tab_label);
    // Lấy layout của label
    PangoLayout *layout = gtk_label_get_layout(GTK_LABEL(tab_label));

    // Thay đổi kích thước và độ đậm của label
    PangoFontDescription *font_desc = pango_font_description_new();
    pango_font_description_set_weight(font_desc, PANGO_WEIGHT_BOLD);
    pango_font_description_set_size(font_desc, 24 * PANGO_SCALE);
    pango_layout_set_font_description(layout, font_desc);
    gtk_container_foreach(GTK_CONTAINER(list), (GtkCallback)gtk_widget_destroy, NULL);
    refresh_tab();
    upload_show();
    gtk_widget_show_all(main_board_fixed);
    upload_status=1;
}

void add_playlist()
{
    tab_previous=tab_curr;
    tab_curr=5;
    GdkRGBA color_tab_label;
    gdk_rgba_parse(&color_tab_label, "white");

    // Thay đổi nội dung label
    gtk_label_set_text(GTK_LABEL(tab_label), "Add new playlist");
    gtk_widget_override_color(tab_label, GTK_STATE_NORMAL, &color_tab_label);
    // Lấy layout của label
    PangoLayout *layout = gtk_label_get_layout(GTK_LABEL(tab_label));

    // Thay đổi kích thước và độ đậm của label
    PangoFontDescription *font_desc = pango_font_description_new();
    pango_font_description_set_weight(font_desc, PANGO_WEIGHT_BOLD);
    pango_font_description_set_size(font_desc, 24 * PANGO_SCALE);
    pango_layout_set_font_description(layout, font_desc);
    // Xóa tất cả các phần tử trong GtkListBox
    gtk_container_foreach(GTK_CONTAINER(list), (GtkCallback)gtk_widget_destroy, NULL);
    refresh_tab();
    add_playlist_show();
    gtk_widget_show_all(main_board_fixed);
    add_playlist_status=1;
}

void logout_click()
{
    g_timeout_add_seconds(0, (GSourceFunc)gtk_widget_destroy, main_board_win);
    g_timeout_add_seconds(0, (GSourceFunc)sign_in_show, main_board_win);
}

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
}

void add_new_playlist()
{
    const char *playlist_name = gtk_entry_get_text(GTK_ENTRY(entry_name_playlist));

    if(add_new_playlists(playlist_name)==ADD_OK);
    {
        const char *src_path_image = gtk_file_chooser_get_filename(image_playlist);
        const char dest_path_image[PATH_MAX];

        strcpy(dest_path_image,absolute_project);
        strcat(dest_path_image,"database\\avatar_playlists\\");
        strcat(dest_path_image,playlist_name);
        strcat(dest_path_image,".jpg");

        copy_file(src_path_image, dest_path_image);
    }
}

void upload_new_song(GtkWidget *widget, gpointer data)
{
    const char *song_name = gtk_entry_get_text(GTK_ENTRY(entry_song_upload));
    const char *artist_name = gtk_entry_get_text(GTK_ENTRY(entry_artist_upload));
    if(add_song(song_name,artist_name,user_id)==ADD_OK);
    {
        const char *src_path_image = gtk_file_chooser_get_filename(image_file_upload);
        const char *src_path_audio = gtk_file_chooser_get_filename(music_file_upload);
        const char dest_path_image[PATH_MAX];
        const char dest_path_audio[PATH_MAX];

        strcpy(dest_path_image,absolute_project);
        strcat(dest_path_image,"database\\avatar_songs\\");
        strcat(dest_path_image,song_name);
        strcat(dest_path_image,".jpg");

        strcpy(dest_path_audio,absolute_project);
        strcat(dest_path_audio,"database\\sound\\");
        strcat(dest_path_audio,song_name);
        strcat(dest_path_audio,".mp3");

        copy_file(src_path_image, dest_path_image);
        copy_file(src_path_audio, dest_path_audio);

    }
}

void on_button_toggled(GtkToggleButton *toggle_button, gpointer data) {
    if (gtk_toggle_button_get_active(toggle_button)) {
        play_music();
        is_playing = TRUE;
        g_timeout_add(1000, update_progress_bar, data);
        // Change image to pause
        gtk_button_set_image(GTK_BUTTON(toggle_button), gtk_image_new_from_file("assets/stop_button.png"));
        // Add code to play song
    } else {
        stop_music();
        is_playing = FALSE;
        // Change image to play
        gtk_button_set_image(GTK_BUTTON(toggle_button), gtk_image_new_from_file("assets/play_button.svg"));
        // Add code to pause song
    }
}

void close_notify()
{
    gtk_widget_destroy(choose_playlist);
}

int add_song_playlist(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog;
    const char *name_playlist_add = gtk_entry_get_text(GTK_ENTRY(entry));

    if( strlen(name_playlist_add)==0 || strlen(curr_song_name)==0)
    {
        dialog = gtk_message_dialog_new(NULL,
                                        GTK_DIALOG_MODAL,
                                        GTK_MESSAGE_INFO,
                                        GTK_BUTTONS_OK,
                                        "Please enter song & playlist!");
        gtk_window_set_decorated(GTK_WINDOW(dialog), FALSE);
        gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
        gtk_dialog_run(GTK_DIALOG(dialog));
        g_timeout_add_seconds(0, (GSourceFunc)gtk_widget_destroy, dialog);
        gtk_entry_set_text(entry, "");
        return 0;
    }
    else
    {

        if (add_new_song_to_playlist(name_playlist_add,curr_song_name)==ADD_OK) {
            dialog = gtk_message_dialog_new(NULL,
                                            GTK_DIALOG_MODAL,
                                            GTK_MESSAGE_INFO,
                                            GTK_BUTTONS_OK,
                                            "Add thành công!");
            gtk_window_set_decorated(GTK_WINDOW(dialog), FALSE);
            gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
            gtk_dialog_run(GTK_DIALOG(dialog));
            gtk_entry_set_text(entry, "");

        } else {
            dialog = gtk_message_dialog_new(NULL,
                                            GTK_DIALOG_MODAL,
                                            GTK_MESSAGE_ERROR,
                                            GTK_BUTTONS_OK,
                                            "Add thất bại!");
            gtk_window_set_decorated(GTK_WINDOW(dialog), FALSE);
            gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
            gtk_dialog_run(GTK_DIALOG(dialog));
            g_timeout_add_seconds(0, (GSourceFunc)gtk_widget_destroy, dialog);
            gtk_entry_set_text(entry, "");
            return 0;
        }

    }
    /* Hủy hộp thoại */
    gtk_widget_destroy(dialog);
    gtk_widget_destroy(choose_playlist);
}

int remove_song_playlist(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog;
    const char *name_playlist_add = gtk_entry_get_text(GTK_ENTRY(entry));

    if( strlen(name_playlist_add)==0 || strlen(curr_song_name)==0)
    {
        dialog = gtk_message_dialog_new(NULL,
                                        GTK_DIALOG_MODAL,
                                        GTK_MESSAGE_INFO,
                                        GTK_BUTTONS_OK,
                                        "Please enter song & playlist!");
        gtk_window_set_decorated(GTK_WINDOW(dialog), FALSE);
        gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
        gtk_dialog_run(GTK_DIALOG(dialog));
        g_timeout_add_seconds(0, (GSourceFunc)gtk_widget_destroy, dialog);
        gtk_entry_set_text(entry, "");
        return 0;
    }
    else
    {

        if (remove_song_out_playlist(name_playlist_add,curr_song_name)==DELETE_OK) {
            dialog = gtk_message_dialog_new(NULL,
                                            GTK_DIALOG_MODAL,
                                            GTK_MESSAGE_INFO,
                                            GTK_BUTTONS_OK,
                                            "DELETE thành công!");
            gtk_window_set_decorated(GTK_WINDOW(dialog), FALSE);
            gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
            gtk_dialog_run(GTK_DIALOG(dialog));
            gtk_entry_set_text(entry, "");

        } else {
            dialog = gtk_message_dialog_new(NULL,
                                            GTK_DIALOG_MODAL,
                                            GTK_MESSAGE_ERROR,
                                            GTK_BUTTONS_OK,
                                            "DELETE thất bại!");
            gtk_window_set_decorated(GTK_WINDOW(dialog), FALSE);
            gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
            gtk_dialog_run(GTK_DIALOG(dialog));
            g_timeout_add_seconds(0, (GSourceFunc)gtk_widget_destroy, dialog);
            gtk_entry_set_text(entry, "");
            return 0;
        }

    }
    /* Hủy hộp thoại */
    gtk_widget_destroy(dialog);
    gtk_widget_destroy(choose_playlist);
}

int remove_playlist(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog;
    const char *name_playlist_add = gtk_entry_get_text(GTK_ENTRY(entry));

    if( strlen(name_playlist_add)==0 || strlen(curr_song_name)==0)
    {
        dialog = gtk_message_dialog_new(NULL,
                                        GTK_DIALOG_MODAL,
                                        GTK_MESSAGE_INFO,
                                        GTK_BUTTONS_OK,
                                        "Please enter song & playlist!");
        gtk_window_set_decorated(GTK_WINDOW(dialog), FALSE);
        gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
        gtk_dialog_run(GTK_DIALOG(dialog));
        g_timeout_add_seconds(0, (GSourceFunc)gtk_widget_destroy, dialog);
        gtk_entry_set_text(entry, "");
        return 0;
    }
    else
    {

        if (delete_playlist(name_playlist_add)==DELETE_OK) {
            dialog = gtk_message_dialog_new(NULL,
                                            GTK_DIALOG_MODAL,
                                            GTK_MESSAGE_INFO,
                                            GTK_BUTTONS_OK,
                                            "DELETE thành công!");
            gtk_window_set_decorated(GTK_WINDOW(dialog), FALSE);
            gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
            gtk_dialog_run(GTK_DIALOG(dialog));
            gtk_entry_set_text(entry, "");

        } else {
            dialog = gtk_message_dialog_new(NULL,
                                            GTK_DIALOG_MODAL,
                                            GTK_MESSAGE_ERROR,
                                            GTK_BUTTONS_OK,
                                            "DELETE thất bại!");
            gtk_window_set_decorated(GTK_WINDOW(dialog), FALSE);
            gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
            gtk_dialog_run(GTK_DIALOG(dialog));
            g_timeout_add_seconds(0, (GSourceFunc)gtk_widget_destroy, dialog);
            gtk_entry_set_text(entry, "");
            return 0;
        }

    }
    /* Hủy hộp thoại */
    gtk_widget_destroy(dialog);
    gtk_widget_destroy(choose_playlist);
}

void add_song_to_playlist()
{
    choose_playlist = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    // Tạo cửa sổ

    gtk_window_set_decorated(GTK_WINDOW(choose_playlist), TRUE);
    gtk_window_set_position(GTK_WINDOW(choose_playlist), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(choose_playlist), 300, 80);
    gtk_window_set_title(GTK_WINDOW(choose_playlist), "Mystic melody");

    GdkRGBA color_main_board;
    gdk_rgba_parse(&color_main_board, "#1f1f1e");
    gtk_widget_override_background_color(choose_playlist, GTK_STATE_FLAG_NORMAL, &color_main_board);

    //Tạo grid để chứa label, entry và các button
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_container_add(GTK_CONTAINER(choose_playlist), grid);

    GdkRGBA color_tab_label;
    gdk_rgba_parse(&color_tab_label, "white");

    // Tạo label "Tên playlist"
    GtkWidget *label = gtk_label_new("Name playlist:");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);
    gtk_widget_override_color(label, GTK_STATE_NORMAL, &color_tab_label);

    // Tạo entry để nhập tên playlist
    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry, 1, 0, 1, 1);


    GdkRGBA color_button;
    gdk_rgba_parse(&color_button, "#f78212");

    // Tạo button "Thêm"
    GtkWidget *button_add_song_to_playlist = gtk_button_new_with_label("Add");
    //g_signal_connect(button_add_song_to_playlist , "clicked", G_CALLBACK(add_playlist), entry);
    gtk_grid_attach(GTK_GRID(grid), button_add_song_to_playlist , 0, 1, 1, 1);
    gtk_button_set_relief(GTK_BUTTON(button_add_song_to_playlist), GTK_RELIEF_NONE);
    gtk_widget_override_color(button_add_song_to_playlist, GTK_STATE_NORMAL, &color_button);
    g_signal_connect(button_add_song_to_playlist, "clicked", G_CALLBACK(add_song_playlist), NULL);

    // Tạo button "Hủy"
    GtkWidget *button_cancel = gtk_button_new_with_label("Cancel");
    g_signal_connect(button_cancel, "clicked", G_CALLBACK(close_notify), choose_playlist);
    gtk_button_set_relief(GTK_BUTTON(button_cancel), GTK_RELIEF_NONE);
    gtk_grid_attach(GTK_GRID(grid), button_cancel, 1, 1, 1, 1);
    gtk_widget_override_color(button_cancel, GTK_STATE_NORMAL, &color_button);
    // Hiển thị window và các widget
    gtk_widget_show_all(choose_playlist);

    // Xử lý sự kiện đóng window
    g_signal_connect(choose_playlist, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Vào vòng lặp GTK
    gtk_main();
}

void remove_song_to_playlist()
{
    choose_playlist = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    // Tạo cửa sổ

    gtk_window_set_decorated(GTK_WINDOW(choose_playlist), TRUE);
    gtk_window_set_position(GTK_WINDOW(choose_playlist), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(choose_playlist), 300, 80);
    gtk_window_set_title(GTK_WINDOW(choose_playlist), "Mystic melody");

    GdkRGBA color_main_board;
    gdk_rgba_parse(&color_main_board, "#1f1f1e");
    gtk_widget_override_background_color(choose_playlist, GTK_STATE_FLAG_NORMAL, &color_main_board);

    //Tạo grid để chứa label, entry và các button
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_container_add(GTK_CONTAINER(choose_playlist), grid);

    GdkRGBA color_tab_label;
    gdk_rgba_parse(&color_tab_label, "white");

    // Tạo label "Tên playlist"
    GtkWidget *label = gtk_label_new("Name playlist:");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);
    gtk_widget_override_color(label, GTK_STATE_NORMAL, &color_tab_label);

    // Tạo entry để nhập tên playlist
    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry, 1, 0, 1, 1);


    GdkRGBA color_button;
    gdk_rgba_parse(&color_button, "#f78212");

    // Tạo button "Thêm"
    GtkWidget *button_add_song_to_playlist = gtk_button_new_with_label("Delete song");
    //g_signal_connect(button_add_song_to_playlist , "clicked", G_CALLBACK(add_playlist), entry);
    gtk_grid_attach(GTK_GRID(grid), button_add_song_to_playlist , 0, 1, 1, 1);
    gtk_button_set_relief(GTK_BUTTON(button_add_song_to_playlist), GTK_RELIEF_NONE);
    gtk_widget_override_color(button_add_song_to_playlist, GTK_STATE_NORMAL, &color_button);
    g_signal_connect(button_add_song_to_playlist, "clicked", G_CALLBACK(remove_song_playlist), NULL);

    // Tạo button "Hủy"
    GtkWidget *button_cancel = gtk_button_new_with_label("Delete playlist");
    g_signal_connect(button_cancel, "clicked", G_CALLBACK(remove_playlist), choose_playlist);
    gtk_button_set_relief(GTK_BUTTON(button_cancel), GTK_RELIEF_NONE);
    gtk_grid_attach(GTK_GRID(grid), button_cancel, 1, 1, 1, 1);
    gtk_widget_override_color(button_cancel, GTK_STATE_NORMAL, &color_button);
    // Hiển thị window và các widget
    gtk_widget_show_all(choose_playlist);

    // Xử lý sự kiện đóng window
    g_signal_connect(choose_playlist, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Vào vòng lặp GTK
    gtk_main();
}