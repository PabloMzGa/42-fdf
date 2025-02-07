/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:21:11 by pablo             #+#    #+#             */
/*   Updated: 2025/02/07 18:07:11 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	clean_map(t_map *map)
{
	size_t	map_size;
	size_t	i;

	map_size = map->size_x * map->size_y;
	i = 0;
	while (i < map_size)
	{
		free(map->vertices[i]);
		++i;
	}
	free(map->vertices);
	free(map);
}

void	clean_matrix(double **matrix, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(matrix[i]);
		++i;
	}
	free(matrix);
}
