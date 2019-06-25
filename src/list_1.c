/*
** EPITECH PROJECT, 2019
** SYN_SBMLparser_2018
** File description:
** list_1
*/

#include "fasta.h"

cs_t *add_cs(cs_t *next, char *cs)
{
    cs_t *list = malloc(sizeof(cs_t));

    list->c_s = cs;
    list->next = next;
    return (list);
}

buf_t *add_start(buf_t *next, char *str, char *dna)
{
    buf_t *list = malloc(sizeof(buf_t));

    list->name = str;
    list->dna = dna;
    list->next = next;
    return (list);
}

void add_end(buf_t *begin, char *str)
{
    buf_t *list = malloc(sizeof(*list));
    buf_t *tmp = begin;

    list->name = str;
    list->next = NULL;
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = list;
}

void add_mid(buf_t *prev, buf_t *next, char *str)
{
    buf_t *add = malloc(sizeof(buf_t *));

    add->name = str;
    add->next = next->next;
    prev->next = add;
}

int list_len(buf_t *buf)
{
    int count = 0;

    for (buf_t *tmp = buf; tmp; tmp = tmp->next)
        count++;
    return (count);
}