/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:30:18 by pablo             #+#    #+#             */
/*   Updated: 2025/03/13 19:02:13 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Executes the Bresenham's line algorithm to draw lines between vertices.
 *
 * This function uses the Bresenham's line algorithm to draw lines between
 * vertices in a given map. It draws horizontal lines between consecutive
 * vertices and vertical lines between vertices in consecutive rows.
 *
 * @param xy An array of two size_t values representing the current x and y
 *           coordinates in the map.
 * @param i The index of the current vertex in the map's vertices array.
 * @param img A pointer to the mlx_image_t structure where the lines will
 *            be drawn.
 * @param map A pointer to the t_map structure containing the map's vertices
 *            and size.
 */
static void	bresenham_algo(size_t xy[2], size_t i, mlx_image_t *img, t_map *map)
{
	size_t	size;

	size = map->size_x * map->size_y;
	if (xy[0] < map->size_x && i < size - 1)
	{
		draw_line(map->vertices[i], map->vertices[i + 1], img);
		++(xy[0]);
	}
	else
		xy[0] = 1;
	if (xy[1] < map->size_y)
	{
		draw_line(map->vertices[i], map->vertices[i
			+ map->size_x], img);
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
 * @brief Adds an image to the graphical map (gmap) if it doesn't already exist.
 *
 * This function checks if the image in the gmap structure is NULL. If it is,
 * it creates a new image using the mlx_new_image function with the width and
 * height of the mlx structure within gmap. It then attempts to display the
 * image in the window using mlx_image_to_window. If this operation fails, it
 * prints an error message using perror.
 *
 * @param gmap Pointer to the graphical map structure (t_gmap) which contains
 *             the image and mlx information.
 */
static void	add_image(t_gmap *gmap)
{
	if (!gmap->img)
	{
		gmap->img = mlx_new_image(gmap->mlx, gmap->mlx->width,
				gmap->mlx->height);
		if (mlx_image_to_window(gmap->mlx, gmap->img, 0, 0) < 0)
			return (perror("Error displaying MLX image"));
	}
}

void	render_map(t_map *map, t_gmap *gmap)
{
	size_t	i;
	size_t	xy[2];

	add_image(gmap);
	if (!gmap->img)
		return (perror("Error creating MLX image"));
	ft_memset(gmap->img->pixels, BACKGROUND_COLOR, gmap->img->width
		* gmap->img->height * sizeof(int32_t));
	i = 0;
	xy[0] = 1;
	xy[1] = 1;
	while (i < map->size_x * map->size_y)
	{
		draw_point(gmap->img, (uint32_t)map->vertices[i][0],
			(uint32_t)map->vertices[i][1], GRAPH_COLOR);
		bresenham_algo(xy, i, gmap->img, map);
		++i;
		if (i >= map->size_x && i % map->size_x == 0)
			++xy[1];
	}
	clean_map(map);
}
