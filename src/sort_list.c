/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** sort_tetriminos
*/

#include "fasta.h"

int inc_i(char *str1, char *str2)
{
    int i = 0;

    while (str1[i] == str2[i])
        i++;
    return (i);
}

buf_t *fst_swap(buf_t *tet)
{
    buf_t *save = tet->next->next;
    buf_t *ret = tet->next;

    tet->next->next = tet;
    tet->next = save;
    return (ret);
}

void swap(int index, buf_t *tetris)
{
    buf_t *save1;
    buf_t *save2;
    buf_t *tmp = tetris;

    for (int i = 0; i < index - 1; i++)
        tmp = tmp->next;
    save1 = tmp->next;
    save2 = tmp->next->next->next;
    tmp->next = tmp->next->next;
    tmp->next->next = save1;
    save1->next = save2;
}

int sort_check(buf_t *tetris)
{
    int i = 0;
    int count = 0;

    for (buf_t *tmp = tetris; tmp->next != NULL; tmp = tmp->next) {
        i = 0;
        i += inc_i(tmp->name, tmp->next->name);
        if (tmp->name[i] > tmp->next->name[i])
            return (count);
        count++;
    }
    return (-1);
}

buf_t *sort_list(buf_t *tet)
{
    int ret = sort_check(tet);

    while (ret != -1) {
        if (ret == 0)
            tet = fst_swap(tet);
        else
        {
            swap(ret, tet);
        }
        ret = sort_check(tet);
    }
    return (tet);
}