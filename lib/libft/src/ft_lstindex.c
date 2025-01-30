/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:21:38 by pabmart2          #+#    #+#             */
/*   Updated: 2025/01/30 20:35:23 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_lstindex(t_list *lst, unsigned int index)
{
	unsigned int	count;

	count = 0;
	while (lst && count < index)
	{
		count++;
		lst = lst->next;
	}
	return (lst->content);
}
