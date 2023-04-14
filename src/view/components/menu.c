//
// Created by ADMIN on 4/13/2023.
//

#include "menu.h"
#include "src/models/songs.h"
#include "src/models/playlist.h"
#include "src/view/main_view/mainboard_view.h"
GtkWidget *scrolled_window,*rect_area,*upload,*explore,*my_music,*logo,*explore_icon,*my_music_icon,*upload_icon;
GtkWidget *list;
GtkWidget *drawing_area_playlist,*circle_button_playlist,*box_circle_playlist;
GtkWidget *select;
GtkWidget *add;

int tab=0;
void select_click()
{
    printf("ok");
}
void on_draw_menu(GtkWidget *widget, cairo_t *cr, gpointer user_data);
gboolean on_draw_circle(GtkWidget *widget, cairo_t *cr, gpointer data) {
    // Lấy kích thước của DrawingArea
    gint width, height;
    gtk_widget_get_size_request(widget, &width, &height);

    // Tạo đường tròn
    cairo_arc(cr, width/2.0, height/2.0, 20.5, 0, 2 * G_PI);

    // Tô màu đường tròn
    cairo_set_source_rgb(cr, 217.0/255.0, 217.0/255.0, 217.0/255.0);
    cairo_fill(cr);

    // Vẽ dấu cộng
    cairo_set_source_rgb(cr, 112.0/255.0, 112.0/255.0, 112.0/255.0);
    cairo_move_to(cr, width/2.0 - 10, height/2.0);
    cairo_line_to(cr, width/2.0 + 10, height/2.0);
    cairo_move_to(cr, width/2.0, height/2.0 - 10);
    cairo_line_to(cr, width/2.0, height/2.0 + 10);
    cairo_stroke(cr);

    return TRUE;
}
void on_row_selected(GtkListBox *listbox, GtkListBoxRow *row, gpointer user_data)
{
    // Lấy vị trí của dòng được chọn
    gint index = gtk_list_box_row_get_index(row);
    g_print("Selected row: %d\n", index);
    play_music();
}
void remove_all_rows(GtkWidget *list_box) {
    GList *children, *iter;
    children = gtk_container_get_children(GTK_CONTAINER(list_box));
    for(iter = children; iter != NULL; iter = g_list_next(iter)) {
        gtk_widget_destroy(GTK_WIDGET(iter->data));
    }
    g_list_free(children);
}
void tab_explore()
{

    tab =1;
   // Xóa tất cả các phần tử trong GtkListBox
    gtk_container_foreach(GTK_CONTAINER(list), (GtkCallback)gtk_widget_destroy, NULL);

    GdkRGBA color1  ;
    gdk_rgba_parse(&color1, "white");

    // Thay đổi nội dung label
    gtk_label_set_text(GTK_LABEL(select), "Explorer");
    gtk_widget_override_color(select, GTK_STATE_NORMAL, &color1);

    // Lấy layout của label
    PangoLayout *layout = gtk_label_get_layout(GTK_LABEL(select));

    // Thay đổi kích thước và độ đậm của label
    PangoFontDescription *font_desc = pango_font_description_new();
    pango_font_description_set_weight(font_desc, PANGO_WEIGHT_BOLD);
    pango_font_description_set_size(font_desc, 24 * PANGO_SCALE);
    pango_layout_set_font_description(layout, font_desc);
    create_list_song(list);
    // Cập nhật lại giao diện của GtkListBox
    gtk_widget_show_all(list);
}
void tab_my_music()
{

    tab =2;
    // Xóa tất cả các phần tử trong GtkListBox
    gtk_container_foreach(GTK_CONTAINER(list), (GtkCallback)gtk_widget_destroy, NULL);

    GdkRGBA color1  ;
    gdk_rgba_parse(&color1, "white");

    // Thay đổi nội dung label
    gtk_label_set_text(GTK_LABEL(select), "My Music");
    gtk_widget_override_color(select, GTK_STATE_NORMAL, &color1);
    // Khởi tạo nút bỏ qua bài hát hiện tại
    GtkWidget *mymusic = gtk_button_new_with_label("+");
    gtk_fixed_put(GTK_FIXED(fixed), mymusic, 1220, 30);

    // Lấy layout của label
    PangoLayout *layout = gtk_label_get_layout(GTK_LABEL(select));

    // Thay đổi kích thước và độ đậm của label
    PangoFontDescription *font_desc = pango_font_description_new();
    pango_font_description_set_weight(font_desc, PANGO_WEIGHT_BOLD);
    pango_font_description_set_size(font_desc, 24 * PANGO_SCALE);
    pango_layout_set_font_description(layout, font_desc);
    my_music_create(list);
    // Cập nhật lại giao diện của GtkListBox
    gtk_widget_show_all(list);
}

