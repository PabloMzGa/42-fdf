/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:17:34 by pablo             #+#    #+#             */
/*   Updated: 2025/02/07 13:26:10 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_minint(int *array, size_t size)
{
	int	min;
	size_t	i;
	size_t	min_pos;

	min = INT_MAX;
	i = 0;
	min_pos = 0;
	while (i < size)
	{
		if (min < array[i])
		{
			min_pos = i;
			min = array[i];
		}
	}
	return (min_pos);
}
