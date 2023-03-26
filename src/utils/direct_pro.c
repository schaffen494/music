//
// Created by ADMIN on 3/26/2023.
//

#include "direct_pro.h"

void remove_last_n_chars(char *str, int n) {
    int len = strlen(str);
    if (n >= len) { // Nếu n >= độ dài chuỗi, thì xóa toàn bộ chuỗi
        str[0] = '\0';
        return;
    }
    int i;
    for (i = 0; i < n; i++) { // Di chuyển con trỏ đến vị trí cuối - n
        str[len - n + i] = '\0';
    }
}
int getDirect(char *direct) {
    char link[PATH_MAX];
    getcwd(link, PATH_MAX + 1);
    remove_last_n_chars(link, 17);
    strcpy(direct, link);
    printf("%s",direct);
    return 0;
}