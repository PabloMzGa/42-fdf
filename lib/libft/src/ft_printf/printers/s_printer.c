/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_printer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:15:53 by pabmart2          #+#    #+#             */
/*   Updated: 2025/01/23 18:56:15 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf/ft_printf.h"

int	s_printer(va_list arg)
{
	char	*str;

	str = (char *)va_arg(arg, int *);
	if (str)
	{
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	else
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
}
