/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_cross.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:04:26 by pablo             #+#    #+#             */
/*   Updated: 2025/02/07 16:26:31 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

double	*ft_vect_cross(double *v1, double *v2, size_t d)
{
	size_t		i;
	double*	result;

	result = malloc(sizeof(double) * d);
	if(!result)
		return (NULL);

	i = 0;
	while (i < d)
	{
		result[i] = v1[i] * v2[i];
		++i;
	}
	return (result);
}
