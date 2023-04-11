//
// Created by ADMIN on 4/11/2023.
//

#ifndef C_CONTENT_H
#define C_CONTENT_H

void content(GtkWidget *fixed)
{
    GtkWidget *scrolled_window;
    GtkWidget *music_list;
    GtkWidget *list_item;
    gchar *music_titles[10] = {"Song 1", "Song 2", "Song 3", "Song 4", "Song 5",
                               "Song 6", "Song 7", "Song 8", "Song 9", "Song 10"};


    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
    gtk_widget_set_size_request(scrolled_window, 1200, 510);
    music_list = gtk_list_box_new();

    for (int i = 0; i < 10; i++) {
        list_item = gtk_label_new(music_titles[i]);
        gtk_container_add(GTK_CONTAINER(music_list), list_item);
    }

    gtk_container_add(GTK_CONTAINER(scrolled_window), music_list);
    //gtk_container_add(GTK_CONTAINER(fixed),scrolled_window);
    gtk_fixed_put(GTK_FIXED(fixed), scrolled_window, 290, 140);


}
#endif //C_CONTENT_H
