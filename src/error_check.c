/*
** EPITECH PROJECT, 2019
** SYN_FASTAtools_2018
** File description:
** error_check
*/

#include "fasta.h"

int is_num(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return (-1);
    return (0);
}

int error_check(int ac, char **av)
{
    if (ac < 2 || ac > 3)
        exit(84);
    if (strlen(av[1]) != 1)
        exit(84);
    if (av[1][0] < '1' || av[1][0] > '7')
        exit(84);
    if (ac == 3 && is_num(av[2]) == -1)
        exit(84);
    return (0);
}