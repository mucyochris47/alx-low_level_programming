#include <stdio.h>

char *infinite_add(char *n1, char *n2, char *r, int size_r);

int main(void)
{
    char n1[] = "1234567890";
    char n2[] = "1";
    char r[100];

    char n3[] = "99999999999999999999999999999999999999999999999999";
    char n4[] = "1";
    char r2[10];

    char n5[] = "99999999999999999999999999999999999999999999999999";
    char n6[] = "1";
    char r3[11];

    char *res;

    res = infinite_add(n1, n2, r, 100);
    if (!res)
    {
        printf("Error: Buffer overflow\n");
        return (1);
    }
    printf("%s + %s = %s\n", n1, n2, r);

    res = infinite_add(n3, n4, r2, 10);
    if (!res)
    {
        printf("Error: Buffer overflow\n");
        return (1);
    }
    printf("%s + %s = %s\n", n3, n4, r2);

    res = infinite_add(n5, n6, r3, 11);
    if (!res)
    {
        printf("Error: Buffer overflow\n");
        return (1);
    }
    printf("%s + %s = %s\n", n5, n6, r3);

    return (0);
}
