/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:51:43 by pablo             #+#    #+#             */
/*   Updated: 2025/03/18 12:45:06 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	invert_coords(double *x0, double *y0, double *x1, double *y1)
{
	double	temp;

	temp = *x0;
	*x0 = *x1;
	*x1 = temp;
	temp = *y0;
	*y0 = *y1;
	*y1 = temp;
}

bool	is_within_bounds(int32_t x, int32_t y, mlx_image_t *img)
{
	return (x >= 0 && y >= 0 && x < (int32_t)img->width
		&& y < (int32_t)img->height);
}
