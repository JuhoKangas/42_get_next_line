/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:06:05 by jkangas           #+#    #+#             */
/*   Updated: 2022/01/13 18:24:04 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	//int	fd = open("basic.txt", O_RDONLY);
	int	fd = open(argv[1], O_RDONLY);
	//int	fd = 42;

	char	*line = NULL;
	int i = 1;
	
	while (i > 0)
	{
		i = get_next_line(fd, &line);
		printf("%d: %s\n", i, line);
		ft_strdel(&line);
	}
	//system("leaks a.out");
	return (0);
}