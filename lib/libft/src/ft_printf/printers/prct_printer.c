/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prct_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:15:53 by pabmart2          #+#    #+#             */
/*   Updated: 2025/01/23 18:56:00 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf/ft_printf.h"

int	prct_printer(va_list arg)
{
	(void)arg;
	ft_putchar_fd('%', 1);
	return (1);
}
