/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_prod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:52:10 by pablo             #+#    #+#             */
/*   Updated: 2025/02/07 16:12:07 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

double	*ft_vect_prod(double *vect, double n, size_t d)
{
	size_t		i;
	double	*result;

	if (!vect)
		return (NULL);
	result = malloc(sizeof(double) * d);
	if (!result)
		return (NULL);
	i = 0;
	while (i < d)
	{
		result[i] = n * vect[i];
		i++;
	}
	return (result);
}
