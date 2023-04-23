//
// Created by ADMIN on 4/17/2023.
//

#include "playlist.h"
#include "src/config/database_config.h"
#include "src/control/sign_in_control.h"
#include "src/view/main_board_view.h"
int so_playlist;
Playlist playlist[PATH_MAX];

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

    char *sql = "SELECT playlist_name FROM playlist WHERE user_id = ?;";
    sqlite3_stmt *stmt;

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    sqlite3_bind_text(stmt, 1, user_id, -1, SQLITE_STATIC);
    so_playlist=0;
    if (rc == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            playlist[so_playlist].image_path = strdup("assets/tt.jpg");
            playlist[so_playlist].playlist_title = strdup((const char*)sqlite3_column_text(stmt, 0));
            so_playlist++;
        }
        sqlite3_finalize(stmt);
    } else {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_close(db);
}

void create_playlist(GtkWidget *list_tmp)
{
    qr_playlist();

    for (gint i = 0; i < so_playlist; i++) {
        GtkWidget *hbox = gtk_hbox_new(FALSE, 0);
        GtkWidget *image = gtk_image_new_from_file(playlist[i].image_path);
        GtkWidget *song_title_label = gtk_label_new(playlist[i].playlist_title);
        GtkWidget *time = gtk_label_new(playlist[i].quantity);
        GdkColor color;
        gdk_color_parse("white", &color);
        gtk_widget_modify_fg(GTK_WIDGET(song_title_label), GTK_STATE_NORMAL, &color);
        gtk_widget_modify_fg(GTK_WIDGET(time), GTK_STATE_NORMAL, &color);
        gtk_box_pack_start(GTK_BOX(hbox), image, FALSE, FALSE, 10);
        gtk_box_pack_start(GTK_BOX(hbox), song_title_label, FALSE, FALSE, 10);
        gtk_box_pack_start(GTK_BOX(hbox), time, TRUE,TRUE, 0);
        gtk_widget_set_halign(time, GTK_ALIGN_END); // căn lề phải
        gtk_widget_set_margin_end(time, 200);
        gtk_list_box_insert(GTK_LIST_BOX(list_tmp), hbox, -1);
    }
}

int add_new_playlists(char name[])
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
    char* sql = "SELECT * FROM playlist WHERE playlist_name = ? ";
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
        char *insert_sql = sqlite3_mprintf("INSERT INTO playlist (playlist_id,playlist_name,user_id) VALUES ((SELECT COALESCE(MAX(playlist_id), 0) + 1 FROM playlist),'%s','%s');",
                                           name, user_id);
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

int add_new_song_to_playlist(char name_playlist[],char name_song[])
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

    // Truy vấn username và password từ bảng users
    const char* sql = "SELECT * FROM song_playlist WHERE playlist_id = ? AND song_id = ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        printf("Error: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return ADD_FAIL;
    }

    // Thiết lập giá trị tham số cho truy vấn
    sqlite3_bind_text(stmt, 1, name_playlist, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, name_song, -1, SQLITE_STATIC);

    // Thực hiện truy vấn
    rc = sqlite3_step(stmt);
    printf("2");
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
        char *insert_sql = sqlite3_mprintf("INSERT INTO song_playlist (playlist_id,song_id) VALUES ('%s','%s');",
                                           name_playlist,name_song);
        rc = sqlite3_exec(db, insert_sql, 0, 0, &err_msg);
        if (rc != SQLITE_OK) {
            printf("SQL error2: %s\n", err_msg);
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

int remove_song_out_playlist(char name_playlist[],char name_song[])
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
        return DELETE_FAIL;
    }

    // Truy vấn username và password từ bảng users
    const char* sql = "SELECT * FROM song_playlist WHERE playlist_id = ? AND song_id = ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        printf("Error: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return DELETE_FAIL;
    }

    // Thiết lập giá trị tham số cho truy vấn
    sqlite3_bind_text(stmt, 1, name_playlist, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, name_song, -1, SQLITE_STATIC);

    // Thực hiện truy vấn
    rc = sqlite3_step(stmt);
    printf("2");
    //kiểm tra tài khoản đã tồn tại hay chưa
    if (rc != SQLITE_ROW)
    {
        sqlite3_finalize(stmt);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return DELETE_FAIL;
    }
    else{

        // XOÁ account mới vào database
        char *insert_sql = sqlite3_mprintf("DELETE FROM song_playlist WHERE playlist_id = '%s' AND song_id = '%s';",
                                           name_playlist,name_song);
        rc = sqlite3_exec(db, insert_sql, 0, 0, &err_msg);
        if (rc != SQLITE_OK) {
            printf("SQL error2: %s\n", err_msg);
            sqlite3_finalize(stmt);
            sqlite3_free(err_msg);
            sqlite3_close(db);
            return DELETE_FAIL;
        } else{

            //copy_file();
            // đóng database
            sqlite3_finalize(stmt);
            sqlite3_free(err_msg);
            sqlite3_close(db);
            return DELETE_OK;
        }
    }
}

int delete_playlist(char name_playlist[])
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
        return DELETE_FAIL;
    }

    // Truy vấn username và password từ bảng users
    const char* sql = "SELECT * FROM playlist WHERE playlist_name = ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        printf("Error: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return DELETE_FAIL;
    }

    // Thiết lập giá trị tham số cho truy vấn
    sqlite3_bind_text(stmt, 1, name_playlist, -1, SQLITE_STATIC);

    // Thực hiện truy vấn
    rc = sqlite3_step(stmt);
    printf("2");
    //kiểm tra tài khoản đã tồn tại hay chưa
    if (rc != SQLITE_ROW)
    {
        sqlite3_finalize(stmt);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return DELETE_FAIL;
    }
    else{

        // XOÁ account mới vào database
        char *insert_sql = sqlite3_mprintf("DELETE FROM playlist WHERE playlist_name = '%s';",
                                           name_playlist);
        rc = sqlite3_exec(db, insert_sql, 0, 0, &err_msg);
        if (rc != SQLITE_OK) {
            printf("SQL error2: %s\n", err_msg);
            sqlite3_finalize(stmt);
            sqlite3_free(err_msg);
            sqlite3_close(db);
            return DELETE_FAIL;
        } else{

            //copy_file();
            // đóng database
            sqlite3_finalize(stmt);
            sqlite3_free(err_msg);
            sqlite3_close(db);
            return DELETE_OK;
        }
    }
}
