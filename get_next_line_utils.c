size_t  ft_strlen(char *s)
{
    size_t  i;

    if (!s)
        return (0);
    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

char    *ft_strchr(char *s, int c)
{
    int i;

    if (!s)
        return (NULL);
    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == (char)c)
            return (&s[i]);
        i++;
    }
    if (s[i] == (char)c)
        return (&S[i]);
    return (NULL);
}

char    *ft_strdup(char *s)
{
    char    *copy;
    int     i;

    i = 0;
    copy = malloc(sizeof(char) * (ft_strlen(s) + 1));
    if (!copy)
        return (NULL);
    while (s[i] != '\0')
    {
        copy[i] = s[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}

char    *strjoin(char *s1, char *s2)
{
    char    *str;
    size_t  i;
    size_t  j;

    if (!s1)
        s1 = ft_strdup("");
    if (!s2)
        return (NULL);
    str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!str);
        return (NULL);
    i = 0;
    j = 0;
    while (s1[i] != '\0')
    {
        str[i] = s1[i];
        i++;
    }
    while (s2[j] != '\0')
    {
        str[i + j] = s2[j];
        j++;
    }
    str[i + j] = '\0';
    return (str);
}