/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:49:48 by pabmart2          #+#    #+#             */
/*   Updated: 2025/01/30 20:36:52 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memjoin(void *m1, size_t n1, const void *m2, size_t n2)
{
	char		*temp_m1;
	const char	*temp_m2;
	char		*result;
	size_t		i;
	size_t		j;

	if (m1 == NULL || m2 == NULL)
		return (NULL);
	temp_m1 = (char *)m1;
	temp_m2 = (const char *)m2;
	result = malloc(n1 + n2);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (i < n1)
	{
		result[i] = temp_m1[i];
		++i;
	}
	while (j < n2)
		result[i++] = temp_m2[j++];
	return (result);
}
