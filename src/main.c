#include <gtk/gtk.h>
#include "src/config/database_config.h"
#include "src/view/intro_view.h"
#include "src/components/selection_menu.h"
int main(int argc, char *argv[]) {

    //get link database
    set_path();
    //gtk initialize gtk
    gtk_init(&argc, &argv);

    //show intro window
    intro_show();
}
