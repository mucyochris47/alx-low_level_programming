#include <stdio.h>

int main() {
    int first = 1, second = 2, next;
    int count;

    printf("%d, %d", first, second); // Print the first two Fibonacci numbers

    for (count = 3; count <= 98; ++count) {
        next = first + second;
        printf(", %d", next);

        first = second;
        second = next;
    }

    printf("\n");

    return 0;
}
