/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 08:11:07 by rhendrik          #+#    #+#             */
/*   Updated: 2019/06/21 10:02:21 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int getlen(const int fd, char **line)
{
	char *s;
	int len;

	s = line[fd];
	len = 0;
	while (*s != '\n' || *s != EOF)
	{
		s++;
		len++;
	}
	return (len);
}

int get_next_line(const int fd, char **line)
{
	if (fd < 0 || line == NULL)
		return (-1);
	return (0);
}
