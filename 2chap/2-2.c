#include <stdio.h>
#define MAXLINE 10000

int main()
{
    int i;
    int lim = 10;
    char c, s[MAXLINE];

    for (i = 0; i < lim - 1; ++i)
    {
        if ((c = getchar()) != '\n')
        {
            if (c != EOF)
                s[i] = c;
        }
    }

    printf("%s", s);
}