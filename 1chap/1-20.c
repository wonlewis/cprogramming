#include <stdio.h>
#define TAB 5
int main()
{
    int i, c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            for (i = 0; i < TAB; ++i)
                putchar(' ');
        }
        else
            putchar(c);
    }
    return 0;
}