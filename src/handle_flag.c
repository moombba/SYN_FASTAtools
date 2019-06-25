/*
** EPITECH PROJECT, 2019
** $
** File description:
** handle_flag
*/

#include "fasta.h"

void h_f2(int ac, char **av, fasta_t *fa)
{
    cs_t *cs = NULL;
    switch (atoi(av[1])) {
        case 5 :
            for (buf_t *tmp = fa->fst; tmp != NULL; tmp = tmp->next) {
                cs = fasta25(cs, tmp->dna);
                cs = fasta25(cs, rev_com(tmp->dna));
            }
            cs = sort_cs(cs);
            for (cs_t *tmp = cs; tmp; tmp = tmp->next)
                if (tmp->c_s != 0)
                    puts_author(tmp->c_s, "CGTAN");
            exit(0);
        case 6:
            exit(0);
        case 7:
            exit(0);
    }
}

void handle_flags(int ac, char **av, fasta_t *fa)
{
    switch (atoi(av[1])) {
        case 1 :
            fasta1(fa);
            exit(0);
        case 2 :
            fasta2(fa);
            exit(0);
        case 3 :
            fasta3(fa);
            exit(0);
        case 4 :
            if (ac != 3)
                exit(84);
            fasta4(fa, atoi(av[2]));
            exit(0);
    }
    h_f2(ac, av, fa);
}