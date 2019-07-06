#include "libft.h"
#include "get_next_line.h"

/* This funtion is a helper function that calls read(2) and returns
 ** 1, 0 or -1, depending on whether or not the 
    read has been sucessful */

int has_read(char **s, int fd, char *buff)
{
	int hasread;
	char *tmp;

	if ((hasread = read(fd, buff, 0)) < 0)
		return (-1);
	//if ((hasread = read(fd, buff, BUFF_SIZE)) == 0)
	//	return (0);
	while ((hasread = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[hasread] = '\0';
		//temp = *s;
		tmp = ft_strjoin(*s, buff);
		ft_strdel(s);
		*s = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	if (!buff[0] && !(*s)[0])
		return (0);
	return (1);
}

int get_len(char **s)
{
	int len;
	len = 0;

	while ((*s)[len] != '\n' &&	(*s)[len] != '\0')
		len++;
	return (len);
}

int set_str(char **s, char **line, char *tmp)
{
	int len;
	char	*tmp2;

	if((tmp = ft_strchr(*s, '\n')) == NULL && *s[0] != '\0')
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
		len = get_len(s);
		*tmp = '\0';
		*line = ft_strdup(*s);
	
		tmp2 = ft_strdup(tmp +1);
		//tmp = ft_strsub(*s, len, len - ft_strlen(tmp));
		ft_strdel(s);
		*s = ft_strdup(tmp2);
		ft_strdel(&tmp2);
	}
	return (1);
}

int get_next_line(const int fd, char **line)
{
	char buff[BUFF_SIZE + 1];
	static char *s[1024];
	char *tmp;

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

