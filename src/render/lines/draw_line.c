/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:51:43 by pablo             #+#    #+#             */
/*   Updated: 2025/03/23 23:43:52 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Draws a horizontal line on an image using Bresenham's line algorithm.
 *
 * This function draws a horizontal line on the given image using Bresenham's
 * line algorithm. It iterates over the x-coordinates and calculates the
 * corresponding y-coordinates to plot the line.
 *
 * @param delta An array of two integers representing the differences in x and y
 *              coordinates between the start and end points of the line.
 * @param dir The direction of the line in the y-axis. It should be either
 *            1 or -1.
 * @param p0 An array of two doubles representing the starting point (x, y)
 *           of the line.
 * @param img A pointer to the image where the line will be drawn.
 */
static void	draw_line_h_loop(int32_t *delta, int dir, double *p0,
		mlx_image_t *img)
{
	uint32_t	y;
	int32_t		p;
	int32_t		i;

	y = p0[1];
	p = 2 * delta[1] - delta[0];
	i = 0;
	while (i < delta[0] + 1)
	{
		if (is_within_bounds(p0[0] + i, y, img))
			mlx_put_pixel(img, p0[0] + i, y, GRAPH_COLOR);
		if (p >= 0)
		{
			y += dir;
			p = p - 2 * abs(delta[0]);
		}
		p = p + 2 * abs(delta[1]);
		++i;
	}
}

/**
 * @brief Draws a horizontal line between two points on an image.
 *
 * This function draws a horizontal line between two points (p0 and p1) on the
 * given image (img). It calculates the differences in the x and y coordinates
 * (delta) and determines the direction of the line. If the x-coordinate
 * difference (delta[0]) is not zero, it calls the draw_line_h_loop function to
 * draw the line. If delta[0] is zero, it prints an error message indicating
 * that the line could not be drawn.
 *
 * @param p0 A pointer to an array containing the x and y coordinates of the
 *           starting point.
 * @param p1 A pointer to an array containing the x and y coordinates of the
 *           ending point.
 * @param img A pointer to the image on which the line will be drawn.
 */
static void	draw_line_h(double *p0, double *p1, mlx_image_t *img)
{
	int32_t	delta[2];
	int		dir;

	if (p0[0] > p1[0])
		invert_coords(&p0[0], &p0[1], &p1[0], &p1[1]);
	delta[0] = p1[0] - p0[0];
	delta[1] = p1[1] - p0[1];
	dir = 1;
	if (delta[1] < 0)
		dir = -1;
	if (delta[0] != 0)
		draw_line_h_loop(delta, dir, p0, img);
}

/**
 * @brief Draws a vertical line on an image using Bresenham's line algorithm.
 *
 * This function draws a vertical line on the given image using Bresenham's line
 * algorithm. It iterates over the y-coordinates and calculates the
 * correspondingx-coordinates to plot the pixels.
 *
 * @param delta An array of two integers representing the differences in x and y
 *              coordinates between the start and end points of the line.
 * @param dir The direction in which to increment the x-coordinate
 *            (either 1 or -1).
 * @param p0 An array of two doubles representing the starting point (x, y)
 *           of the line.
 * @param img A pointer to the image on which the line will be drawn.
 */
static void	draw_line_v_loop(int32_t delta[], int dir, double *p0,
		mlx_image_t *img)
{
	uint32_t	x;
	int32_t		p;
	int32_t		i;

	x = p0[0];
	p = 2 * delta[0] - delta[1];
	i = 0;
	while (i < delta[1] + 1)
	{
		if (is_within_bounds(x, p0[1] + i, img))
			mlx_put_pixel(img, x, p0[1] + i, GRAPH_COLOR);
		if (p >= 0)
		{
			x += dir;
			p = p - 2 * abs(delta[1]);
		}
		p = p + 2 * abs(delta[0]);
		++i;
	}
}

/**
 * @brief Draws a vertical line on the given image.
 *
 * This function draws a vertical line from point p0 to point p1 on the provided
 * image. If p0 is below p1, the coordinates are inverted to ensure the line is
 * drawn from top to bottom. The function calculates the differences in the x
 * and y coordinates (delta) and determines the direction of the line. If the
 * line is not horizontal (delta[1] != 0), it calls draw_line_v_loop to draw
 * the line. If the line is horizontal, an error message is printed.
 *
 * @param p0 A pointer to the starting point coordinates (x0, y0).
 * @param p1 A pointer to the ending point coordinates (x1, y1).
 * @param img A pointer to the image where the line will be drawn.
 */
static void	draw_line_v(double *p0, double *p1, mlx_image_t *img)
{
	int32_t	delta[2];
	int		dir;

	if (p0[1] > p1[1])
		invert_coords(&p0[0], &p0[1], &p1[0], &p1[1]);
	delta[0] = p1[0] - p0[0];
	delta[1] = p1[1] - p0[1];
	dir = 1;
	if (delta[0] < 0)
		dir = -1;
	if (delta[1] != 0)
		draw_line_v_loop(delta, dir, p0, img);
}

void	draw_line(double *p0, double *p1, mlx_image_t *img)
{
	double	tmp_p0[2];
	double	tmp_p1[2];

	if (p0[0] > INT32_MAX || p0[1] > INT32_MAX || p1[0] > INT32_MAX
		|| p1[1] > INT32_MAX)
	{
		perror("Coordinates too large for line drawing algorithm");
		return ;
	}
	tmp_p0[0] = p0[0];
	tmp_p0[1] = p0[1];
	tmp_p1[0] = p1[0];
	tmp_p1[1] = p1[1];
	if (abs((int32_t)p1[0] - (int32_t)p0[0]) > abs((int32_t)p1[1]
			- (int32_t)p0[1]))
		draw_line_h(tmp_p0, tmp_p1, img);
	else
		draw_line_v(tmp_p0, tmp_p1, img);
}
