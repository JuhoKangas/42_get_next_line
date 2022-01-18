/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:02:30 by jkangas           #+#    #+#             */
/*   Updated: 2022/01/18 17:10:37 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft/libft.h"

int	get_line(char **str, char **line)
{
	size_t	i;
	char	*temp;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if ((*str)[i] == '\n')
	{
		*line = ft_strsub(*str, 0, i);
		temp = ft_strdup(&(*str)[i + 1]);
		ft_strdel(str);
		*str = temp;
		if ((*str)[0] == '\0')
			ft_strdel(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
	}
	return (1);
}

/*
 * check_data will
 * Return -1 for error in reading the file, bytes < 0
 * Return 0 if the end of file was successfully read, bytes == 0, or
 * Pass the data forward to get_line, bytes > 0
 */

static int	check_data(const int fd, char **line, ssize_t bytes, char **str)
{
	if (bytes < 0)
	{
		ft_memdel((void **)str);
		return (-1);
	}
	else if (bytes == 0 && str[fd] == NULL)
	{
		ft_memdel((void **)str);
		return (0);
	}
	else
		return (get_line(&str[fd], line));
}

/*
 * Comment about get_next_line here
 */

int	get_next_line(const int fd, char **line)
{
	static char	*str[FD_SIZE];
	char		buffer[BUFF_SIZE + 1];
	char		*temp;
	ssize_t		bytes;

	if (fd < 0 || !line)
		return (-1);
	bytes = read(fd, buffer, BUFF_SIZE);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(str[fd], buffer);
			ft_strdel(&str[fd]);
			str[fd] = temp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
		bytes = read(fd, buffer, BUFF_SIZE);
	}
	return (check_data(fd, line, bytes, str));
}
