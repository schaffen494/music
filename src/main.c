#include <stdio.h>
#include <stdlib.h>
#include "query/db_signin.h"
#include "query/directProject.h"
#include "view/sample.h"

struct threeNum
{
    int n1, n2, n3;
};

int main(int argc, char *argv[]) {

    char user[] = "lap",pass[]="123456",direct[] = "C:/Users/ADMIN/CLionProjects/music/database/music.db";
    int *status;
    db_signin(user,pass,direct,status);
}
