/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:11:23 by rhendrik          #+#    #+#             */
/*   Updated: 2019/06/20 16:43:26 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int main(int ac, char **av)
{
	int fd;
	const char *filename;
	char *mode;
	FILE *file;

	filename = av[1];
	mode = av[2];
	if (ac != 3)
	{
		ft_putstr("Sorry! Invalid arguments.\n <FILENAME> <MODE>\n");
		return (0);
	}
	file = fopen(filename, mode);
	fd = fileno(file);
	return (0);
}
