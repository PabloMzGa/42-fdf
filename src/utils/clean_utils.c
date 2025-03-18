/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:21:11 by pablo             #+#    #+#             */
/*   Updated: 2025/03/14 17:22:28 by pabmart2         ###   ########.fr       */
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

void	clean_gmap(t_gmap *gmap)
{
	clean_map(gmap->map);
	if (gmap->p_point)
		;
	free(gmap->p_point);
	if (gmap->p_point)
		;
	free(gmap->center);
	free(gmap);
}

/**
 * @brief Frees the memory allocated for the projected vertices and the
 * projected map.
 *
 * This function iterates through the projected vertices array in reverse
 * order, freeing each vertex. After all vertices are freed, it frees the
 * array itself and finally the projected map structure.
 *
 * @param i The number of vertices in the projected map.
 * @param projected_map Pointer to the projected map structure containing the
 *                      vertices to be freed.
 */
void	clean_porjected_map(size_t i, t_map *projected_map)
{
	while (i > 0)
		free(projected_map->vertices[--i]);
	free(projected_map->vertices);
	free(projected_map);
}
