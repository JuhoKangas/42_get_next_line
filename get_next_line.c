/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:02:30 by jkangas           #+#    #+#             */
/*   Updated: 2022/01/17 18:42:45 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft/libft.h"

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
	return (bytes_read);
}
