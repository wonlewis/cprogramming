#include <stdio.h>
#include <ctype.h>
#define MAXLINE 5

int htoi(char s[]);
int loopAndConvert(char s[], int lengthOfString);
int convertToInt(char s);
int power(int input, int power);
int lengthOfString(char s[], int startingIndex);
int startingPoint(int x);
int checkFor0x(char s[]);
int mgetline(char line[], int lim);

int main()
{
    char s[MAXLINE], c;
    int i = 0;
    char j;
    int result;
    mgetline(s, MAXLINE);
    result = htoi(s);
    printf("The result of %s is %d", s, result);
    return 0;
}

int mgetline(char line[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;
}

int htoi(char s[])
{
    int check0x, startingIndex, lengthString, result;
    check0x = checkFor0x(s);
    startingIndex = startingPoint(check0x);
    lengthString = lengthOfString(s, startingIndex);
    result = loopAndConvert(s, lengthString);
    return result;
}

int loopAndConvert(char s[], int lengthOfString)
{
    int i;
    int counter = 1;
    int result = 0;
    int convertedS;
    for (i = lengthOfString - 1; i >= 0; i--)
    {
        convertedS = convertToInt(s[i]);
        result = result + power(convertedS, counter);
        counter++;
    }
    return result;
}

int convertToInt(char s)
{
    int i;
    if (isdigit(s))
        i = s - '0';
    if (isupper(s))
        i = s - 'A' + 10;
    if (islower(s))
        i = s - 'a' + 10;
    return i;
}

int power(int input, int power)
{
    int output = input;
    while (power > 1)
    {
        output = output * 16;
        power--;
    }
    return output;
}

int lengthOfString(char s[], int startingIndex)
{
    int i = 0;
    while (s[i] != '\n')
        i++;
    if (startingIndex == 2)
        return i - 2;
    return i;
}

int startingPoint(int x)
{
    if (x == 1)
        return 2;
    return 0;
}

int checkFor0x(char s[])
{
    int i = 0;
    if ((s[0] == '0') && (s[1] == 'x' || s[1] == 'X'))
    {
        return 1;
    }
    return 0;
}