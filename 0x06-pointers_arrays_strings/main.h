#ifndef MAIN_H
#define MAIN_H

int _putchar(char);
char *_strcat(char *, char *);
char *_strncat(char *dest, const char *src, int n);
char *_strncpy(char *dest, const char *src, int n);
int _strcmp(const char *s1, const char *s2);
void reverse_array(int *, int);
char *string_toupper(char *);
char *cap_string(char *);
char *leet(char *str);
char *rot13(char *);
void print_number(int);
void print_triangle(int);
void print_square(int size);
void print_buffer(char *b, int size);

#endif /* MAIN_H */
