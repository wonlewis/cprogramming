#include <stdio.h>
#define MAXLINE 1000
#define MINLENGTH 80
/** logic as below
 * read line
 * Count number of characters. if > 80, save into char array
 * at end of line, add new line
 * print the char array
 */

int record(char s[]);
int AppendToArray(char result[], char from[], int startingPoint, int recordOutcome);
int CountLength(char s[], int startingPoint);
void ClearString(char s[]);

int main()
{
    int lineLength, c, recordOutcome;
    int startingPoint = 0;
    char validString[MAXLINE];
    char result[MAXLINE];

    while ((recordOutcome = record(validString)) > -1)
    {
        if (recordOutcome > MINLENGTH)
        {
            startingPoint = AppendToArray(result, validString, startingPoint, recordOutcome);
        }
    }
    printf("%s", result);
    return 0;
}

void clearString(char s[])
{
    s[0] = '\n';
}

int AppendToArray(char result[], char from[], int startingPoint, int recordOutcome)
{
    int i = startingPoint;
    int j = 0;
    while (j <= recordOutcome)
    {
        result[i] = from[j];
        i++;
        j++;
    }

    clearString(from);
    return i - 1;
}

int record(char s[])
{
    int c;
    int i = 0;
    while ((c = getchar()) != EOF)
    {
        s[i] = c;
        i++;
        if (c == '\n')
            return i;
    }
    return -1;
}
