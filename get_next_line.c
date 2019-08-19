/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:45:59 by rhendrik          #+#    #+#             */
/*   Updated: 2019/08/19 12:34:24 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	has_read(char **s, int fd, char *buff)
{
	int		hasread;
	char	*tmp;

	while (!(ft_strchr(buff, '\n')))
	{
		hasread = read(fd, buff, BUFF_SIZE);
		if (hasread < 0)
			return (-1);
	}
		buff[hasread] = '\0';
		tmp = ft_strjoin(*s, buff);
		ft_strdel(s);
		*s = ft_strdup(tmp);
		ft_strdel(&tmp);
	if (!buff[0] && !(*s)[0])
		return (0);
	return (1);
}

static int	set_str(char **s, char **line, char *tmp)
{
	char	*tmp2;

	if ((tmp = ft_strchr(*s, '\n')) == NULL && *s[0] != '\0')
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	else if (*s[0] == '\0')
	{
		return (0);
	}
	else
	{
		*tmp = '\0';
		*line = ft_strdup(*s);
		tmp2 = ft_strdup(tmp + 1);
		ft_strdel(s);
		*s = ft_strdup(tmp2);
		ft_strdel(&tmp2);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*s[1024];
	char		*tmp;

	tmp = NULL;
	if (!s[fd])
		s[fd] = ft_strnew(1);
	buff[0] = '\0';
	if (line == NULL || fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	if (has_read(&(s[fd]), fd, buff) < 0)
		return (-1);
	return (set_str(&(s[fd]), line, tmp));
}
