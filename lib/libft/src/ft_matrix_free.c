/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:17:34 by pablo             #+#    #+#             */
/*   Updated: 2025/03/13 20:23:11 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_matrix_free(void **array, size_t size)
{
	size_t	i;

	i = 0;
	if (i > 0)
	{
		while (i < size)
		{
			free(array[i]);
			++i;
		}
	}
	else
	{
		while (array[i])
		{
			free(array[i]);
			++i;
		}
	}
	free(array);
}
