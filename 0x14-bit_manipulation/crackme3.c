#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <password>\n", argv[0]);
        return 1;
    }

    // Placeholder for the actual password check
    const char *correct_password = "secret123"; // Replace with the actual password
    if (strcmp(argv[1], correct_password) == 0) {
        printf("Congratulations!\n");
    } else {
        printf("Wrong password!\n");
    }

    return 0;
}

