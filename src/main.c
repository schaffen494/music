#include <gtk/gtk.h>
#include "view/sign_in.h"

int main(int argc, char *argv[]) {
    // Khởi tạo GTK
    gtk_init(&argc, &argv);
    sign_in();
    return 0;
}
