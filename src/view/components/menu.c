//
// Created by ADMIN on 4/13/2023.
//

#include "menu.h"
#include "src/models/songs.h"
#include "src/models/playlist.h"
#include "src/view/main_view/mainboard_view.h"
#include "src/view/components/musicbar.h"
#include "src/config/database_config.h"
#include "src/models/infor.h"
GtkWidget *scrolled_window,*rect_area,*upload,*explore,*my_music,*logo,*explore_icon,*my_music_icon,*upload_icon;
GtkWidget *post_song_window,*list;

GtkWidget *link_song,*art;
GtkWidget *select;
GtkWidget *add;
char song_name_add[PATH_MAX];
char song_name_tmp[PATH_MAX];
char artist_name_tmp[PATH_MAX];
int tab=0;
void select_click()
{
    printf("ok");
}
void on_draw_menu(GtkWidget *widget, cairo_t *cr, gpointer user_data);

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

void button_clicked(GtkWidget *widget, gpointer data)
{

    const char *name = gtk_entry_get_text(GTK_ENTRY(link_song));
    const char *artist = gtk_entry_get_text(GTK_ENTRY(art));
    if(add_song(name,artist,id_user_tmp)==ADD_OK);
    {
        const char *src_path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(data));
        const char dest_path[PATH_MAX];
        strcpy(dest_path,absolute_project);
        strcat(dest_path,"\\database\\sound\\");
        strcat(dest_path,name);
        strcat(dest_path,".mp3");
        copy_file(src_path, dest_path);
        gtk_widget_destroy(post_song_window);
    }


}

void add_click()
{
    if(tab ==1)
    {
        tab_explore();
    }
    if(tab ==2)
    {
        GtkWidget *grid, *filechooser, *button, *label;
        post_song_window= gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(post_song_window), "Copy MP3 File");
        gtk_window_set_default_size(GTK_WINDOW(post_song_window), 200, 100);
        GdkRGBA color;
        gdk_rgba_parse(&color, "#1f1f1e");
        gtk_widget_override_background_color(post_song_window, GTK_STATE_FLAG_NORMAL, &color);

        gtk_window_set_decorated(GTK_WINDOW(post_song_window), FALSE);
        gtk_window_set_position(GTK_WINDOW(post_song_window), GTK_WIN_POS_CENTER_ALWAYS);
        grid = gtk_grid_new();
        gtk_container_add(GTK_CONTAINER(post_song_window), grid);

        GdkRGBA color1;
        gdk_rgba_parse(&color1, "#ffffff");
        GtkWidget *link_song_label = gtk_label_new("Name of song");
        gtk_widget_override_color(link_song_label, GTK_STATE_FLAG_NORMAL, &color1);
        gtk_grid_attach(GTK_GRID(grid), link_song_label, 0, 0, 1, 1);
        link_song= gtk_entry_new();
        gtk_grid_attach(GTK_GRID(grid), link_song, 0, 1, 1, 1);

        GtkWidget *link_song_label1 = gtk_label_new("Artist");
        gtk_widget_override_color(link_song_label1, GTK_STATE_FLAG_NORMAL, &color1);
        gtk_grid_attach(GTK_GRID(grid), link_song_label1, 0, 2, 1, 1);
        art = gtk_entry_new();
        gtk_grid_attach(GTK_GRID(grid), art, 0, 3, 1, 1);
        filechooser = gtk_file_chooser_button_new("Select a File", GTK_FILE_CHOOSER_ACTION_OPEN);
        gtk_grid_attach(GTK_GRID(grid), filechooser, 0, 4, 1, 1);

        button = gtk_button_new_with_label("Add song");
        g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), filechooser);
        gtk_grid_attach(GTK_GRID(grid), button, 0, 5, 1, 1);

        label = gtk_label_new("");
        gtk_grid_attach(GTK_GRID(grid), label, 0, 6, 1, 1);
        //Load file css
        GtkCssProvider *provider = gtk_css_provider_new();
        GdkDisplay *display = gdk_display_get_default ();
        GdkScreen *screen = gdk_display_get_default_screen (display);
        GError *error = NULL;
        gtk_widget_show_all(post_song_window);
        gtk_main();
    }
    if(tab ==3)
    {

    }
}

void on_row_selected(GtkListBox *listbox, GtkListBoxRow *row, gpointer user_data)
{
    if(tab!=3)
    {
        // Lấy vị trí của dòng được chọn
        gint index = gtk_list_box_row_get_index(row);
        //g_print("Selected row: %d\n", index);
        //printf("%s",songs[index].song_title);


        strcpy(artist_name_tmp,songs[index].artist);
        strcpy(song_name_tmp,songs[index].song_title);
        gtk_label_set_text(song_label,song_name_tmp);
        gtk_label_set_text(artist_label,artist_name_tmp);

        char song_image[PATH_MAX];
        strcpy(song_image,"database\\avatar_songs\\");
        strcat(song_image,song_name_tmp);
        strcat(song_image,".jpg");
        gtk_image_set_from_file(image, song_image);
        play_music(song_name_tmp);
    }
    else
    {
        // Xóa tất cả các phần tử trong GtkListBox
        gtk_container_foreach(GTK_CONTAINER(list), (GtkCallback)gtk_widget_destroy, NULL);
        my_music_playlist(list);
        gtk_widget_show_all(list);
    }

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

    // Khởi tạo nút Playlist
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

    // Khởi tạo nút add
    add = gtk_button_new_with_label("");
    gtk_fixed_put(GTK_FIXED(fixed), add, 600, 100);
    gtk_button_set_relief(GTK_BUTTON(add), GTK_RELIEF_NONE);
    GdkPixbuf *pixbuf_skip1 = gdk_pixbuf_new_from_file("assets/add_logo.svg", NULL);
    GtkImage *image_skip1 = gtk_image_new_from_pixbuf(pixbuf_skip1);
    gtk_button_set_image(GTK_BUTTON(add), GTK_WIDGET(image_skip1));
    gtk_widget_show(image_skip1);
    gtk_widget_show(add);
    tab_explore();
    g_signal_connect(add, "clicked", G_CALLBACK(add_click), NULL);


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