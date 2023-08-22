#include <stdio.h>

int main()
{
    int c, i, j;
    int ndigit[1000];
    for (i = 0; i < 1000; i++)
    {
        ndigit[i] = 0;
    }
    i = 0;
    while (i < 1000 && ((c = getchar()) != EOF))
    {
        if (c == '\n' || c == '\t' || c == ' ')
        {
            i++;
        }
        else
        {
            ndigit[i]++;
        }
    }
    for (j = 0; j <= i; j++)
    {
        while (ndigit[j] > 0)
        {
            printf("|");
            ndigit[j]--;
        }
        printf("\n");
    }
}