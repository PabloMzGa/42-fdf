/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_maxcol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:17:34 by pablo             #+#    #+#             */
/*   Updated: 2025/02/10 21:22:34 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_matrix_maxcol(double **array, size_t size, size_t pos)
{
	double	max;
	size_t	i;

	max = DBL_MIN;

	i = 0;
	while (i < size)
	{
		if (max < array[i][pos])
		{
			max = array[i][pos];
		}
		++i;
	}
	return (max);
}
