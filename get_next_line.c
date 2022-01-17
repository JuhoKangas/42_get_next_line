/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:02:30 by jkangas           #+#    #+#             */
/*   Updated: 2022/01/17 14:56:08 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static char	*str[FD_SIZE];
	char		*buffer[BUFF_SIZE + 1];
	ssize_t		bytes_read;

	if (fd <= 0 || !line)
		return (-1);
	bytes_read = read(fd, buffer, BUFF_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		
	}
}
