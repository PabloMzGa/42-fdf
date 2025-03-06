/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:30:18 by pablo             #+#    #+#             */
/*   Updated: 2025/03/06 21:42:47 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	bresenham_algo(size_t xy[2], size_t i, mlx_image_t *img,
		t_map *map)
{
	size_t	size;

	size = map->size_x * map->size_y;
	if (xy[0] < map->size_x && i < size - 1)
	{
		draw_line((uint32_t)map->vertices[i][0], (uint32_t)map->vertices[i][1],
			(uint32_t)map->vertices[i + 1][0], (uint32_t)map->vertices[i
			+ 1][1], img);
		++(xy[0]);
	}
	else
		xy[0] = 1;
	if (xy[1] < map->size_y)
	{
		draw_line((uint32_t)map->vertices[i][0], (uint32_t)map->vertices[i][1],
			(uint32_t)map->vertices[i + map->size_x][0],
			(uint32_t)map->vertices[i + map->size_x][1], img);
	}
}

/**
 * @brief Draws a point on the given image with a specified color.
 *
 * This function draws a point on the provided image at the specified (x, y)
 * coordinates with the given color. The point is drawn with a radius defined
 * by the macro POINT_RADIUS, resulting in a filled circle of pixels.
 *
 * @param img Pointer to the image where the point will be drawn.
 * @param x The x-coordinate of the center of the point.
 * @param y The y-coordinate of the center of the point.
 * @param color The color of the point to be drawn.
 */
static void	draw_point(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color)
{
	int	i;
	int	j;

	i = -POINT_RADIUS;
	j = -POINT_RADIUS;
	while (i <= POINT_RADIUS)
	{
		while (j <= POINT_RADIUS)
		{
			if (img->width > x + j && x + j > 0 && img->height > y + i && y
				+ i > 0)
				mlx_put_pixel(img, x + j, y + i, color);
			++j;
		}
		++i;
		j = -POINT_RADIUS;
	}
}

/**
 * TODO: NEcesito reutilizar la imagen y no crear una nueva cada vez.
 * Para ello tengo que guardar el return de mlx_image_to_window. Creo
 * que lo mejor es almacenarlo en el gmap.
 *
 */
void	render_map(t_map *map, mlx_t *mlx)
{
	mlx_image_t	*img;
	size_t		size;
	size_t		i;
	size_t		xy[2];

	size = map->size_x * map->size_y;
	img = mlx_new_image(mlx, mlx->width, mlx->height);
	if (!img)
		return (perror("Error creating MLX image"));
	ft_memset(img->pixels, BACKGROUND_COLOR, img->width * img->height
		* sizeof(int32_t));
	i = 0;
	xy[0] = 1;
	xy[1] = 1;
	while (i < size)
	{
		draw_point(img, (uint32_t)map->vertices[i][0],
			(uint32_t)map->vertices[i][1], GRAPH_COLOR);
		bresenham_algo(xy, i, img, map);
		++i;
		if (i >= map->size_x && i % map->size_x == 0)
			++xy[1];
	}
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		return (perror("Error displaying MLX image"));
}
