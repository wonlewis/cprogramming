#include <stdio.h>
#define MAXLINE 1000
/** logic as below
 * read line
 * Count number of characters. if > 80, save into char array
 * at end of line, add new line
 * print the char array
 */

int record(char s[]);
int AppendToArray(char result[], char from[], int startingPoint, int recordOutcome);
void ClearString(char s[]);
int CountLength(char s[]);
void Reverse(char intput[], char output[]);

void clearString(char s[])
{
    s[0] = '\n';
}

int main()
{
    int lineLength, c, recordOutcome;
    int startingPoint = 0;
    char validString[MAXLINE];
    char reversedString[MAXLINE];
    char result[MAXLINE];

    while ((recordOutcome = record(validString)) > -1)
    {
        if (recordOutcome > 0)
        {
            Reverse(validString, reversedString);
            startingPoint = AppendToArray(result, reversedString, startingPoint, recordOutcome);
            clearString(validString);
        }
    }
    printf("%s", result);
    return 0;
}

int AppendToArray(char result[], char from[], int startingPoint, int recordOutcome)
{
    int i = startingPoint;
    int j = 0;
    while ((j <= recordOutcome) && (from[j] != '\n'))
    {
        result[i] = from[j];
        i++;
        j++;
    }
    clearString(from);
    result[i] = '\n';
    i++;
    return i;
}

int record(char s[])
{
    int c;
    int newLineCounter = MAXLINE;
    int i = 0;
    int lastEmptyCounter = -1;
    while ((c = getchar()) != EOF)
    {
        s[i] = c;
        if ((c == ' ' || c == '\t') && lastEmptyCounter == -1)
            lastEmptyCounter = i;
        else if (c != ' ' && c != '\t' && c != '\n')
            lastEmptyCounter = -1;
        if (c == '\n')
        {
            if (lastEmptyCounter != -1)
                s[lastEmptyCounter] = '\n';
            return i;
        }
        i++;
    }
    return -1;
}

void Reverse(char input[], char output[])
{
    int length;
    length = CountLength(input);
    int j = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        output[j] = input[i];
        j++;
    }
    output[j] = '\n';
}

int CountLength(char input[])
{
    int i = 0;
    while (input[i] != '\n')
        i++;
    return i;
}
