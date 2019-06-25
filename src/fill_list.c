/*
** EPITECH PROJECT, 2019
** SYN_FASTAtools_2018
** File description:
** fill_list
*/

#include "fasta.h"

char *retrieve_data(char *str, int count)
{
    char *new = malloc(sizeof(char) * (count + 1));

    for (int i = 0; str[i]; i++) {
        new[i] = str[i];
    }
    new[count] = 0;
    return (new);
}

char *get_dna(char **file, int i)
{
    int len = 0;
    char *dna = 0;

    for (int run = i;file[run] && file[run][0] != '>'; run++) {
        len += strlen(file[run]);
    }
    dna = malloc(sizeof(char) * (len + 1));
    for (;file[i] && file[i][0] != '>'; i++) {
        dna = strcat(dna, file[i]);
    }
    return (dna);
}

buf_t *fill_list(char **file, char *av)
{
    buf_t *next = 0;
    char *name = 0;
    char *tmp = 0;
    char *dna = 0;

    for (int i = 0; file[i]; i++) {
        if (file[i][0] == '>') {
            name = file[i];
            tmp = get_dna(file, i + 1);
            dna = clean_str(tmp, "AaTtGgCcNn");
            next = add_start(next, name, dna);
        }
    }
    return (next);
}