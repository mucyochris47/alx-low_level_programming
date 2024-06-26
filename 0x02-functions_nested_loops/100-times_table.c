#include "main.h"
#include <stdio.h>

/**
 * print_times_table - Prints the n times table, starting with 0.
 * @n: The number of times table to print (0 <= n <= 15)
 */
void print_times_table(int n) {
    int i, j; /* Declarations moved to the beginning of the function */

    /* Exit function if n is out of valid range */
    if (n < 0 || n > 15) {
        return;
    }

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            int result = i * j;
            if (j == 0) {
                printf("%d", result); /* First element of the row */
            } else {
                printf(", %d", result); /* Rest of the elements */
            }
        }
        printf("\n"); /* Move to the next row */
    }
}
