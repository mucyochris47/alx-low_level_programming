/* File: 9-times_table.c */

#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0
 */
void times_table(void)
{
    int a, b, product;

    for (a = 0; a <= 9; a++)
    {
        for (b = 0; b <= 9; b++)
        {
            product = a * b;
            if (b == 0)
            {
                _putchar('0');
            }
            else
            {
                _putchar(',');
                _putchar(' ');
                if (product >= 10)
                {
                    _putchar((product / 10) + '0');
                }
                else
                {
                    _putchar(' ');
                }
                _putchar((product % 10) + '0');
            }
        }
        _putchar('\n');
    }
}
