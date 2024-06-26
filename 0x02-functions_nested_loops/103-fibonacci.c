#include <stdio.h>

int main() {
    long int first = 1, second = 2, next;
    long int sum = 0;

    while (first <= 4000000) {
        if (first % 2 == 0) {
            sum += first;
        }
        next = first + second;
        first = second;
        second = next;
    }

    printf("%ld\n", sum);

    return 0;
}
