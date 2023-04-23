#include <gtk/gtk.h>
#include "src/config/database_config.h"
#include "src/view/intro_view.h"
#include "src/models/songs.h"
int main(int argc, char *argv[]) {

    //get link database and project
    set_path();

    //gtk initialize gtk
    gtk_init(&argc, &argv);

    //show intro window
    intro_show();
    //find_song("lap");
    return 0;
}

