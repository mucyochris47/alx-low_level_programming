#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 10  // Adjust the length as needed

int main(void) {
    char password[PASSWORD_LENGTH + 1]; // +1 for the null terminator
    int i, ascii;

    srand(time(0)); // Seed the random number generator

    for (i = 0; i < PASSWORD_LENGTH; i++) {
        // Generate random ASCII characters in the range we desire
        ascii = rand() % 94 + 33; // ASCII range from '!' to '~'
        password[i] = (char)ascii;
    }

    password[PASSWORD_LENGTH] = '\0'; // Null-terminate the string

    printf("%s\n", password);

    return 0;
}
