/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:04:01 by pabmart2          #+#    #+#             */
/*   Updated: 2024/11/21 18:31:10 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*temp_dest;
	const unsigned char	*temp_src;

	if (dest == src || n == 0)
		return (dest);
	if (src < dest && dest < src + n)
	{
		temp_dest = (unsigned char *)dest + n;
		temp_src = (unsigned char *)src + n;
		while (n--)
			*(--temp_dest) = *(--temp_src);
		return (dest);
	}
	return (ft_memcpy(dest, src, n));
}
