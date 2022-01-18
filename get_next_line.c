/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:02:30 by jkangas           #+#    #+#             */
/*   Updated: 2022/01/18 15:19:01 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft/libft.h"

int	get_line()
{
	//either with iterating with integer or using the pointer from strchr
	//trim the everything after \n including the character itself

	//Set the remaining string as the line to the address given
}

static int	check_data(const int fd, char **line, ssize_t bytes_read, char **str)
{
	//Return -1 for error in reading the file, bytes_read < 0
	if (bytes_read < 0)
	{
		return (-1);
	}
	//Return 0 for successfully reading end of file, bytes_read == 0
	else if (bytes_read == 0)
		return (0);
	//Return 1 for reading the line and coming across \n
	//-->pass the data for trimming the line
	else
		return (get_line(&str[fd]), line)
}

int	get_next_line(const int fd, char **line)
{
	static char	*str[FD_SIZE];
	char		buffer[BUFF_SIZE + 1];
	char		*temp;
	ssize_t		bytes_read;

	if (fd <= 0 || !line)
		return (-1);
	bytes_read = read(fd, buffer, BUFF_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if(!str[fd])
			str[fd] = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(str[fd], buffer);
			ft_strdel(&str[fd]);
			str[fd] = temp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFF_SIZE);
	}
	return (check_data(fd, **line, bytes_read, str));
}
