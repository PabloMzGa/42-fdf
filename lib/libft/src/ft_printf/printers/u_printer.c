/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_printer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:57:48 by pabmart2          #+#    #+#             */
/*   Updated: 2025/01/23 18:56:11 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf/ft_printf.h"

int	u_printer(va_list arg)
{
	char			*str;
	unsigned int	un;
	size_t			len;

	un = (unsigned int)va_arg(arg, int);
	str = ft_uitoa(un);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}
