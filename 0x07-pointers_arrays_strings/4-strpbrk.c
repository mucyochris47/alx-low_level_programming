#include "main.h"  /* Include any necessary headers here */
#include <string.h>
#include <stddef.h>

char *_strpbrk(char *s, char *accept) {
    while (*s != '\0') {
        if (strchr(accept, *s) != NULL) {
            return s;  /* Return pointer to the first occurrence in 's' */
        }
        s++;
    }
    return NULL;  /* Return NULL if no character in 'accept' is found in 's' */
}
