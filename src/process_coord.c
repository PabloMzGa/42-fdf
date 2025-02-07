/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:28:36 by pabmart2          #+#    #+#             */
/*   Updated: 2025/02/07 17:46:09 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h>

t_map	*project_map(t_map *map, double *normal, double *p_point)
{
	t_map	*projected_map;
	size_t	map_size;
	size_t	i;

	projected_map = malloc(sizeof(t_map));
	if (!project_map)
		return (perror("Error allocating  projected map"), NULL);
	map_size = map->size_x * map->size_y;
	projected_map->vertices = malloc(sizeof(double *) * map_size);
	if (!projected_map->vertices)
		return ((free(projected_map),
				perror("Error allocating projected vertices array"), NULL));
	i = 0;
	while (i < map_size)
	{
		projected_map->vertices[i] = ft_vect_ortproj(map->vertices[i], normal,
				p_point, 3);
		if (!projected_map->vertices[i])
			// TODO: Cleanup de todo lo de arriba si falla
			return (perror("Error projecting vector vector"), NULL);
		++i;
	}
	projected_map->size_x = map->size_x;
	projected_map->size_y = map->size_y;
	return (projected_map);
}

static double	*assign_a_vector(double *a_vect, double *normal, size_t pos)
{
	if (pos == 0)
	{
		a_vect[0] = 0;
		a_vect[1] = -normal[2];
		a_vect[2] = -normal[1];
	}
	else if (pos == 1)
	{
		a_vect[0] = -normal[2];
		a_vect[1] = 0;
		a_vect[2] = -normal[0];
	}
	else if (pos == 2)
	{
		a_vect[0] = -normal[1];
		a_vect[1] = normal[0];
		a_vect[2] = 0;
	}
	else
		return (perror("Error assigning a_vector"), NULL);
	return (a_vect);
}

static double	*get_a_vect(double *normal)
{
	double	*a_vect;
	double	*aux;

	a_vect = malloc(sizeof(double) * 3);
	if (!a_vect)
		return (perror("Error allocating a_vect"), NULL);
	normal = ft_vect_abs(normal, 3);
	a_vect = assign_a_vector(a_vect, normal, ft_mindbl(normal, 3));
	free(normal);
	aux = a_vect;
	a_vect = ft_vect_norm(a_vect, 3);
	free(aux);
	return (a_vect);
}

static double	*get_u_vect(double *normal)
{
	double	*a_vect;
	double	*u_vect;

	a_vect = get_a_vect(normal);
	u_vect = ft_vect_cross(normal, a_vect, 3);
	free(a_vect);
	return (u_vect);
}

/**
 * @brief Creates a 2D map from a 3D map using a normal vector and a
 *        reference point.
 * @param p_map Pointer to the 3D map structure containing vertices
 *        and dimensions.
 * @param normal Pointer to the normal vector used for projection.
 * @param p_point Pointer to the reference point used for projection.
 *
 * This function allocates memory for a 2D map and projects each vertex of the
 * 3D map onto a 2D plane defined by the normal vector and reference point.
 * The 3D map must be already projected onto the plane defined by normal and
 * p_point.
 *
 * It calculates the u and v vectors for the plane, then computes the dot
 * product of the difference vector with these u and v vectors to get the 2D
 * coordinates.
 *
 * @return Pointer to the 2D map (array of 2D vectors) on success,
 *         or NULL on failure.
 */
double	**create_2d_map(t_map *p_map, double *normal, double *p_point)
{
	double	*u_vect;
	double	*v_vect;
	double	*d_vect;
	double	**vects_2d;
	size_t	i;

	vects_2d = malloc(sizeof(double *) * p_map->size_x * p_map->size_y);
	if (!vects_2d)
		return (perror("Error allocating vects_2d"), NULL);
	u_vect = get_u_vect(normal);
	v_vect = ft_vect_cross(normal, u_vect, 3);
	i = 0;
	while (i < p_map->size_x * p_map->size_y)
	{
		d_vect = ft_vect_sub(p_map->vertices[i], p_point, 3);
		vects_2d[i] = malloc(sizeof(double) * 2);
		if (!vects_2d[i])
			return (perror("Error allocating 2d vector in vects_2d"), NULL);
		vects_2d[i][0] = ft_vect_dot(d_vect, u_vect, 3);
		vects_2d[i][1] = ft_vect_dot(d_vect, v_vect, 3);
		free(d_vect);
		++i;
	}
	return (free(u_vect), free(v_vect), vects_2d);
}
