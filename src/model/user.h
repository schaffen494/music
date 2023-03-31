#ifndef MUSIC_USER_H
#define MUSIC_USER_H

typedef struct {
    int user_id;
    char user_name[50];
    char password[50];
    float balance;
    int premium;
} User;
#endif //MUSIC_USER_H
