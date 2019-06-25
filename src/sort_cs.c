/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** sort_tetriminos
*/

#include "fasta.h"

int inc_i_cs(char *str1, char *str2)
{
    int i = 0;

    while (str1[i] == str2[i])
        i++;
    return (i);
}

cs_t *fst_swap_cs(cs_t *tet)
{
    cs_t *save = tet->next->next;
    cs_t *ret = tet->next;

    tet->next->next = tet;
    tet->next = save;
    return (ret);
}

void swap_cs(int index, cs_t *tetris)
{
    cs_t *save1;
    cs_t *save2;
    cs_t *tmp = tetris;

    for (int i = 0; i < index - 1; i++)
        tmp = tmp->next;
    save1 = tmp->next;
    save2 = tmp->next->next->next;
    tmp->next = tmp->next->next;
    tmp->next->next = save1;
    save1->next = save2;
}

int sort_check_cs(cs_t *tetris)
{
    int i = 0;
    int count = 0;

    for (cs_t *tmp = tetris; tmp->next != NULL; tmp = tmp->next) {
        i = 0;
        i += inc_i_cs(tmp->c_s, tmp->next->c_s);
        if (tmp->c_s[i] > tmp->next->c_s[i])
            return (count);
        count++;
    }
    return (-1);
}

cs_t *sort_cs(cs_t *tet)
{
    int ret = sort_check_cs(tet);

    while (ret != -1) {
        if (ret == 0)
            tet = fst_swap_cs(tet);
        else
        {
            swap_cs(ret, tet);
        }
        ret = sort_check_cs(tet);
    }
    return (tet);
}