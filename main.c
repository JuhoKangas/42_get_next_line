/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:06:05 by jkangas           #+#    #+#             */
/*   Updated: 2022/05/02 17:45:15 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	//int	fd = open("basic.txt", O_RDONLY);
	int	fd = open(argv[1], O_RDONLY);
	int	lines = 0;

	argc = 2;
	char	*line = NULL;
	int i = 1;
	printf("fd is: %d\n", fd);
	while (i > 0)
	{
		i = get_next_line(fd, &line);
		printf("%d: %s\n", lines, line);
		ft_strdel(&line);
		lines++;
	}
	printf("%d", lines);
	//system("leaks a.out");
	return (0);
}
