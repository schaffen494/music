//
// Created by ADMIN on 4/17/2023.
//

#include "songs.h"
#include "src/config/database_config.h"
#include "src/control/sign_in_control.h"
#include "src/view/main_board_view.h"
#include "src/control/main_board_control.h"
int so_bai_hat = 0;
Song found[PATH_MAX];
Song explorer[PATH_MAX];
Song my_song[PATH_MAX];
Song song_in_playlist[PATH_MAX];

char curr_playlist_name[PATH_MAX];
char curr_song_name[PATH_MAX],curr_artist_name[PATH_MAX];
int time_curr;

static int callback(void *data, int argc, char **argv, char **azColName){
    int i;
    printf("%s: ", (const char*)data);
    for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int find_song(char name_song[])
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc;

    // Mở kết nối với cơ sở dữ liệu
    rc = sqlite3_open(absolute_path, &db);
    if (rc != SQLITE_OK) {
        printf("Không thể mở kết nối với cơ sở dữ liệu.\n");
        return 1;
    }

    // Chuẩn bị câu lệnh truy vấn
    char* sql = "SELECT song_name,artist_id FROM songs WHERE song_name LIKE ? OR artist_id LIKE ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        printf("Lỗi khi chuẩn bị câu lệnh truy vấn.\n");
        return 1;
    }

    // Thiết lập tham số cho câu lệnh truy vấn
    rc = sqlite3_bind_text(stmt, 1, name_song, -1, SQLITE_TRANSIENT);
    if (rc != SQLITE_OK) {
        printf("Lỗi khi thiết lập tham số cho câu lệnh truy vấn.\n");
        return 1;
    }
    rc = sqlite3_bind_text(stmt, 2, name_song, -1, SQLITE_TRANSIENT);
    if (rc != SQLITE_OK) {
        printf("Lỗi khi thiết lập tham số cho câu lệnh truy vấn.\n");
        return 1;
    }
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        found[so_bai_hat].image_path = strdup("assets/tt.jpg");
        found[so_bai_hat].song_title = strdup((const char*)sqlite3_column_text(stmt, 0));
        found[so_bai_hat].artist = strdup((const char*)sqlite3_column_text(stmt, 1));
        found[so_bai_hat].times = strdup("04:04");
        so_bai_hat++;
    }
    if (rc != SQLITE_DONE) {
        printf("Lỗi khi thực thi câu lệnh truy vấn.\n");
        return 1;
    }

    // Giải phóng tài nguyên và đóng kết nối
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 0;
}

int find_my_song()
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
    sqlite3_bind_text(stmt, 1, user_id, -1, SQLITE_STATIC);
    so_bai_hat=0;
    if (rc == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            my_song[so_bai_hat].image_path = strdup("assets/tt.jpg");
            my_song[so_bai_hat].song_title = strdup((const char*)sqlite3_column_text(stmt, 0));
            my_song[so_bai_hat].artist = strdup((const char*)sqlite3_column_text(stmt, 1));
            my_song[so_bai_hat].times = strdup("04:04");
            so_bai_hat++;
        }
        sqlite3_finalize(stmt);
    } else {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_close(db);
}

int find_song_in_playlist()
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

    char *sql = "SELECT song_id,playlist_id FROM song_playlist WHERE playlist_id = ?;";
    sqlite3_stmt *stmt;

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    sqlite3_bind_text(stmt, 1, curr_playlist_name, -1, SQLITE_STATIC);
    so_bai_hat=0;
    if (rc == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            song_in_playlist[so_bai_hat].image_path = strdup("assets/tt.jpg");
            song_in_playlist[so_bai_hat].song_title = strdup((const char*)sqlite3_column_text(stmt, 0));
            song_in_playlist[so_bai_hat].artist = strdup((const char*)sqlite3_column_text(stmt, 1));
            song_in_playlist[so_bai_hat].times = strdup("04:04");
            so_bai_hat++;
        }
        sqlite3_finalize(stmt);
    } else {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_close(db);
}

int find_song_explorer()
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
        explorer[so_bai_hat].image_path = strdup("assets/tt.jpg");
        explorer[so_bai_hat].song_title = strdup((const char*)sqlite3_column_text(stmt, 0));
        explorer[so_bai_hat].artist = strdup((const char*)sqlite3_column_text(stmt, 1));
        explorer[so_bai_hat].times = strdup("04:04");
        so_bai_hat++;
    }

    // Xử lý lỗi và giải phóng bộ nhớ
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Error in fetching data: %s\n", sqlite3_errmsg(db));
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);

}

void create_list_song(char name_song[]) {

    so_bai_hat =0;
    find_song(name_song);
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

void create_list_song_explorer() {

    so_bai_hat =0;
    find_song_explorer();
    for (gint i = 0; i < so_bai_hat; i++) {
        GtkWidget *hbox = gtk_hbox_new(FALSE, 15);
        GtkWidget *image = gtk_image_new_from_file(explorer[i].image_path);
        GtkWidget *vbox = gtk_vbox_new(FALSE, 0);
        GtkWidget *song_title_label = gtk_label_new(explorer[i].song_title);
        GtkWidget *artist_label = gtk_label_new(explorer[i].artist);
        GtkWidget *time = gtk_label_new(explorer[i].times);
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

void create_list_song_my_music() {

    so_bai_hat =0;
    find_my_song();
    for (gint i = 0; i < so_bai_hat; i++) {
        GtkWidget *hbox = gtk_hbox_new(FALSE, 15);
        GtkWidget *image = gtk_image_new_from_file(my_song[i].image_path);
        GtkWidget *vbox = gtk_vbox_new(FALSE, 0);
        GtkWidget *song_title_label = gtk_label_new(my_song[i].song_title);
        GtkWidget *artist_label = gtk_label_new(my_song[i].artist);
        GtkWidget *time = gtk_label_new(my_song[i].times);
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

void create_list_song_in_playlist() {

    so_bai_hat =0;
    find_song_in_playlist();
    for (gint i = 0; i < so_bai_hat; i++) {
        GtkWidget *hbox = gtk_hbox_new(FALSE, 15);
        GtkWidget *image = gtk_image_new_from_file(song_in_playlist[i].image_path);
        GtkWidget *vbox = gtk_vbox_new(FALSE, 0);
        GtkWidget *song_title_label = gtk_label_new(song_in_playlist[i].song_title);
        GtkWidget *artist_label = gtk_label_new(song_in_playlist[i].artist);
        GtkWidget *time = gtk_label_new(song_in_playlist[i].times);
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
        char *insert_sql = sqlite3_mprintf("INSERT INTO songs (song_id,song_name,artist_id,user) VALUES ((SELECT COALESCE(MAX(song_id), 0) + 1 FROM songs),'%s','%s','%s');",
                                           name, artist, user);
        rc = sqlite3_exec(db, insert_sql, 0, 0, &err_msg);
        if (rc != SQLITE_OK) {
            printf("SQL error: %s\n", err_msg);
            sqlite3_finalize(stmt);
            sqlite3_free(err_msg);
            sqlite3_close(db);
            return ADD_FAIL;
        } else{
            //copy_file();
            // đóng database
            sqlite3_finalize(stmt);
            sqlite3_free(err_msg);
            sqlite3_close(db);
            return ADD_OK;
        }
    }
}

