#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 10  /* Adjust the length as needed */

char *generate_password(void) {
    static char password[PASSWORD_LENGTH + 1]; // Static for local persistence

    int i, ascii;

    srand(time(NULL)); // Seed the random number generator

    for (i = 0; i < PASSWORD_LENGTH; i++) {
        ascii = rand() % 94 + 33; // ASCII range from '!' to '~'
        password[i] = (char)ascii;
    }

    password[PASSWORD_LENGTH] = '\0'; // Null-terminate the string

    return password;
}

int main(void) {
    char *password = generate_password();

    printf("%s\n", password);

    return 0;
}
