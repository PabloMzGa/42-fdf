/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_mincol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:17:34 by pablo             #+#    #+#             */
/*   Updated: 2025/02/10 21:22:38 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_matrix_mincol(double **array, size_t size, size_t pos)
{
	double	min;
	size_t	i;

	min = DBL_MAX;

	i = 0;
	while (i < size)
	{
		if (min > array[i][pos])
		{
			min = array[i][pos];
		}
		++i;
	}
	return (min);
}
