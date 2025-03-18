/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:30:14 by pabmart2          #+#    #+#             */
/*   Updated: 2025/03/18 13:00:28 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

t_gmap	*gmap_init(char *path)
{
	t_gmap	*gmap;

	gmap = malloc(sizeof(t_gmap));
	if (!gmap)
		return (perror("Error allocating gmap"), NULL);
	gmap->img = NULL;
	gmap->map = read_map(path);
	if (!gmap->map)
		return (free(gmap), NULL);
	gmap->p_point = set_p_point(gmap->map);
	if (!gmap->p_point)
		return (clean_gmap(gmap), NULL);
	gmap->center = get_center(gmap->map);
	if (!gmap->center)
		return (clean_gmap(gmap), NULL);
	gmap->scale_factor = 0;
	return (gmap);
}

static void	exit_fdf(t_gmap *gmap, mlx_t *mlx)
{
	mlx_terminate(mlx);
	clean_gmap(gmap);
}

int	main(int argc, char **argv)
{
	mlx_t	*mlx;
	t_gmap	*gmap;
	t_map	*initial_2dmap;

	if (argc != 2)
		return (perror("Invalid argument count"), 1);
	if (!argv[1])
		return (perror("Error: no map path detected"), 1);
	gmap = gmap_init(argv[1]);
	if (!gmap)
		return (1);
	initial_2dmap = set_2d_map(gmap);
	if (!initial_2dmap)
		return (clean_gmap(gmap), 1);
	mlx_set_setting(MLX_DECORATED, 1);
	mlx = mlx_init(WIDTH, HEIGHT, "fdf", 0);
	gmap->mlx = mlx;
	if (render_map(initial_2dmap, gmap) != 0)
		exit_fdf(gmap, mlx);
	mlx_key_hook(mlx, &exit_keyhook, mlx);
	mlx_loop_hook(mlx, &rotate_wrapper, gmap);
	mlx_scroll_hook(mlx, &zoom_wrapper, gmap);
	mlx_loop(mlx);
	exit_fdf(gmap, mlx);
}
