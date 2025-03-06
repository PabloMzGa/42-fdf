/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:28:36 by pabmart2          #+#    #+#             */
/*   Updated: 2025/03/01 18:29:38 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*alloc_2d_map(t_map *p_map, double **vects_2d)
{
	t_map	*map_2d;

	map_2d = malloc(sizeof(t_map));
	if (!map_2d)
		return (perror("Error allocating map_2d"), NULL);
	map_2d->vertices = vects_2d;
	map_2d->size_x = p_map->size_x;
	map_2d->size_y = p_map->size_y;
	return (map_2d);
}
