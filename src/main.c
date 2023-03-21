#include <stdio.h>
#include <stdlib.h>
#include "model/sign_in.h"
#include "model/directProject.h"
int main(int argc, char *argv[]) {
    int k;
    char user[] = "lap",pass[]="123456",direct[] = "C:/Users/ADMIN/CLionProjects/music/database/music.db";
    sign_in(user,pass,direct);


}
