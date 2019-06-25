/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** clean_str
*/

#include "fasta.h"

int is_wrong(char c)
{
    if (c == ' ' || c == '\n')
        return (1);
    return (0);
}

int is_auth(char c, char *auth)
{
    for (int i = 0; auth[i]; i++) {
        if (auth[i] == c)
            return (0);
    }
    return (1);
}

char *capitalize(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
    return (str);
}

char *clean_str5(char *str)
{
    int count = 0;
    char *new = 0;
    int lmark = 0;

    for (int i = 0; str[i] != 0; i++)
    {
        if (!is_wrong(str[i]))
            count++;
    }
    new = malloc(sizeof(char) * (count + 1));
    for (int i = 0; str[i]; i++) {
        if (!is_wrong(str[i]))
            new[lmark++] = str[i];
    }
    new[count] = 0;
    new = capitalize(new);
    return (new);
}

char *clean_str(char *str, char *author)
{
    int count = 0;
    char *new = 0;
    int lmark = 0;

    for (int i = 0; str[i] != 0; i++)
    {
        if (!is_wrong(str[i]) && !is_auth(str[i], author))
            count++;
    }
    new = malloc(sizeof(char) * (count + 1));
    for (int i = 0; str[i]; i++) {
        if (!is_wrong(str[i]) && !is_auth(str[i], author))
            new[lmark++] = str[i];
    }
    new[count] = 0;
    new = capitalize(new);
    return (new);
}