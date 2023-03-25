#include <stdio.h>
#include <stdlib.h>
#include "model/songs.h"
#include "view/sample.h"



int main(int argc, char *argv[]) {

    char user[] = "lap",pass[]="123456",direct[] = "C:/Users/ADMIN/CLionProjects/music/database/music.db";
    int *status;
    delete_songs("noname","lap",direct,status);
}
