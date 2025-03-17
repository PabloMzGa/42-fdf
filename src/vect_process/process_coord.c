/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:28:36 by pabmart2          #+#    #+#             */
/*   Updated: 2025/03/17 19:17:42 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

t_map	*project_map(t_map *map, double *normal, double *p_point)
{
	t_map	*projected_map;
	size_t	map_size;
	size_t	i;

	projected_map = malloc(sizeof(t_map));
	if (!projected_map)
		return (perror("Error allocating  projected map"), NULL);
	map_size = map->size_x * map->size_y;
	projected_map->vertices = malloc(sizeof(double *) * map_size);
	if (!projected_map->vertices)
		return ((free(projected_map),
				perror("Error allocating projected vertices array"), NULL));
	i = 0;
	while (i < map_size)
	{
		projected_map->vertices[i] = ft_vect_ortproj(map->vertices[i], normal,
				p_point, 3);
		if (!projected_map->vertices[i])
			return (clean_porjected_map(i, projected_map),
				perror("Error projecting vector vector"), NULL);
		++i;
	}
	projected_map->size_x = map->size_x;
	projected_map->size_y = map->size_y;
	return (projected_map);
}

/**
 * @brief Sets the offset values based on the minimum UV coordinates.
 *
 * This function calculates the offset values for the UV coordinates.
 * If the minimum UV coordinate is negative, the offset is set to the
 * absolute value of the minimum UV coordinate. Otherwise, the offset
 * is set to zero.
 *
 * @param uv_min A pointer to an array containing the minimum UV coordinates.
 * @param uv_offset A pointer to an array where the calculated offset values
 *                  will be stored.
 */
static void	set_offset(double *uv_min, double *uv_offset)
{
	if (uv_min[0] < 0)
		uv_offset[0] = fabs(uv_min[0]);
	else
		uv_offset[0] = 0;
	if (uv_min[1] < 0)
		uv_offset[1] = fabs(uv_min[1]);
	else
		uv_offset[1] = 0;
}

/**
 * @brief Sets the range of the 2D map coordinates.
 *
 * This function calculates the range of the 2D map coordinates by finding the
 * maximum values in each column and subtracting the minimum values. If the
 * calculated range for any dimension is zero, it sets the range to 1 to avoid
 * division by zero errors.
 *
 * @param map2d A pointer to the 2D map array.
 * @param map_size The size of the 2D map.
 * @param uv_min An array containing the minimum values for the u and v
 *               coordinates.
 * @param uv_range An array to store the calculated range for the u and v
 *                 coordinates.
 */
static void	set_range(double **map2d, size_t map_size, double uv_min[],
		double *uv_range)
{
	uv_range[0] = ft_matrix_maxcol(map2d, map_size, 0) - uv_min[0];
	uv_range[1] = ft_matrix_maxcol(map2d, map_size, 1) - uv_min[1];
	if (uv_range[0] == 0)
		uv_range[0] = 1;
	if (uv_range[1] == 0)
		uv_range[1] = 1;
}

/**
 * @brief Transforms a 2D map of coordinates to screen coordinates.
 *
 * This function takes a 2D map of coordinates and transforms them to fit within
 * the screen dimensions specified by the width (w) and height (h).
 * The transformation includes scaling and centering the coordinates on the
 * screen.
 *
 * @param map2d A double pointer to the 2D map of coordinates.
 * @param w The width of the screen.
 * @param h The height of the screen.
 * @param map_size The number of points in the 2D map.
 */
static void	map2d_to_screen(double **map2d, t_gmap *gmap)
{
	double	uv_min[2];
	double	uv_offset[2];
	double	uv_range[2];
	size_t	i;
	size_t	map_size;

	map_size = gmap->map->size_x * gmap->map->size_y;
	uv_min[0] = ft_matrix_mincol(map2d, map_size, 0);
	uv_min[1] = ft_matrix_mincol(map2d, map_size, 1);
	set_range(map2d, map_size, uv_min, uv_range);
	if (gmap->scale_factor == 0)
		gmap->scale_factor = fmin((WIDTH * 0.8) / uv_range[0], (HEIGHT * 0.8)
				/ uv_range[1]);
	i = 0;
	set_offset(uv_min, uv_offset);
	while (i < map_size)
	{
		map2d[i][0] = (map2d[i][0] + uv_offset[0]) * gmap->scale_factor + (WIDTH
				- uv_range[0] * gmap->scale_factor) / 2;
		map2d[i][1] = (HEIGHT - 1) - ((map2d[i][1] + uv_offset[1])
				* gmap->scale_factor + (HEIGHT - uv_range[1]
					* gmap->scale_factor) / 2);
		++i;
	}
}

t_map	*set_2d_map(t_gmap *gmap)
{
	t_map	*projected_map;
	t_map	*projected_2d;
	double	*normal;

	if (!gmap || !gmap->map)
		return (NULL);
	normal = set_camera_normal(gmap);
	projected_map = project_map(gmap->map, normal, gmap->p_point);
	if (!projected_map)
		return (free(normal), NULL);
	projected_2d = create_2d_map(projected_map, normal, gmap->p_point);
	if (!projected_2d)
		return (free(normal), clean_map(projected_map), NULL);
	map2d_to_screen(projected_2d->vertices, gmap);
	clean_map(projected_map);
	free(normal);
	return (projected_2d);
}
