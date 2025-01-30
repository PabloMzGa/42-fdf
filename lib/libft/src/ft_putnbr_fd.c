/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:39:17 by pabmart2          #+#    #+#             */
/*   Updated: 2024/11/21 18:31:10 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;

	if (n < 0)
	{
		un = (unsigned int)n * -1;
		ft_putchar_fd('-', fd);
	}
	else
		un = (unsigned int)n;
	if (un >= 10)
	{
		ft_putnbr_fd(un / 10, fd);
		ft_putchar_fd(un % 10 + '0', fd);
	}
	else
		ft_putchar_fd(un + '0', fd);
}
