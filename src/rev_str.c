/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** rev_str
*/

#include "fasta.h"

char *rev_str(char *str)
{
    int wr = 0;
    int run = 0;
    char *rev = malloc(sizeof(char) * (strlen(str) + 1));

    for (; str[run]; run++);
    run--;
    for (; run >= 0; run--, wr++) {
        rev[wr] = str[run];
    }
    rev[wr] = '\0';
    return (rev);
}