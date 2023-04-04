#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char username[50];
    char password[50];
};

void registerUser() {
    struct User newUser;

    // Ask user for username and password
    printf("Enter a username: ");
    scanf("%s", newUser.username);
    printf("Enter a password: ");
    scanf("%s", newUser.password);

    // Save user information to file
    FILE *fp;
    fp = fopen("users.txt", "a");
    fprintf(fp, "%s:%s\n", newUser.username, newUser.password);
    fclose(fp);

    printf("User registered successfully.\n");
}

int main() {
    registerUser();

    return 0;
}

