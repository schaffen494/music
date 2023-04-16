#include <gtk/gtk.h>
#include "src/config/database_config.h"
#include "src/view/main_view/intro_view.h"

int main(int argc, char *argv[]) {

    //get link database and project
    set_path();

    //gtk initialize gtk
    gtk_init(&argc, &argv);

    //show intro window
    intro_show();
    //main_board_show();
    return 0;
}

