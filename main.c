/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:07:16 by rhendrik          #+#    #+#             */
/*   Updated: 2019/07/06 15:31:44 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	char *line;
	int i;

	i = 0;
	line = NULL;
	fd = open("tester", O_RDONLY);
	while(get_next_line(fd, &line) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		ft_strdel(&line);
		i++;
	}
	ft_putstr("Yaay!\n");
	ft_putchar('\n');
	sleep (100);
	return (0);
}
