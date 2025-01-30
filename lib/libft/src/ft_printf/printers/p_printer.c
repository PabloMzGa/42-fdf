/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_printer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:19:38 by pabmart2          #+#    #+#             */
/*   Updated: 2025/01/23 18:55:57 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf/ft_printf.h"

int	p_printer(va_list arg)
{
	void	*p;
	char	*str;
	size_t	len;

	p = va_arg(arg, void *);
	if (!p)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	str = ft_uintptrtob((uintptr_t)p, "0123456789abcdef");
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str) + 2;
	free(str);
	return (len);
}
