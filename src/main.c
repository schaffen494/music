#include <gtk/gtk.h>
#include "view/intro.h"

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    intro_show();
    return 0;
}
