/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:21:11 by pablo             #+#    #+#             */
/*   Updated: 2025/03/13 19:08:38 by pablo            ###   ########.fr       */
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
	free(gmap->p_point);
	free(gmap->center);
	free(gmap);
}

