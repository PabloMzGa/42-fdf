/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:28:36 by pabmart2          #+#    #+#             */
/*   Updated: 2025/03/04 12:49:49 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Assigns a vector based on the given normal vector and position.
 *
 * This function assigns values to a vector `a_vect` based on the provided
 * normal vector `normal` and the position `pos`. The assignment is done
 * differently depending on the value of `pos`.
 *
 * @param a_vect A pointer to the vector to be assigned.
 * @param normal The normal vector used for assignment.
 * @param pos The position index determining the assignment pattern.
 *            - If pos is 0, assigns values based on the first pattern.
 *            - If pos is 1, assigns values based on the second pattern.
 *            - If pos is 2, assigns values based on the third pattern.
 *            - If pos is any other value, an error message is printed and NULL
 *              is returned.
 *
 * @return The assigned vector `a_vect`, or NULL if an error occurred.
 */
static double	*assign_a_vector(double **a_vect, double *normal, size_t pos)
{
	if (pos == 0)
	{
		(*a_vect)[0] = 0;
		(*a_vect)[1] = -normal[2];
		(*a_vect)[2] = -normal[1];
	}
	else if (pos == 1)
	{
		(*a_vect)[0] = -normal[2];
		(*a_vect)[1] = 0;
		(*a_vect)[2] = -normal[0];
	}
	else if (pos == 2)
	{
		(*a_vect)[0] = -normal[1];
		(*a_vect)[1] = normal[0];
		(*a_vect)[2] = 0;
	}
	else
		return (perror("Error assigning a_vector"), NULL);
	return (*a_vect);
}

/**
 * @brief Allocates and computes a vector based on the given normal vector.
 *
 * This function allocates memory for a new vector, normalizes the input normal
 * vector, assigns a new vector based on the normalized values, and then
 * normalizes the resulting vector.
 *
 * @param normal A pointer to a double array representing the normal vector.
 *               The function expects this array to have 3 elements.
 *
 * @return A pointer to the newly allocated and computed vector, or NULL if
 *         memory allocation fails.
 *
 * @note The caller is responsible for freeing the returned vector.
 */
static double	*get_a_vect(double *normal)
{
	double	*a_vect;
	double	*aux;

	a_vect = malloc(sizeof(double) * 3);
	if (!a_vect)
		return (perror("Error allocating a_vect"), NULL);
	normal = ft_vect_abs(normal, 3);
	a_vect = assign_a_vector(&a_vect, normal, ft_mindbl(normal, 3));
	free(normal);
	aux = a_vect;
	a_vect = ft_vect_norm(a_vect, 3);
	free(aux);
	return (a_vect);
}

/**
 * @brief Computes the unit vector (u_vect) orthogonal to the given normal
 * vector.
 *
 * This function calculates a unit vector that is orthogonal to the provided
 * normal vector. It first computes an arbitrary vector (a_vect) that is not
 * parallel to the normal vector. Then, it calculates the cross product of
 * a_vect and the normal vector to get an auxiliary vector (aux).
 * Finally, it normalizes the auxiliary vector to obtain the unit vector
 * (u_vect).
 *
 * @param normal A pointer to the normal vector (array of doubles).
 * @return A pointer to the unit vector (u_vect) orthogonal to the normal
 *         vector.
 *
 * @note The caller is responsible for freeing the returned pointer.
 */
static double	*get_u_vect(double *normal)
{
	double	*a_vect;
	double	*u_vect;
	double	*aux;

	a_vect = get_a_vect(normal);
	aux = ft_vect_cross(a_vect, normal, 3);
	u_vect = ft_vect_norm(aux, 3);
	free(aux);
	free(a_vect);
	return (u_vect);
}

/**
 * @brief Computes the v vector which is orthogonal to the given normal
 * and u vectors.
 *
 * This function calculates the cross product of the normal vector and the
 * u vector, normalizes the resulting vector, and returns it as the v vector.
 *
 * @param normal A pointer to the normal vector.
 * @param u_vect A pointer to the u vector.
 * @return A pointer to the v vector, which is orthogonal to both the normal
 *         and u vectors.
 *
 * @note The caller is responsible for freeing the memory allocated for the
 *       returned v vector.
 */
static double	*get_v_vect(double *normal, double *u_vect)
{
	double	*aux;
	double	*v_vect;

	aux = ft_vect_cross(normal, u_vect, 3);
	v_vect = ft_vect_norm(aux, 3);
	free(aux);
	return (v_vect);
}

t_map	*create_2d_map(t_map *p_map, double *normal, double *p_point)
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
	v_vect = get_v_vect(normal, u_vect);
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
	return (free(u_vect), free(v_vect), alloc_2d_map(p_map, vects_2d));
}
