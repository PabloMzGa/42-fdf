/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:30:14 by pabmart2          #+#    #+#             */
/*   Updated: 2025/01/30 18:58:09 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h>

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
