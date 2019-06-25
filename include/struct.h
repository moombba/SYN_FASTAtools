/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct cs_s {
    char *c_s;
    struct cs_s *next;
} cs_t;

typedef struct buf_s {
    char *name;
    char *dna;
    struct buf_s *next;
} buf_t;

typedef struct fasta_s {
    char **file;
    buf_t *fst;
} fasta_t;


#endif /* !STRUCT_H_ */
