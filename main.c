/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:07:16 by rhendrik          #+#    #+#             */
/*   Updated: 2019/06/27 13:23:15 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	int gnl;
	char *line;

	line = NULL;
	fd = open("author", O_RDONLY);
	gnl = get_next_line(fd, &line);
	if (gnl == 1 || gnl == 1)
		ft_putstr("Yaay!\n");
	ft_putstr(line);
	ft_putchar('\n');
	return (0);
}
