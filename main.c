/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:07:16 by rhendrik          #+#    #+#             */
/*   Updated: 2019/06/24 18:19:11 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	int fd;
	(void)ac;
	int gnl;
	char *line;

	fd = open("author", O_RDONLY);
	gnl = 1;
	gnl = get_next_line(fd, &line);
	ft_putstr(line);
	return (0);
}
