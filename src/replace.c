/*
** EPITECH PROJECT, 2019
** fasta
** File description:
** replace
*/

#include "fasta.h"

void replace(char *str, char t_r, char nw)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == t_r)
            str[i] = nw;
    }
}

char comp(char str)
{
    switch (str)
    {
        case 'T':
            return ('A');
        case 'A':
            return ('T');
        case 'G':
            return ('C');
        case 'C':
            return ('G');
        default:
            return (str);
    }
}

char *rev_com(char *str)
{
    int len = strlen(str);
    char *new = malloc(sizeof(char) * (len + 1));

    for (int i = 0; str[i]; i++)
        new[i] = comp(str[i]);
    new[len] = 0;
    return (rev_str(new));
}