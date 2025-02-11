/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:28:36 by pabmart2          #+#    #+#             */
/*   Updated: 2025/02/11 22:54:54 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h>

t_map	*project_map(t_map *map, double *normal, double *p_point)
{
	t_map	*projected_map;
	size_t	map_size;
	size_t	i;

	projected_map = malloc(sizeof(t_map));
	if (!project_map)
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
			// TODO: Cleanup de todo lo de arriba si falla
			return (perror("Error projecting vector vector"), NULL);
		++i;
	}
	projected_map->size_x = map->size_x;
	projected_map->size_y = map->size_y;
	return (projected_map);
}
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

/* double	**map2d_to_screen(double **map2d, size_t width, size_t heigth,
		size_t map_size)
{
	double	uv_min[2];
	double	uv_offset[2];
	double	uv_range[2];
	double	uv_scale[2];
	size_t	i;

	uv_min[0] = ft_matrix_mincol(map2d, map_size, 0);
	uv_min[1] = ft_matrix_mincol(map2d, map_size, 1);
	set_range(map2d, map_size, uv_min, uv_range);
	uv_scale[0] = (width - 1) / uv_range[0];
	uv_scale[1] = (heigth - 1) / uv_range[1];
	i = 0;
	set_offset(uv_min, uv_offset);
	while (i < map_size)
	{
		map2d[i][0] = (map2d[i][0] + uv_offset[0]) * uv_scale[0];
		map2d[i][1] = (heigth - 1) - ((map2d[i][1] + uv_offset[1])
				* uv_scale[1]);
		++i;
	}
	return (map2d);
} */

/**
 * TODO: Entender mejor esto
 * TODO: Documentar
 */

double	**map2d_to_screen(double **map2d, size_t w, size_t h, size_t map_size)
{
	double	uv_min[2];
    double	uv_offset[2];
    double	uv_range[2];
    double	scale_factor;
    size_t	i;

	uv_min[0] = ft_matrix_mincol(map2d, map_size, 0);
	uv_min[1] = ft_matrix_mincol(map2d, map_size, 1);
	set_range(map2d, map_size, uv_min, uv_range);
	scale_factor = fmin((w * 0.8) / uv_range[0], (h * 0.8) / uv_range[1]);
	i = 0;
	set_offset(uv_min, uv_offset);
	while (i < map_size)
	{
		map2d[i][0] = (map2d[i][0] + uv_offset[0]) * scale_factor + (w
				- uv_range[0] * scale_factor) / 2;
		map2d[i][1] = (h - 1) - ((map2d[i][1] + uv_offset[1]) * scale_factor
				+ (h - uv_range[1] * scale_factor) / 2);
		++i;
	}
	return (map2d);
}
