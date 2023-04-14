//
// Created by ADMIN on 4/8/2023.
//

#include "songs.h"
#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#include <string.h>
#pragma comment(lib, "winmm.lib")
#include "src/config/database_config.h"
#include "src/models/infor.h"

int so_bai_hat = 0;
char music[PATH_MAX];

Song songs[PATH_MAX];
int explorer();
void create_list_song(GtkWidget *list) {

    explorer();

    for (gint i = 0; i < so_bai_hat; i++) {
        GtkWidget *hbox = gtk_hbox_new(FALSE, 15);
        GtkWidget *image = gtk_image_new_from_file(songs[i].image_path);
        GtkWidget *vbox = gtk_vbox_new(FALSE, 0);
        GtkWidget *song_title_label = gtk_label_new(songs[i].song_title);
        GtkWidget *artist_label = gtk_label_new(songs[i].artist);
        GtkWidget *time = gtk_label_new(songs[i].times);
        GdkColor color;
        gdk_color_parse("white", &color);
        gtk_widget_modify_fg(GTK_WIDGET(song_title_label), GTK_STATE_NORMAL, &color);
        gtk_widget_modify_fg(GTK_WIDGET(artist_label), GTK_STATE_NORMAL, &color);
        gtk_widget_modify_fg(GTK_WIDGET(time), GTK_STATE_NORMAL, &color);
        gtk_box_pack_start(GTK_BOX(hbox), image, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(vbox), song_title_label, FALSE,  FALSE, 0);
        gtk_widget_set_halign(song_title_label, GTK_ALIGN_START);
        gtk_box_pack_start(GTK_BOX(vbox), artist_label, FALSE,  FALSE, 0);
        gtk_widget_set_halign(artist_label, GTK_ALIGN_START);

        gtk_box_pack_start(GTK_BOX(hbox), vbox, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(hbox), time, TRUE,TRUE, 0);
        gtk_widget_set_halign(time, GTK_ALIGN_END); // căn lề phải
        gtk_widget_set_margin_end(time, 200); // thêm lề phải 200px
        gtk_list_box_insert(GTK_LIST_BOX(list), hbox, -1);

    }
}
int explorer()
{
    sqlite3 *db;
    sqlite3_stmt *stmt;

    // Mở kết nối đến database
    int rc = sqlite3_open(absolute_path, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Chuẩn bị câu lệnh truy vấn
    const char *sql = "SELECT song_name,artist_id FROM songs ORDER BY RANDOM() LIMIT 10;";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Can't prepare SQL statement: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    // Thực hiện truy vấn và thêm bài hát vào mảng songs
    so_bai_hat = 0;
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        songs[so_bai_hat].image_path = strdup("assets/tt.jpg");
        songs[so_bai_hat].song_title = strdup((const char*)sqlite3_column_text(stmt, 0));
        songs[so_bai_hat].artist = strdup((const char*)sqlite3_column_text(stmt, 1));
        songs[so_bai_hat].times = strdup("04:04");
        so_bai_hat++;
    }

    // Xử lý lỗi và giải phóng bộ nhớ
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Error in fetching data: %s\n", sqlite3_errmsg(db));
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);

}

void play_music(char song_name_play[])
{

    // Đóng tập tin nhạc
    mciSendString("close music", NULL, 0, NULL);

    strcpy(music,"open \"");
    strcat(music,absolute_project);
    strcat(music,"\\database\\sound\\");
    strcat(music,song_name_play);
    strcat(music,".mp3");
    strcat(music,"\" type mpegvideo alias music");

    printf("%s",music);
    // Mở tập tin nhạc
    mciSendString(music, NULL, 0, NULL);

    // Tua đến thời điểm 30 giây
    mciSendString("seek music to 00000", NULL, 0, NULL);

    // Tiếp tục phát nhạc
    mciSendString("play music", NULL, 0, NULL);

}
void stop_music()
{
    // Đóng tập tin nhạc
    mciSendString("close music", NULL, 0, NULL);

}
int qr_plalist();
int my_music_create(GtkWidget *list)
{
    qr_plalist();
    for (gint i = 0; i < so_bai_hat; i++) {
        GtkWidget *hbox = gtk_hbox_new(FALSE, 15);
        GtkWidget *image = gtk_image_new_from_file(songs[i].image_path);
        GtkWidget *vbox = gtk_vbox_new(FALSE, 0);
        GtkWidget *song_title_label = gtk_label_new(songs[i].song_title);
        GtkWidget *artist_label = gtk_label_new(songs[i].artist);
        GtkWidget *time = gtk_label_new(songs[i].times);
        GdkColor color;
        gdk_color_parse("white", &color);
        gtk_widget_modify_fg(GTK_WIDGET(song_title_label), GTK_STATE_NORMAL, &color);
        gtk_widget_modify_fg(GTK_WIDGET(artist_label), GTK_STATE_NORMAL, &color);
        gtk_widget_modify_fg(GTK_WIDGET(time), GTK_STATE_NORMAL, &color);
        gtk_box_pack_start(GTK_BOX(hbox), image, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(vbox), song_title_label, FALSE,  FALSE, 0);
        gtk_widget_set_halign(song_title_label, GTK_ALIGN_START);
        gtk_box_pack_start(GTK_BOX(vbox), artist_label, FALSE,  FALSE, 0);
        gtk_widget_set_halign(artist_label, GTK_ALIGN_START);

        gtk_box_pack_start(GTK_BOX(hbox), vbox, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(hbox), time, TRUE,TRUE, 0);
        gtk_widget_set_halign(time, GTK_ALIGN_END); // căn lề phải
        gtk_widget_set_margin_end(time, 200); // thêm lề phải 200px
        gtk_list_box_insert(GTK_LIST_BOX(list), hbox, 0);

    }
}
int qr_plalist()
{
    sqlite3 *db;
    char *errMsg = 0;
    int rc;

    rc = sqlite3_open(absolute_path, &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    char *sql = "SELECT song_name,artist_id FROM songs WHERE genre = ?;";
    sqlite3_stmt *stmt;

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    sqlite3_bind_text(stmt, 1, id_user_tmp, -1, SQLITE_STATIC);
    so_bai_hat=0;
    if (rc == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            songs[so_bai_hat].image_path = strdup("assets/tt.jpg");
            songs[so_bai_hat].song_title = strdup((const char*)sqlite3_column_text(stmt, 0));
            songs[so_bai_hat].artist = strdup((const char*)sqlite3_column_text(stmt, 1));
            songs[so_bai_hat].times = strdup("04:04");
            so_bai_hat++;
        }
        sqlite3_finalize(stmt);
    } else {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_close(db);
}
