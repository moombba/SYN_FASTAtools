/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** fasta
*/

#ifndef FASTA_H_
    #define FASTA_H_

#include <unistd.h>
#include <string.h>
#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


#define READ_SIZE  1

char *get_next_line(int fd);
char *clean_str(char *str, char *);
int error_check(int ac, char **av);
void handle_flags(int ac, char **av, fasta_t *fa);
int len_to_char(char *str, char c);
int is_auth(char c, char *auth);
char *clean_str5(char *str);
void puts_author(char *str, char *auth);

char *rev_str(char *str);
void replace(char *str, char t_r, char nw);

int list_len(buf_t *buf);
buf_t *fill_list(char **file, char *av);
buf_t *add_start(buf_t *next, char *str, char *dna);
cs_t *add_cs(cs_t *next, char *cs);
buf_t *sort_list(buf_t *tet);
cs_t *sort_cs(cs_t *tet);
char *rev_com(char *str);
void disp_arr(char **arr, int k);

void fasta1(fasta_t *fa);
void fasta2(fasta_t *fa);
void fasta3(fasta_t *fa);
void fasta4(fasta_t *fa, int k);
cs_t *fasta25(cs_t *next, char *str);

char *retrieve_data(char *str, int count);

cs_t *fasta5(cs_t *, char *str);
int find_stop(char *str);
int is_addable(cs_t *, char *);
int jump_to_start(char *str, int i);
#endif /* !FASTA_H_ */
