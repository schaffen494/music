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
Song song[PATH_MAX];
Song found[PATH_MAX];
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
int qr_playlist();
int my_music_create(GtkWidget *list)
{
    qr_playlist();
    for (gint i = 0; i < so_bai_hat; i++) {
        GtkWidget *hbox = gtk_hbox_new(FALSE, 15);
        GtkWidget *image = gtk_image_new_from_file(song[i].image_path);
        GtkWidget *vbox = gtk_vbox_new(FALSE, 0);
        GtkWidget *song_title_label = gtk_label_new(song[i].song_title);
        GtkWidget *artist_label = gtk_label_new(song[i].artist);
        GtkWidget *time = gtk_label_new(song[i].times);
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
int qr_playlist()
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

    char *sql = "SELECT song_name,artist_id FROM songs WHERE user = ?;";
    sqlite3_stmt *stmt;

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    sqlite3_bind_text(stmt, 1, id_user_tmp, -1, SQLITE_STATIC);
    so_bai_hat=0;
    if (rc == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            song[so_bai_hat].image_path = strdup("assets/tt.jpg");
            song[so_bai_hat].song_title = strdup((const char*)sqlite3_column_text(stmt, 0));
            song[so_bai_hat].artist = strdup((const char*)sqlite3_column_text(stmt, 1));
            song[so_bai_hat].times = strdup("04:04");
            so_bai_hat++;
        }
        sqlite3_finalize(stmt);
    } else {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_close(db);
}

int add_song(char name[],char artist[],char user[])
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    char *err_msg = 0;
    int rc;
    rc = sqlite3_open(absolute_path, &db);
    if (rc != SQLITE_OK) {
        printf("Can not access to database: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return ADD_FAIL;
    }
    //truy vấn account
    char* sql = "SELECT * FROM songs WHERE song_name = ? ";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        printf("Error: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return ADD_FAIL;
    }

    // Thiết lập giá trị tham số cho truy vấn
    sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);

    // Thực hiện truy vấn
    rc = sqlite3_step(stmt);

    //kiểm tra tài khoản đã tồn tại hay chưa
    if (rc == SQLITE_ROW)
    {
        sqlite3_finalize(stmt);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return ADD_FAIL;
    }
    else{

        // thêm account mới vào database
        char *insert_sql = sqlite3_mprintf("INSERT INTO songs (song_id,song_name,artist_id,user) VALUES ((SELECT COALESCE(MAX(song_id), 0) + 1 FROM songs),'%s', '%s',%s');",
                                           name, artist, user);
        rc = sqlite3_exec(db, insert_sql, 0, 0, &err_msg);
        if (rc != SQLITE_OK) {
            printf("SQL error: %s\n", err_msg);
            sqlite3_finalize(stmt);
            sqlite3_free(err_msg);
            sqlite3_close(db);
            return ADD_FAIL;
        } else{
            // đóng database
            sqlite3_finalize(stmt);
            sqlite3_free(err_msg);
            sqlite3_close(db);
            return ADD_OK;
        }
    }

}
static int callback(void *data, int argc, char **argv, char **azColName){
    int i;
    printf("%s: ", (const char*)data);
    for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}
int find_song(char name[]);
void create_list_found(GtkWidget *list,char name[])
{
    so_bai_hat=0;
    find_song(name);
    printf("ch");

    for (gint i = 0; i < so_bai_hat; i++) {
        GtkWidget *hbox = gtk_hbox_new(FALSE, 15);
        GtkWidget *image = gtk_image_new_from_file(found[i].image_path);
        GtkWidget *vbox = gtk_vbox_new(FALSE, 0);
        GtkWidget *song_title_label = gtk_label_new(found[i].song_title);
        GtkWidget *artist_label = gtk_label_new(found[i].artist);
        GtkWidget *time = gtk_label_new(found[i].times);
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
int find_song(char name[])
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    const char* data = "Callback function called";

    /* Open database */
    rc = sqlite3_open(absolute_path, &db);
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return(1);
    }

    /* Create SQL statement */
     // từ khóa cần tìm kiếm
    sql = "SELECT * FROM songs WHERE song_name LIKE '%";
    strcat(sql, name);
    strcat(sql, "%';");

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    /* Close database */
    sqlite3_close(db);
    return 0;
}
