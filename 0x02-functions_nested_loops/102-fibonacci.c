#include <stdio.h>

int main() {
    int i;
    long long int first = 1, second = 2, next;

    printf("%lld, %lld", first, second); // Print the first two Fibonacci numbers

    for (i = 3; i <= 50; ++i) {
        next = first + second;
        printf(", %lld", next);
        first = second;
        second = next;
    }

    printf("\n");

    return 0;
}
