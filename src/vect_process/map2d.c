/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:28:36 by pabmart2          #+#    #+#             */
/*   Updated: 2025/03/17 19:17:51 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Computes the normalized vector perpendicular to the given normal
 * vector.
 *
 * This function calculates a vector that is perpendicular to the given normal
 * vector by performing a cross product with the up vector (0, 0, 1).
 * The resulting vector is then normalized.
 *
 * @param normal The normal vector to which the perpendicular vector is to be
 *               computed.
 * @return A pointer to the normalized perpendicular vector.
 * @note The caller is responsible for freeing the returned vector.
 */
static double	*get_up_vect(double *normal)
{
	double	up[3];
	double	*cross;
	double	*n_cross;

	up[0] = 0;
	up[1] = 0;
	up[2] = 1;
	cross = ft_vect_cross(up, normal, 3);
	n_cross = ft_vect_norm(cross, 3);
	free(cross);
	return (n_cross);
}

/**
 * @brief Computes the right vector from the given normal and up vectors.
 *
 * This function calculates the right vector by taking the cross product of the
 * normal and up vectors, and then normalizes the resulting vector.
 *
 * @param normal A pointer to the normal vector.
 * @param up A pointer to the up vector.
 * @return A pointer to the normalized right vector.
 * @note The caller is responsible for freeing the returned vector.
 */
static double	*get_right_vect(double *normal, double *up)
{
	double	*right;
	double	*n_right;

	right = ft_vect_cross(normal, up, 3);
	n_right = ft_vect_norm(right, 3);
	free(right);
	return (n_right);
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
	right = get_right_vect(normal, up);
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
