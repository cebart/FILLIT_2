#include "get_next_line.h"

static char	    *ft_too_much_read(char *str)
{
	char	*leftover;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if ((str[i] && !str[i + 1]) || !str[i])
	{
		ft_strdel(&str);
		return (NULL);
	}
	leftover = ft_strdup(str + i + 1);
	return (leftover);
}

static char		*ft_put_line(char *str)
{
	int		i;
	char	*line;

    i = ft_strlen(str);
	line = ft_strnew(i + 1);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int			get_next_line(const int fd, char **line)
{
	static char	    *files[100]; /* OPEN_MAX*/
	int				ret;
	char			*str;


	str = ft_strnew(BUFF_SIZE + 1);
	if (fd < 0 || BUFF_SIZE < 0 || !line)
		return (-1);
	if (!files[fd])
		files[fd] = ft_strnew(BUFF_SIZE + 1);
	while (!(ft_strchr(files[fd], '\n')))
	{
		ret = read(fd, str, BUFF_SIZE);
		if (ret == -1)
			return (0);
		str[ret] = '\0';
		files[fd] = ft_strjoin(files[fd], str);
		if (ret == 0)
			return (0);
	}
	*line = ft_put_line(files[fd]);
	files[fd] = ft_too_much_read(files[fd]);
	return (1);
}
