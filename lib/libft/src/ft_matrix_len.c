/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:17:34 by pablo             #+#    #+#             */
/*   Updated: 2025/02/11 21:17:51 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Calculates the length of a null-terminated array of pointers.
 *
 * This function iterates through the array of pointers until it encounters
 * a null pointer, counting the number of elements in the array.
 *
 * @param array A null-terminated array of pointers.
 * @return The number of elements in the array, excluding the null pointer.
 */
size_t	ft_matrix_len(void **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		++i;
	if (i > 0)
		return (i);
	return(0);
}
