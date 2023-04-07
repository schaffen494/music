#include "database_config.h"
char absolute_path[PATH_MAX];
char absolute_project[PATH_MAX];
void set_path()
{
    char *path = "database\\music.db";


    if (chdir("..") != 0) {
        // Change working directory to parent directory
        perror("chdir");
        exit(EXIT_FAILURE);
    }

    if (getcwd(absolute_path, sizeof(absolute_path)) == NULL) {
        perror("getcwd");
        exit(EXIT_FAILURE);
    }
    strcpy(absolute_project,absolute_path);
    strcat(absolute_path, "\\");
    strcat(absolute_path, path); // Append file name to directory path

    printf("Absolute path to music.db: %s\n", absolute_path);
}