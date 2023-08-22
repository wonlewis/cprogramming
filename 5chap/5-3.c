#include <stdio.h>

void strcattest(char *s, char *t);

int main()
{
    char s[100] = "Hello there!";
    char t[] = " You are great!";
    strcattest(s, t);
    printf("%s", s);
}

void strcattest(char *s, char *t)
{
    while (*s++)
        ;
    *s--;
    while (*s++ = *t++)
        ;
}