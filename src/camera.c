/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:33:57 by pablo             #+#    #+#             */
/*   Updated: 2025/03/06 20:44:24 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	*set_camera_normal(t_map *map, double *p_point)
{
	double	center[3];
	double	*normal;
	double	*n_normal;

	center[0] = map->size_x / 2;
	center[1] = map->size_y / 2;
	center[2] = 0;
	normal = ft_vect_sub(center, p_point, 3);
	n_normal = ft_vect_norm(normal, 3);
	free(normal);
	return (n_normal);
}

double	*set_p_point(t_map *map)
{
	double	*p_point;
	double	max_z;
	double	d;
	double	isometric_dir[3];
	double 	*iso_norm;

	p_point = malloc(sizeof(double) * 3);
	if (!p_point)
		return (perror("Error allocating p_point"), NULL);
	max_z = ft_matrix_maxcol(map->vertices, map->size_x * map->size_y, 2);
	d = sqrtf(pow(map->size_x / 2, 2) + pow(map->size_y / 2, 2) + pow(max_z / 2,
				2));
	isometric_dir[0] = 1;
	isometric_dir[1] = 1;
	isometric_dir[2] = 1;
	iso_norm = ft_vect_norm(isometric_dir, 3);
	p_point[0] = (map->size_x / 2) + iso_norm[0] * d;
	p_point[1] = (map->size_y / 2) + iso_norm[1] * d;
	p_point[2] = (max_z / 2) + iso_norm[2] * d;
	printf("P point: (%f, %f, %f)\n", p_point[0], p_point[1], p_point[2]);
	return (p_point);
}
