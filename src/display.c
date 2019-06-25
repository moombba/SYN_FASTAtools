/*
** EPITECH PROJECT, 2019
** SYN_FASTAtools_2018
** File description:
** display
*/

#include "fasta.h"

int is_addable(cs_t *cs, char *str)
{
    int len = strlen(str);

    if (len < 3)
        return (-1);
    for (cs_t *tmp = cs; tmp; tmp = tmp->next)
        if (!strcmp(str, tmp->c_s))
            return (-1);
    return (0);
}

int is_autho(char c, char *auth)
{
    for (int i = 0; auth[i]; i++) {
        if (auth[i] == c)
            return (0);
    }
    return (-1);
}

void puts_author(char *str, char *auth)
{
    for (int run = 0; str[run]; run++) {
        if (!is_autho(str[run], auth))
            putchar(str[run]);
    }
    putchar('\n');
}