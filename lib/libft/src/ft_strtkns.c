/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtkns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:18:39 by pabmart2          #+#    #+#             */
/*   Updated: 2024/11/23 20:42:08 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strtkns(char const *s, char *cs)
{
	size_t	counter;
	int		inside_token;

	counter = 0;
	inside_token = 0;
	while (*s)
	{
		if (ft_strchr(cs, *s) == NULL && !inside_token)
		{
			inside_token = 1;
			++counter;
		}
		else if (ft_strchr(cs, *s) != NULL)
			inside_token = 0;
		++s;
	}
	return (counter);
}
