/*
** EPITECH PROJECT, 2019
** SYN_FASTAtools_2018
** File description:
** len_to_char
*/

#include "fasta.h"

int len_to_char(char *str, char c)
{
    int count = 0;
    for (int i = 0; str[i] && str[i] != c; i++) {
        count++;
    }
    return (count);
}