/*
** EPITECH PROJECT, 2019
** getnext line
** File description:
** read a line
*/

#include "fasta.h"

int look_for_char(char c, char *str)
{
    for (int run = 0; run < READ_SIZE; run++) {
        if (str[run] == c)
            return (1);
    }
    return (0);
}

int set_index(char *buf)
{
    int run = 0;

    for (; buf[run] != '\n'; run++);
    return (++run);
}

char *cut_merge_string(char *str1, char *str2, int index) //and cut at \n
{
    char *buf;
    int run = 0;
    int len1 = 0;
    int len2 = 0;

    for (; str1[len1]; len1 += 1);
    for (; str2[len2]; len2 += 1);
    buf = malloc(len1 + len2 + 1);
    for (int i = 0; str1[i]; run++, i++)
        buf[run] = str1[i];
    for (int i = index; str2[i] && str2[i] != '\n'; run++, i++)
        buf[run] = str2[i];
    buf[run] = '\0';
    return (buf);
}

char *get_next_line(int fd)
{
    char *tmp = malloc(READ_SIZE + 1);
    static char buf[READ_SIZE + 1];
    static unsigned int index = 0;

    *tmp = '\0';
    if (index != 0)
        tmp = cut_merge_string("\0", buf, index);
    else
        (tmp != NULL) ? tmp[0] = '\0', buf[0] = '\0': 0;

    for (int check = 0; (check = read(fd, buf, READ_SIZE) > 0); ) {
        buf[READ_SIZE] = '\0';
        if (look_for_char('\n', buf) > 0) {
            index = set_index(buf);
            return (cut_merge_string(tmp, buf, 0));
        }
        tmp = cut_merge_string(tmp, buf, 0);
    }
    return (NULL);
}