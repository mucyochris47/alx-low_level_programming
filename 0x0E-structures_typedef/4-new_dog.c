#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - Creates a new dog
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner of the dog
 *
 * Return: Pointer to the new dog_t structure, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *dog;
    size_t name_len, owner_len;

    dog = malloc(sizeof(dog_t));
    if (dog == NULL)
        return (NULL);

    name_len = strlen(name) + 1;
    owner_len = strlen(owner) + 1;

    dog->name = malloc(name_len);
    if (dog->name == NULL)
    {
        free(dog);
        return (NULL);
    }

    dog->owner = malloc(owner_len);
    if (dog->owner == NULL)
    {
        free(dog->name);
        free(dog);
        return (NULL);
    }

    strncpy(dog->name, name, name_len);
    strncpy(dog->owner, owner, owner_len);
    dog->age = age;

    return (dog);
}

