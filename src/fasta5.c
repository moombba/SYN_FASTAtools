/*
** EPITECH PROJECT, 2019
** SYN_FASTAtools_2018
** File description:
** fasta5
*/

#include "fasta.h"

int is_stop(char *str)
{
    if (len_to_char(str, '\0') < 3)
        return (-1);
    if (!strncmp(str, "TAG", strlen("TAG")))
        return (0);
    if (!strncmp(str, "TAA", strlen("TAA")))
        return (0);
    if (!strncmp(str, "TGA", strlen("TGA")))
        return (0);
    return (-1);
}

int find_stop(char *str)
{
    int count = 0;

    for (int i = 0; str[i]; i += 3, count += 3) {
        if (str[i] == 'T' && !is_stop(&str[i]))
            return (count);
    }
    return (-1);
}

int is_start(char *str)
{
    if (len_to_char(str, '\0') < 3)
        return (-1);
    if (!strncmp(str, "ATG", strlen("ATG")))
        return (0);
    return (-1);
}

int jump_to_start(char *str, int i)
{
    int count = 0;

    for (; str[i]; i++, count++) {
        if (str[i] == 'A' && !is_start(&str[i]))
            return (count);
    }
    return (-1);
}

cs_t *fasta25(cs_t *next, char *str)
{
    int count = -1;
    char *c_s = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == 'A' && !is_start(&str[i]))
            count = find_stop(&str[i]);
        if (count != -1) {
            c_s = retrieve_data(&str[i], count);
            if (!is_addable(next, c_s))
                next = add_cs(next, c_s);
        }
        count = -1;
    }
    return (next);
}