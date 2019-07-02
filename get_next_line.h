#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include "libft.h"
#include <stdio.h>
#define BUFF_SIZE 10

int get_next_line(const int fd, char **line);
int getlen(const int fd, char **line);

#endif
