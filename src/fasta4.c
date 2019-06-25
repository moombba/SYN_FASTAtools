/*
** EPITECH PROJECT, 2019
** SYN_FASTAtools_2018
** File description:
** fasta4
*/

#include "fasta.h"

char *check_mer(char *str, char **arr, int k)
{
    char *new = malloc(sizeof(char) * (k + 1));

    for (int i = 0; i < k; i++) {
        new[i] = str[i];
    }
    new[k] = 0;
    for (int i = 0; arr[i]; i++) {
        if (!strcmp(new, arr[i])) {
            free(new);
            return (NULL);
        }
    }
    return (new);
}

void fasta4(fasta_t *fa, int k)
{
    char **arr;
    int len = 0;
    int run = 0;
    char *mer = NULL;

    for (buf_t *tmp = fa->fst; tmp; tmp = tmp->next)
        len += strlen(tmp->dna);
    arr = malloc(sizeof(char *) * (len * 2));
    arr[run] = NULL;
    for (buf_t *tmp = fa->fst; tmp; tmp = tmp->next) {
        len = strlen(tmp->dna);
        for (int i = 0;len >= k && tmp->dna[i + (k - 1)]; i++) {
            mer = check_mer(&tmp->dna[i], arr, k);
            if (mer != NULL)
                arr[run++] = mer;
        arr[run] = NULL;
        }
    }
    disp_arr(arr, k);
}