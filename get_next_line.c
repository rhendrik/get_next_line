#include "libft.h"
#include "get_next_line.h"

/* This funtion is a helper function that calls read(2) and returns
 ** 1, 0 or -1, depending on whether or not the 
    read has been sucessful */

int has_read(char *s[255], int fd, char *buff)
{
	int hasread;

	if ((hasread = read(fd, buff, BUFF_SIZE)) == 0)
		return (0);
	if ((hasread = read(fd, buff, BUFF_SIZE)) < 0)
		return (-1);
	while ((hasread = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[hasread] = '\0';
		*s = ft_strjoin(*s, buff);
	}
	return (1);
}

int get_len(char *s)
{
	int len;
	len = 0;

	while (s[len] != '\n' || s[len] != '\0')
		len++;
	return (len);
}

int set_str(char *s[255], char **line, char *tmp, int fd)
{
	int len;

	len = get_len(s[fd]);
	if((tmp = ft_strchr(s[fd], '\n')) == NULL)
	{
		*line = ft_strdup(s[fd]);
		return (0);
	}
	else
	{
		tmp = ft_strchr(s[fd], '\n') + 1;
		*line = ft_strsub(s[fd], 0, len);
		free(s[fd]);
		s[fd] = tmp;
		free(tmp);
		return (1);
	}
	return (-1);
}

int get_next_line(const int fd, char **line)
{
	char *buff;
	static char *s[255];
	char *tmp;

	tmp = NULL;
	if (!s[fd])
		s[fd] = ft_strnew(0);
	buff = (char *)malloc(BUFF_SIZE + 1 * sizeof(char));
	if (line == NULL || fd < 0 || read(fd, buff, BUFF_SIZE) < 0)
		return (-1);
	if (has_read(s, fd, buff) < 0)
		return (-1);
	buff[fd] = '\0';
	return (set_str(s, line, tmp, fd));
}

