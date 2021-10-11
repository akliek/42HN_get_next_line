/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:27:55 by akliek            #+#    #+#             */
/*   Updated: 2021/10/11 11:33:08 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_strdel(char *s)
{
	free(s);
	s = NULL;
}

static int	rd_is_zero(char *str, char **line)
{
	ft_strdel(str);
	*line = ft_strdup("");
	return (0);
}

static int	get_line(char **str, char **line, int fd)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[fd][i] && str[fd][i] != '\n')
		i++;
	if (str[fd][i] == '\n')
	{
		*line = ft_substr(str[fd], 0, i);
		tmp = ft_strdup(str[fd] + i + 1);
		free(str[fd]);
		str[fd] = ft_strdup(tmp);
		free(tmp);
	}
	else if (str[fd][i] == '\0')
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(str[fd]);
		return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	int			rd;
	static char	*str[0xffffffff];
	char		*tmp;

	rd = read(fd, buff, BUFFER_SIZE);
	while (rd > 0)
	{
		buff[BUFFER_SIZE] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup("");
		tmp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = ft_strdup(tmp);
		free(tmp);
		if (ft_strchr(str[fd], '\n'))
			break ;
		rd = read(fd, buff, BUFFER_SIZE);
	}
	if (rd < 0 || !line)
		return (-1);
	else if (rd == 0 && !str[fd])
		return (rd_is_zero(str[fd], line));
	return (get_line(str, line, fd));
}
