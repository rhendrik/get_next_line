/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 08:11:07 by rhendrik          #+#    #+#             */
/*   Updated: 2019/06/27 13:22:04 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int get_next_place(char **s, char **line)
{
	char *tmp;
	size_t len;

	len = 0;
	while ((*s)[len] != '\n' || (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_strsub(*s, 0, len);
		tmp = ft_strdup(&*s[len + 1]);
		free(*s);
		*s = tmp;
		if ((*s)[0] == '\0')
			ft_strdel(s);
		return (0);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
		return (0);
	}
	return (1);
}

int output(char **s, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && s[fd] ==NULL)
		return (0);
	else
		return get_next_place(&s[fd], line);
}

int get_next_line(const int fd, char **line)
{
	int ret;
	static char **s;
	char buff[BUFF_SIZE + 1];
	char *tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (output(s, line, ret, fd));
}
