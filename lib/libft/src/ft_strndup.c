/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:01:49 by pabmart2          #+#    #+#             */
/*   Updated: 2024/11/23 21:03:54 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	char	*cpy;

	len = (size_t)(ft_strchr(s, '\0') - s + 1);
	if (n && n < len)
		len = n;
	cpy = malloc(len);
	if (!cpy)
		return (NULL);
	ft_memset(cpy, 0, len);
	ft_strlcat(cpy, s, len);
	return (cpy);
}
