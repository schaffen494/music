//
// Created by ADMIN on 4/11/2023.
//

#ifndef C_TS_H
#define C_TS_H

#include <gtk/gtk.h>
void on_song_selected(GtkListBox *box, GtkListBoxRow *row, gpointer user_data) {
    g_print("Slection: %s\n", gtk_label_get_text(GTK_LABEL(gtk_bin_get_child(GTK_BIN(row)))));
}
void on_draw_content(GtkWidget *widget, cairo_t *cr, gpointer user_data);
void tst(GtkWidget *fixed)
{

    // Tạo một box chứa danh sách các bài hát
    GtkWidget *listbox = gtk_list_box_new();
    gtk_fixed_put(GTK_FIXED(fixed), listbox, 300, 145);

    // Tạo một bài hát và thêm nó vào danh sách
    GtkWidget *song1 = gtk_list_box_row_new();
    GtkWidget *hbox1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 250);
    GtkWidget *image1 = gtk_image_new_from_file("assets/tt.jpg");
    GtkWidget *vbox1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget *label1 = gtk_label_new("Bài hát 1");
    GtkWidget *label2 = gtk_label_new("Ca sĩ 1");
    GtkWidget *label3 = gtk_label_new("4:32");
    gtk_box_pack_start(GTK_BOX(vbox1), label1, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox1), label2, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hbox1), image1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox1), vbox1, TRUE, TRUE, 0);
    gtk_box_pack_end(GTK_BOX(hbox1), label3, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(song1), hbox1);
    gtk_container_add(GTK_CONTAINER(listbox), song1);

    // Tạo một bài hát khác và thêm nó vào danh sách
    GtkWidget *song2 = gtk_list_box_row_new();
    GtkWidget *hbox2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    GtkWidget *image2 = gtk_image_new_from_file("assets/tt.jpg");
    GtkWidget *vbox2 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget *label4 = gtk_label_new("Bài hát 2");
    GtkWidget *label5 = gtk_label_new("Ca sĩ 2");
    GtkWidget *label6 = gtk_label_new("3:48");
    gtk_box_pack_start(GTK_BOX(vbox2), label4, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox2), label5, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hbox2), image2, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox2), vbox2, TRUE, TRUE, 0);
    gtk_box_pack_end(GTK_BOX(hbox2), label6, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(song2), hbox2);
    gtk_container_add(GTK_CONTAINER(listbox), song2);

    // Thiết lập chế độ cuộn tự động cho danh sách bài hát
    GtkWidget *scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
    gtk_container_add(GTK_CONTAINER(scrolled_window), listbox);
    //gtk_container_add(GTK_CONTAINER(window), scrolled_window);
    gtk_fixed_put(GTK_FIXED(fixed), scrolled_window, 300, 145);

    // Thiết lập callback khi chọn một bài hát
    g_signal_connect(listbox, "row-selected", G_CALLBACK(on_song_selected), NULL);
  }
void on_draw_content(GtkWidget *widget, cairo_t *cr, gpointer user_data) {

    // Chỉnh màu cho background của hcn
    cairo_set_source_rgb(cr, 41/255.0, 40/255.0, 40/255.0); // fill color

    // Bắt đầu vẽ hcn
    cairo_rectangle(cr, 0, 0, 300, 680);
    cairo_fill_preserve(cr); // fill the rectangle
    cairo_stroke(cr); // draw the border
}
#endif //C_TS_H
