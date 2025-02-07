/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:30:14 by pabmart2          #+#    #+#             */
/*   Updated: 2025/02/07 18:15:39 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h>

void	show_vertices(t_map *map)
{
	for (size_t i = 0; i < map->size_x * map->size_y; i++)
	{
		printf("Vertex %zu: (%f, %f, %f)\n", i, map->vertices[i][0],
			map->vertices[i][1], map->vertices[i][2]);
	}
}

void	show_projected_2d(double **projected_2d, size_t size_x, size_t size_y)
{
    for (size_t i = 0; i < size_x * size_y; i++)
    {
        printf("Projected Vertex %zu: (%f, %f)\n", i, projected_2d[i][0],
            projected_2d[i][1]);
    }
}

int	main(void)
{
	t_map	*map;
	t_map	*projected_map;
	double	**projected_2d;
	double	normal[3] = {1, 2, 3};
	double	p_point[3] = {4, 5, 6};
	double *n_normal;

	mlx_t *mlx;

	map = read_map("maps/test_maps/10-2.fdf");
	projected_map = project_map(map, normal, p_point);

	n_normal = ft_vect_norm(normal, 3);
	projected_2d  = create_2d_map(projected_map, n_normal, p_point);
	show_vertices(map);
	show_projected_2d(projected_2d, map->size_x, map->size_y);

	mlx_set_setting(MLX_DECORATED, 1);
	mlx = mlx_init(1920, 1080, "fdf_test", 1);
	// Configuración de los hooks
	mlx_key_hook(mlx, &exit_keyhook, mlx);
	mlx_loop(mlx);
	// Cierre del programa
	mlx_terminate(mlx);

	clean_matrix(projected_2d, map->size_x * map->size_y);
	clean_map(map);
	clean_map(projected_map);
	free(n_normal);
}
