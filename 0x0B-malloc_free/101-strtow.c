#include <stdlib.h>

/* Helper function to get the number of words in a string */
int count_words(char *str)
{
    int count = 0;
    int in_word = 0; /* Flag to track if we are inside a word */

    while (*str)
    {
        if (*str == ' ')
            in_word = 0; /* If space, not in a word */
        else if (in_word == 0)
        {
            in_word = 1; /* Found start of a new word */
            count++;     /* Increment word count */
        }
        str++;
    }

    return count;
}

/* Helper function to free memory if allocation fails during word allocation */
void free_words(char **words)
{
    int i = 0;
    while (words[i])
    {
        free(words[i]);
        i++;
    }
    free(words);
}

/* Main function to split the string into words */
char **strtow(char *str)
{
    char **words;
    int word_count, i = 0;
    int start, end;

    if (str == NULL || *str == '\0')
        return NULL;

    word_count = count_words(str);

    words = malloc(sizeof(char *) * (word_count + 1)); /* Allocate array of char pointers */

    if (words == NULL)
        return NULL;

    while (*str)
    {
        while (*str == ' ' && *str != '\0') /* Skip leading spaces */
            str++;

        if (*str == '\0')
            break;

        start = i; /* Start of current word */

        while (*str != ' ' && *str != '\0') /* Find end of word */
        {
            str++;
            i++;
        }

        end = i; /* End of current word */

        words[start] = malloc(sizeof(char) * (end - start + 1)); /* Allocate memory for word */

        if (words[start] == NULL) /* Check for allocation failure */
        {
            free_words(words); /* Free previously allocated memory */
            return NULL;
        }

        /* Copy word from str to words[start] */
        for (i = start, str -= (end - start); i < end; i++, str++)
            words[start][i - start] = *str;

        words[start][i - start] = '\0'; /* Null-terminate the word */
    }

    words[word_count] = NULL; /* Last element of array is NULL as required */

    return words;
}

