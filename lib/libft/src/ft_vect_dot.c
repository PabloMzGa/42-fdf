/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_dot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:04:26 by pablo             #+#    #+#             */
/*   Updated: 2025/01/30 16:13:14 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

double	ft_vect_dot(double *v1, double *v2, int d)
{
	int		i;
	double	result;

	i = 0;
	result = 0;
	while (i < d)
	{
		result += v1[i] * v2[i];
		++i;
	}
	return (result);
}
