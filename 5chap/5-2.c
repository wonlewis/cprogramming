#include <ctype.h>
#include <stdio.h>
#define BUFSIZE 100

int getch(void);
void ungetch(int);
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

int main()
{
    int n, i;
    float ans;
    float getfloat(float *);
    while (getfloat(&ans) != 0)
    {
        if (ans != ' ')
        {
            printf("\n%f", ans);
        }
    }
}

/* getint:  get next integer from input into *pn */
float getfloat(float *pn)
{
    int c, sign;
    int decimal = 0, powerCounter;
    float ans, power;
    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
    {
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getch();
        if (!isdigit(c))
        {
            ungetch(c); /* it is not a number */
            *pn = ' ';
            return c;
        }
    }

    for (*pn = 0; isdigit(c) || c == '.'; c = getch())
    {
        if (c == '.')
        {
            decimal = 1;
            power = 10.0f;
        }
        else if (decimal)
        {
            ans = (float)((c - '0') / power);
            *pn = *pn + ans;
            power *= 10;
            decimal++;
        }
        else
        {
            *pn = 10 * *pn + (c - '0');
        }
    }
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}