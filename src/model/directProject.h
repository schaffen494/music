#ifndef MUSIC_DIRECTPROJECT_H
#define MUSIC_DIRECTPROJECT_H
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

// format link
void remove_last_n_chars(char *str, int n) {
    int len = strlen(str);
    if (n >= len) {
        str[0] = '\0';
        return;
    }
    int i;
    for (i = 0; i < n; i++) {
        str[len - n + i] = '\0';
    }
}
void link_return(char * direct)
{
    char link[PATH_MAX];
    getcwd(link,PATH_MAX+1);
    remove_last_n_chars(link,17);
    strcpy(direct,link);
}

#endif //MUSIC_DIRECTPROJECT_H
