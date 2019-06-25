/*
** EPITECH PROJECT, 2019
** SYN_FASTAtools_2018
** File description:
** main
*/

#include "fasta.h"

void init_struct(fasta_t *fa)
{
    fa->file = NULL;
    fa->fst = NULL;
}

void get_file(fasta_t *fa)
{
    char *tmp = 0;
    int count = 0;

    fa->file = malloc(sizeof(char *) * 100);
    while ((tmp = get_next_line(0)) != NULL) {
        fa->file[count++] = tmp;
    }
    fa->file[count] = NULL;
}

int main(int ac, char **av)
{
    fasta_t fa;

    error_check(ac, av);
    init_struct(&fa);
    get_file(&fa);
    fa.fst = fill_list(fa.file, av[1]);
    handle_flags(ac, av, &fa);
    return (0);
}