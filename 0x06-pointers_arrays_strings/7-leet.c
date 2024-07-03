#include "main.h"
#include <stdio.h>

int main(void)
{
    char str[] = "Hello, World!";

    printf("Original: %s\n", str);
    printf("Leetified: %s\n", leet(str));

    return 0;
}
