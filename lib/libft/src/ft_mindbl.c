/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mindbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:17:34 by pablo             #+#    #+#             */
/*   Updated: 2025/02/07 17:17:40 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_mindbl(double *array, size_t size)
{
	double	min;
	size_t	i;
	size_t	min_pos;

	min = DBL_MAX;
	i = 0;
	min_pos = 0;
	while (i < size)
	{
		if (min > array[i])
		{
			min_pos = i;
			min = array[i];
		}
		++i;
	}
	return (min_pos);
}
