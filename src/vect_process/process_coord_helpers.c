/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_coord_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:28:36 by pabmart2          #+#    #+#             */
/*   Updated: 2025/03/06 21:04:31 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

/**
 * @brief - Calculates the center coordinates of a given map.
 *
 * This function allocates memory for a 3-element array of doubles and
 * calculates the center coordinates of the map. The center coordinates
 * are determined by taking the midpoint of the map's width (size_x),
 * height (size_y), and the maximum z-coordinate value (max_z).
 *
 * @param map Pointer to the t_map structure containing the map data.
 * @return A pointer to a dynamically allocated array of doubles
 *         containing the center coordinates [center_x, center_y, center_z].
 *         Returns NULL if memory allocation fails.
 * @note The caller is responsible for freeing the memory allocated for the
 *       vector
 */
double	*get_center(t_map *map)
{
	double	*center;
	double	max_z;

	center = malloc(sizeof(double) * 3);
	if (!center)
		return (NULL);
	max_z = ft_matrix_maxcol(map->vertices, map->size_x * map->size_y, 2);
	center[0] = map->size_x / 2;
	center[1] = map->size_y / 2;
	center[2] = max_z / 2;
	return (center);
}
