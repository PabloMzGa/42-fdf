/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:30:14 by pabmart2          #+#    #+#             */
/*   Updated: 2025/02/05 21:55:53 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h>

//TODO: Cambiar y no usar t_vert y usar directamente double * o int *;

int	main(void)
{
	t_map	*map;
	char	*line;
	int		fd;

	map = read_map("maps/test_maps/10-2.fdf");
	/* 	fd = open("maps/test_maps/10-2.fdf", O_RDONLY);
		line = ft_get_next_line(fd);
		while(line)
		{
			ft_printf("%s\n", line);
			line = ft_get_next_line(fd);
		} */
	printf("A");
}
