/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:59:18 by pabmart2          #+#    #+#             */
/*   Updated: 2024/11/21 18:32:24 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf/ft_printf.h"

static int	call_printer(char const *str, va_list args)
{
	int			char_counter;
	t_printer	printer;

	char_counter = 0;
	printer = check_printer(*(str));
	if (printer)
		char_counter += printer(args);
	else
	{
		ft_putchar_fd('%', 1);
		ft_putchar_fd(*str, 1);
		char_counter += 2;
	}
	return (char_counter);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		char_counter;

	char_counter = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);
			++char_counter;
		}
		else
			char_counter += call_printer(++str, args);
		++str;
	}
	va_end(args);
	return (char_counter);
}
