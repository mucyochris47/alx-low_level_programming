#include "3-calc.h"
#include <stdio.h>

/* Array of Operation Structs */
op_t ops[] = {
    {"+", op_add},
    {"-", op_sub},
    {"*", op_mul},
    {"/", op_div},
    {"%", op_mod},
    {NULL, NULL}
};

/* Function to Select Operation Function */
int (*get_op_func(char *s))(int, int)
{
    int i = 0;

    while (ops[i].op != NULL)
    {
        if (*(ops[i].op) == *s && s[1] == '\0')
            return ops[i].f;
        i++;
    }

    printf("Error\n");
    exit(99);
}

