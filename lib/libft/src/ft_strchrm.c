/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:06:55 by pabmart2          #+#    #+#             */
/*   Updated: 2025/03/13 20:27:07 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrm(const char *s, char *c)
{
	unsigned char	*uc;
	size_t			i;

	uc = malloc(sizeof(unsigned char) * (ft_strlen(c) + 1));
	if (!uc)
		return (perror("Error allocating uc in ft_strchrm"), NULL);
	i = 0;
	while ((char)c[i])
	{
		uc[i] = (unsigned char)c[i];
		++i;
	}
	uc[i] = '\0';
	while (*s)
	{
		if (ft_strchr((const char *)uc, *s))
			return (free(uc), (char *)s);
		s++;
	}
	if (*uc == '\0')
		return (free(uc), (char *)s);
	return (free(uc), NULL);
}
