/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_magn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:55:22 by pablo             #+#    #+#             */
/*   Updated: 2025/03/13 20:22:05 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
double ft_vect_magn(double *vect, size_t d)
{
	size_t i;
	double res;

	res = 0;
	i = 0;
	while(i < d)
	{
		res += pow(vect[i], 2);
		++i;
	}
	res = sqrt(res);
	return(res);
}
