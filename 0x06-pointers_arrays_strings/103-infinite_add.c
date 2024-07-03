#include <stdio.h>

/* Calculate lengths of n1 and n2 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int len1 = 0, len2 = 0, carry = 0, i = 0;

    while (n1[len1])
        len1++;
    while (n2[len2])
        len2++;

    if (len1 + 2 > size_r || len2 + 2 > size_r)
        return (0);

    len1--;
    len2--;
    r[size_r] = 0;

    for (i = size_r - 2; len1 >= 0 || len2 >= 0; --i, --len1, --len2)
    {
        r[i] = (len1 >= 0 ? n1[len1] - '0' : 0) + (len2 >= 0 ? n2[len2] - '0' : 0) + carry;
        carry = r[i] / 10;
        r[i] = r[i] % 10 + '0';
    }

    if (carry)
    {
        r[i] = carry + '0';
        return (&r[i]);
    }
    return (r + i + 1);
}
