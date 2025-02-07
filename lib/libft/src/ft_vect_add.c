/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:52:10 by pablo             #+#    #+#             */
/*   Updated: 2025/02/07 13:33:47 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

double	*ft_vect_add(double *v1, double *v2, size_t d)
{
	size_t		i;
	double	*result;

	if (!v1 || !v2)
		return (NULL);
	result = malloc(sizeof(double) * d);
	if (!result)
		return (NULL);
	i = 0;
	while (i < d)
	{
		result[i] = v1[i] + v2[i];
		++i;
	}
	return (result);
}
