/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:28:36 by pabmart2          #+#    #+#             */
/*   Updated: 2025/02/10 20:47:36 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

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
	printf("Vector A:  (%f, %f, %f)\n", a_vect[0], a_vect[1], a_vect[2]);
	free(aux);
	return (a_vect);
}

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

static double	*get_v_vect(double *normal, double *u_vect)
{
	double	*aux;
	double	*v_vect;

	aux = ft_vect_cross(normal, u_vect, 3);
	v_vect = ft_vect_norm(aux, 3);
	free(aux);
	return (v_vect);
}

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
	v_vect = get_v_vect(normal, u_vect);
	printf("Vector Normal:  (%f, %f, %f)\n", normal[0], normal[1], normal[2]);
	printf("Vector U:  (%f, %f, %f)\n", u_vect[0], u_vect[1], u_vect[2]);
	printf("Vector V:  (%f, %f, %f)\n", v_vect[0], v_vect[1], v_vect[2]);
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
