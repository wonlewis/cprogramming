#include <stdio.h>
#include <string.h>
#define MAXLINES 5000 /* max #lines to be sorted */
#define ALLOCSIZE 10000
char *lineptr[MAXLINES]; /* pointers to text lines */
int readlines(char *lineptr[], int nlines, char *allocationPointer);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
/* sort input lines */
int main()
{
    int nlines; /* number of input lines read */
    char allocationBuffer[ALLOCSIZE];
    char *allocationPointer = allocationBuffer;
    if ((nlines = readlines(lineptr, MAXLINES, allocationPointer)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}
#define MAXLEN 1000 /* max length of any input line */
int getlineL(char s[], int lim);
char *alloc(int);
/* readlines:  read input lines */
int readlines(char *lineptr[], int maxlines, char *allocationPointer)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = getlineL(line, MAXLEN)) > 0)
        if ((nlines >= maxlines) || (p = alloc(len)) == NULL)
            return -1;
        else
        {
            line[len - 1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}
/* writelines:  write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* getline:  read a line into s, return length  */
int getlineL(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    }
    else
        return 0;
}