/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:33:57 by pablo             #+#    #+#             */
/*   Updated: 2025/02/11 22:55:12 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/**
 * TODO: Creo que se esta viendo todo desde debajo
 */
double	*set_camera_normal(t_map *map, double *p_point)
{
	double	center[3];
	double	*normal;
	double	*n_normal;

	normal = malloc(sizeof(double) * 3);
	if (!normal)
		return (perror("Error allocating normal"), NULL);
	center[0] = map->size_x / 2;
	center[1] = map->size_y / 2;
	center[2] = 0;
	normal = ft_vect_sub(center, p_point, 3);
	n_normal = ft_vect_norm(normal, 3);
	free(normal);
	printf("Normal: (%f, %f, %f)\n", n_normal[0], n_normal[1], n_normal[2]);
	return (n_normal);
}

double	*set_p_point(t_map *map)
{
	double	*p_point;
	double	max_z;
	double	d;

	p_point = malloc(sizeof(double) * 3);
	if (!p_point)
		return (perror("Error allocating p_point"), NULL);
	max_z = ft_matrix_maxcol(map->vertices, map->size_x * map->size_y, 2);
	d = sqrtf(pow(map->size_x / 2, 2) + pow(map->size_y / 2, 2) + pow(max_z / 2,
				2));

	p_point[0] = (map->size_x / 2) - d;
	p_point[1] = (map->size_y / 2) - d;
	p_point[2] = d;
	printf("P point: (%f, %f, %f)\n", p_point[0], p_point[1], p_point[2]);
	return (p_point);
}
