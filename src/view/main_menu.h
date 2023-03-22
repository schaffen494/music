//
// Created by Nhat on 3/22/2023.
//

#ifndef MUSIC_MAIN_MENU_H
#define MUSIC_MAIN_MENU_H
#include <gtk/gtk.h>

extern GtkWidget *window,
                 *main_box,
                 *main_menu_vbox,
                 *main_menu_discover_label,
                 *main_menu_follow_label,
                 *main_music_my_music_label,
                 *main_menu_upload_label;

// Khởi tạo các widgets trong main menu
void main_menu_init()
{
    // Tạo hộp đựng các widget
    main_menu_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(main_box), main_menu_vbox);

    // Tạo nhãn discover
    main_menu_discover_label = gtk_label_new("Discover");
    gtk_box_pack_start(GTK_BOX(main_menu_vbox), main_menu_discover_label, FALSE, FALSE, 0);

    // Tạo nhãn follow
    main_menu_follow_label = gtk_label_new("Follow");
    gtk_box_pack_start(GTK_BOX(main_menu_vbox), main_menu_follow_label, FALSE, FALSE, 0);

    // Tạo nhãn my music
    main_music_my_music_label = gtk_label_new("My music");
    gtk_box_pack_start(GTK_BOX(main_menu_vbox), main_music_my_music_label, FALSE, FALSE, 0);

    // Tạo nhãn upload
    main_menu_upload_label = gtk_label_new("Upload");
    gtk_box_pack_start(GTK_BOX(main_menu_vbox), main_menu_upload_label, FALSE, FALSE, 0);
}



#endif //MUSIC_MAIN_MENU_H
