//
// Created by ADMIN on 4/13/2023.
//

#include "playlist.h"
#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include "src/config/database_config.h"
#include "src/models/infor.h"
int dem =0;
typedef struct {
    gchar *image_path;
    gchar *playlist_title;
    gchar *quantity;
} Playlist;
int add_playlist();
Playlist playlist[PATH_MAX];
void create_playlist(GtkWidget *list)
{
    add_playlist();

    for (gint i = 0; i < dem; i++) {
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
        gtk_list_box_insert(GTK_LIST_BOX(list), hbox, -1);
    }
}
int add_playlist()
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
    sqlite3_bind_text(stmt, 1, id_user_tmp, -1, SQLITE_STATIC);
    dem=0;
    if (rc == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            playlist[dem].image_path = strdup("assets/tt.jpg");
            playlist[dem].playlist_title = strdup((const char*)sqlite3_column_text(stmt, 0));
            playlist[dem].quantity = strdup("3");
            dem++;
        }
        sqlite3_finalize(stmt);
    } else {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_close(db);
}