#include <gtk/gtk.h>
#include "view/intro.h"
#include "view/sign_up.h"
#include "view/sign_in.h"
#include "db/connectData.h"
int main(int argc, char *argv[]) {

    // Khởi tạo GTK
    gtk_init(&argc, &argv);

    //gọi intro UI
    intro_show();
}