/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:49:48 by pabmart2          #+#    #+#             */
/*   Updated: 2025/01/30 21:00:54 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*temp_dest;
	const char	*temp_src;

	if (!dest && !src)
		return (NULL);
	temp_dest = (char *)dest;
	temp_src = (const char *)src;
	while (n--)
		*(temp_dest++) = *(temp_src++);
	return (dest);
}
