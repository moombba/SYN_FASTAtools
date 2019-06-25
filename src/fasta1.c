/*
** EPITECH PROJECT, 2019
** SYN_FASTAtools_2018
** File description:
** fasta1
*/

#include "fasta.h"

void fasta1(fasta_t *fa)
{
    int len = list_len(fa->fst);
    buf_t *tmp;

    for (int i; len > 0; len--) {
        i = 1;
        tmp = fa->fst;
        for (; i < len; tmp = tmp->next, i++);
        printf("%s\n%s\n", tmp->name, tmp->dna);
    }
}

void fasta2(fasta_t *fa)
{
    int len = list_len(fa->fst);
    buf_t *tmp;

    for (int i; len > 0; len--) {
        i = 1;
        tmp = fa->fst;
        for (; i < len; tmp = tmp->next, i++);
        replace(tmp->dna, 'T', 'U');
        printf("%s\n%s\n", tmp->name, tmp->dna);
    }
}

void fasta3(fasta_t *fa)
{
    int len = list_len(fa->fst);
    buf_t *tmp;

    for (int i; len > 0; len--) {
        i = 1;
        tmp = fa->fst;
        for (; i < len; tmp = tmp->next, i++);
        printf("%s\n%s\n", tmp->name, rev_com(tmp->dna));
    }
}