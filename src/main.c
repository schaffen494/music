#include <gtk/gtk.h>
#include "db/connectData.h"
#include "view/intro.h"

int main(int argc, char *argv[]) {
    // Khởi tạo GTK
    //gtk_init(&argc, &argv);

    if( set_account("miloo","12345")==SIGNUP_FAIL)
    {
        printf("Account existed!");
    }
    return 0;
}