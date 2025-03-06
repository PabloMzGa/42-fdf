/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:28:36 by pabmart2          #+#    #+#             */
/*   Updated: 2025/03/06 20:31:54 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/**
 *
 * TODO: Comprobar si la normal se encuentra muy cerca de 0,0,1, y escoger otro
 * up.
 */
static double	*get_up_vect(double *normal)
{
	double	up[3];

	up[0] = 0;
	up[1] = 0;
	up[2] = 1;
	return (ft_vect_norm(ft_vect_cross( up,normal, 3), 3));
}

t_map	*create_2d_map(t_map *p_map, double *normal, double *p_point)
{
	double	*up;
	double	*right;
	double	*d_vect;
	double	**vects_2d;
	size_t	i;

	vects_2d = malloc(sizeof(double *) * p_map->size_x * p_map->size_y);
	if (!vects_2d)
		return (perror("Error allocating vects_2d"), NULL);
	up = get_up_vect(normal);
	right = ft_vect_norm(ft_vect_cross(normal,up, 3), 3);

	i = 0;
	while (i < p_map->size_x * p_map->size_y)
	{
		d_vect = ft_vect_sub(p_map->vertices[i], p_point, 3);
		vects_2d[i] = malloc(sizeof(double) * 2);
		if (!vects_2d[i])
			return (perror("Error allocating 2d vector in vects_2d"), NULL);
		vects_2d[i][0] = ft_vect_dot(d_vect, up, 3);
		vects_2d[i][1] = ft_vect_dot(d_vect, right, 3);
		free(d_vect);
		++i;
	}
	return (free(up), free(right), alloc_2d_map(p_map, vects_2d));
}
