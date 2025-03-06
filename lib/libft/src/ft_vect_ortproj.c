/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_ortproj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:00:54 by pablo             #+#    #+#             */
/*   Updated: 2025/03/06 19:55:39 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

double	*ft_vect_ortproj(double *a_point, double *normal, double *p_point,
		size_t dimension)
{
	double	*result;
	double	*vect_aux;
	double	n_aux;

	if (!dimension)
		return (NULL);
	vect_aux = ft_vect_sub(p_point, a_point, dimension);
	n_aux = ft_vect_dot(normal, vect_aux, dimension);
	free(vect_aux);
	n_aux /= ft_vect_dot(normal, normal, dimension);
	vect_aux = ft_vect_prod(normal, n_aux, dimension);
	result = ft_vect_add(a_point, vect_aux, dimension);
	free(vect_aux);
	return (result);
}
