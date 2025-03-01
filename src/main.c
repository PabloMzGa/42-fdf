/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:30:14 by pabmart2          #+#    #+#             */
/*   Updated: 2025/03/01 18:29:29 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h>

static t_map	*set_2d_map(char *map_path)
{
	t_map	*map;
	t_map	*projected_map;
	t_map	*projected_2d;
	double	*p_point;
	double	*normal;

	map = read_map(map_path);
	if (!map)
		return (NULL);
	p_point = set_p_point(map);
	normal = set_camera_normal(map, p_point);
	projected_map = project_map(map, normal, p_point);
	projected_2d = create_2d_map(projected_map, normal, p_point);
	map2d_to_screen(projected_2d->vertices, 1920, 1080, projected_map->size_x
		* projected_map->size_y);
	clean_map(map);
	clean_map(projected_map);
	free(normal);
	return (projected_2d);
}

/**
 * TODO: Comprobar leaks de memoria
 * TODO: Parece que algunos puntos se desplazan
 * TODO: Calculo de la cámara, posición y normal teniendo en cuenta la mitad
 * del tamaño del mapa para apuntar al centro. UPDATE: A medio hacer
 */
int	main(int argc, char **argv)
{
	mlx_t	*mlx;
	t_map	*screen_map;

	if (!argv[1])
		return (perror("Error: no map path detected"), 1);
	screen_map = set_2d_map(argv[1]);
	if (!screen_map)
		return (1);
	mlx_set_setting(MLX_DECORATED, 1);
	mlx = mlx_init(1920, 1080, "fdf_test", 1);
	mlx_key_hook(mlx, &exit_keyhook, mlx);
	create_image(screen_map, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	clean_map(screen_map);
}
