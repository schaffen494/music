//
// Created by ADMIN on 3/26/2023.
//

#ifndef MUSIC_SIGN_IN_H
#define MUSIC_SIGN_IN_H
#include <gtk/gtk.h>

gboolean authenticate_user(const char *username, const char *password);
void signin_show();
#endif //MUSIC_SIGN_IN_H
