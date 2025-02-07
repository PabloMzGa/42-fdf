/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_dot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:04:26 by pablo             #+#    #+#             */
/*   Updated: 2025/02/07 13:33:53 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

double	ft_vect_dot(double *v1, double *v2, size_t d)
{
	size_t		i;
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
