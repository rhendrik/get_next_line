/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:11:23 by rhendrik          #+#    #+#             */
/*   Updated: 2019/06/21 12:28:26 by rhendrik         ###   ########.fr       */
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
	int lentest;
	char **tmpline;

	tmpline = NULL;
	tmpline[0] = ft_strdup("This is a temporary test\n");
	filename = av[1];
	mode = av[2];
	if (ac != 3)
	{
		ft_putstr("Sorry! Invalid arguments.\n <FILENAME> <MODE>\n");
		return (0);
	}
	file = fopen(filename, mode);
	fd = fileno(file);
	lentest = getlen(0, tmpline);
	ft_putnbr(lentest);
	return (0);
}
