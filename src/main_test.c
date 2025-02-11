/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:30:14 by pabmart2          #+#    #+#             */
/*   Updated: 2025/02/11 22:54:04 by pablo            ###   ########.fr       */
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

void	draw_point(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color)
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

void	create_image(double **projected_2d, size_t size, mlx_t *mlx)
{
	mlx_image_t	*image;
	size_t		i;

	image = mlx_new_image(mlx, mlx->width, mlx->height);
	if (!image)
		return (perror("Error creating MLX image"));
	ft_memset(image->pixels, 15, image->width * image->height
		* sizeof(int32_t));
	i = 0;
	while (i < size)
	{
		draw_point(image, (uint32_t)projected_2d[i][0],
			(uint32_t)projected_2d[i][1], 0xffffff);
		++i;
	}
	// Display an instance of the image
	if (mlx_image_to_window(mlx, image, 0, 0) < 0)
		return (perror("Error displaying MLX image"));
}

/**
 * TODO: Comprobar leaks de memoria
 * TODO: Parece que algunos puntos se desplazan
 * TODO: Calculo de la cámara, posición y normal teniendo en cuenta la mitad
 * del tamaño del mapa para apuntar al centro.
 */
int	main(void)
{
	t_map	*map;
	t_map	*projected_map;
	double	**projected_2d;
	double	*normal;
	double	*p_point;
	double	*n_normal;
	mlx_t	*mlx;

	map = read_map("maps/test_maps/mars.fdf");

	p_point = set_p_point(map);
	normal = set_camera_normal(map, p_point);
	projected_map = project_map(map, normal, p_point);
	show_vertices(map);
	n_normal = ft_vect_norm(normal, 3);
	projected_2d = create_2d_map(projected_map, n_normal, p_point);
	map2d_to_screen(projected_2d, 1920, 1080, projected_map->size_x
		* projected_map->size_y);
	show_projected_2d(projected_2d, map->size_x, map->size_y);
	mlx_set_setting(MLX_DECORATED, 1);
	mlx = mlx_init(1920, 1080, "fdf_test", 1);
	// Configuración de los hooks
	mlx_key_hook(mlx, &exit_keyhook, mlx);
	create_image(projected_2d, map->size_x * map->size_y, mlx);
	mlx_loop(mlx);
	// Cierre del programa
	mlx_terminate(mlx);
	clean_matrix(projected_2d, map->size_x * map->size_y);
	clean_map(map);
	clean_map(projected_map);
	free(n_normal);
}
