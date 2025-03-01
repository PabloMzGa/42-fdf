/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:51:43 by pablo             #+#    #+#             */
/*   Updated: 2025/03/01 17:44:08 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line_h_loop(int32_t *delta, int dir, uint32_t x0, uint32_t y0,
		mlx_image_t *img)
{
	uint32_t	y;
	int32_t		p;
	size_t		i;

	y = y0;
	p = 2 * delta[1] - delta[0];
	i = 0;
	while (i < delta[0] + 1)
	{
		mlx_put_pixel(img, x0 + i, y, GRAPH_COLOR);
		if (p >= 0)
		{
			y += dir;
			p = p - 2 * abs(delta[0]);
		}
		p = p + 2 * abs(delta[1]);
		++i;
	}
}

static void	draw_line_h(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1,
		mlx_image_t *img)
{
	int32_t	delta[2];
	int		dir;

	if (x0 > x1)
		invert_coords(&x0, &y0, &x1, &y1);
	delta[0] = x1 - x0;
	delta[1] = y1 - y0;
	dir = 1;
	if (delta[1] < 0)
		dir = -1;
	if (delta[0] != 0)
		draw_line_h_loop(delta, dir, x0, y0, img);
	else
		perror("The line couldn't be drawn, delta_x = 0");
}

static void	draw_line_v_loop(int32_t delta[], int dir, uint32_t x0, uint32_t y0,
		mlx_image_t *img)
{
	uint32_t	x;
	int32_t		p;
	size_t		i;

	x = x0;
	p = 2 * delta[0] - delta[1];
	i = 0;
	while (i < delta[1] + 1)
	{
		mlx_put_pixel(img, x, y0 + i, GRAPH_COLOR);
		if (p >= 0)
		{
			x += dir;
			p = p - 2 * abs(delta[1]);
		}
		p = p + 2 * abs(delta[0]);
		++i;
	}
}

static void	draw_line_v(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1,
		mlx_image_t *img)
{
	int32_t	delta[2];
	int		dir;

	if (y0 > y1)
		invert_coords(&x0, &y0, &x1, &y1);
	delta[0] = x1 - x0;
	delta[1] = y1 - y0;
	dir = 1;
	if (delta[0] < 0)
		dir = -1;
	if (delta[1] != 0)
		draw_line_v_loop(delta, dir, x0, y0, img);
	else
		perror("The line couldn't be drawn, delta_x = 0");
}

void	draw_line(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1,
		mlx_image_t *img)
{
	// Comprobar que las coordenadas están dentro del rango seguro
	if (x0 > INT32_MAX || x1 > INT32_MAX || y0 > INT32_MAX || y1 > INT32_MAX)
	{
		perror("Coordinates too large for line drawing algorithm");
		return ;
	}
	if (abs((int32_t)x1 - (int32_t)x0) > abs((int32_t)y1 - (int32_t)y0))
		draw_line_h(x0, y0, x1, y1, img);
	else
		draw_line_v(x0, y0, x1, y1, img);
}
