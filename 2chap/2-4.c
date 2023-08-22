void squeeze(char s[], char c[])
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
        if (!checkIfCharInArray(c, s[i]))
            s[j++] = s[i];
    s[j] = '\0';
}

int checkIfCharInArray(char c, char thisArray[])
{
    int i;
    while (thisArray[i] != '\0')
    {
        if (c == thisArray[i])
            return 1;
        i++;
    }
    return 0;
}