int any(char s1[], char s2[])
{
    int i;
    while (s1[i] != '\0')
    {
        if (checkIfCharInArray(s1[i], s2))
            return i;
        i++;
    }
    return -1;
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