void tab_playlist()
{

    tab= 3;
    // Xóa tất cả các phần tử trong GtkListBox
    gtk_container_foreach(GTK_CONTAINER(list), (GtkCallback)gtk_widget_destroy, NULL);

    GdkRGBA color1  ;
    gdk_rgba_parse(&color1, "white");

    // Thay đổi nội dung label
    gtk_label_set_text(GTK_LABEL(select), "Playlist");
    gtk_widget_override_color(select, GTK_STATE_NORMAL, &color1);

    // Lấy layout của label
    PangoLayout *layout = gtk_label_get_layout(GTK_LABEL(select));

    // Thay đổi kích thước và độ đậm của label
    PangoFontDescription *font_desc = pango_font_description_new();
    pango_font_description_set_weight(font_desc, PANGO_WEIGHT_BOLD);
    pango_font_description_set_size(font_desc, 24 * PANGO_SCALE);
    pango_layout_set_font_description(layout, font_desc);


    create_playlist(list);
    // Cập nhật lại giao diện của GtkListBox
    gtk_widget_show_all(list);

}
void menu_show()
{

    // Tạo một hình chữ nhật để chứa toàn bộ Widget
    rect_area = gtk_drawing_area_new();
    // Set size và vị trí cho hình chữ nhật
    gtk_widget_set_size_request(rect_area,300 , 680);
    gtk_fixed_put(GTK_FIXED(fixed), rect_area, 0, 0);
    // bắt đầu vẽ hình chữ nhật
    g_signal_connect(rect_area, "draw", G_CALLBACK(on_draw_menu), NULL);

    // Khởi tạo nút Explore
    explore = gtk_button_new_with_label("Explore");
    gtk_fixed_put(GTK_FIXED(fixed), explore, 0, 170);
    gtk_widget_set_size_request(explore, 300, 50);
    gtk_button_set_relief(GTK_BUTTON(explore), GTK_RELIEF_NONE);

    // Khởi tạo nút My Music
    my_music = gtk_button_new_with_label("My music");
    gtk_fixed_put(GTK_FIXED(fixed), my_music, 0, 215);
    gtk_widget_set_size_request(my_music, 300, 50);
    gtk_button_set_relief(GTK_BUTTON(my_music), GTK_RELIEF_NONE);

    // Khởi tạo nút Upload
    upload = gtk_button_new_with_label("Playlist");
    gtk_fixed_put(GTK_FIXED(fixed), upload, 0, 260);
    gtk_widget_set_size_request(upload, 300, 50);
    gtk_button_set_relief(GTK_BUTTON(upload), GTK_RELIEF_NONE);

    // Add event clicked cho từng nút
    g_signal_connect(explore, "clicked", G_CALLBACK(tab_explore), NULL);
    g_signal_connect(my_music, "clicked", G_CALLBACK(tab_my_music), NULL);
    g_signal_connect(upload, "clicked", G_CALLBACK(tab_playlist), NULL);


    // Khởi tạo Logo của app ở đỉnh của selection menu
    logo = gtk_image_new_from_file("assets/header_logo.png");
    gtk_fixed_put(GTK_FIXED(fixed), logo, 20, 0);

    // Thêm các icon của từng mục
    explore_icon = gtk_image_new_from_file("assets/explore_icon.png");
    gtk_fixed_put(GTK_FIXED(fixed), explore_icon, 65, 184);
    my_music_icon = gtk_image_new_from_file("assets/my_music_icon.png");
    gtk_fixed_put(GTK_FIXED(fixed), my_music_icon, 65, 229);
    upload_icon = gtk_image_new_from_file("assets/upload_icon.png");
    gtk_fixed_put(GTK_FIXED(fixed), upload_icon, 65, 274);

    //Load file css
    GtkCssProvider *provider = gtk_css_provider_new();
    GtkStyleContext *explore_context,
            *my_music_context,
            *upload_context;
    GError *error = NULL;

    gtk_css_provider_load_from_path(provider, "src\\view\\properties\\selection_menu.css", &error);
    if (error)
    {
        g_warning ("%s", error->message);
        g_clear_error (&error);
    }

    explore_context = gtk_widget_get_style_context(explore);
    my_music_context = gtk_widget_get_style_context(my_music);
    upload_context = gtk_widget_get_style_context(upload);

    gtk_style_context_add_provider(explore_context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    gtk_style_context_add_provider(my_music_context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    gtk_style_context_add_provider(upload_context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);



    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_widget_set_size_request(scrolled_window, 1020, 510);
    gtk_fixed_put(GTK_FIXED(fixed), scrolled_window, 400, 170);

    list = gtk_list_box_new();

    gtk_container_add(GTK_CONTAINER(scrolled_window), list);
    select = gtk_label_new("Explore");
    gtk_fixed_put(GTK_FIXED(fixed), select, 410, 100);
    g_signal_connect(select, "button-press-event", G_CALLBACK(select_click), NULL);

    // Khởi tạo nút log out
    add = gtk_button_new_with_label("");
    gtk_fixed_put(GTK_FIXED(fixed), add, 600, 100);
    gtk_button_set_relief(GTK_BUTTON(add), GTK_RELIEF_NONE);
    GdkPixbuf *pixbuf_skip1 = gdk_pixbuf_new_from_file("assets/add_logo.svg", NULL);
    GtkImage *image_skip1 = gtk_image_new_from_pixbuf(pixbuf_skip1);
    gtk_button_set_image(GTK_BUTTON(add), GTK_WIDGET(image_skip1));
    gtk_widget_show(image_skip1);
    gtk_widget_show(add);
    tab_explore();

    GdkColor color;
    gdk_color_parse("#1e1f1f", &color);
    gtk_widget_modify_bg(list, GTK_STATE_NORMAL, &color);
    // Đăng ký callback cho sự kiện row-selected
    g_signal_connect(list, "row-selected", G_CALLBACK(on_row_selected), NULL);

}

void on_draw_menu(GtkWidget *widget, cairo_t *cr, gpointer user_data) {

    // Chỉnh màu cho background của hcn
    cairo_set_source_rgb(cr, 41/255.0, 40/255.0, 40/255.0); // fill color

    // Bắt đầu vẽ hcn
    cairo_rectangle(cr, 0, 0, 300, 680);
    cairo_fill_preserve(cr); // fill the rectangle
    cairo_stroke(cr); // draw the border
}