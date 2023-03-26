#include <gtk/gtk.h>
#include "view/sign_in.h"
#include "view/intro.h"
int main(int argc, char *argv[]) {
    // Khởi tạo GTK
    gtk_init(&argc, &argv);
    intro_show();
    return 0;
}