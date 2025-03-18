/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:30:14 by pabmart2          #+#    #+#             */
/*   Updated: 2025/03/18 12:45:31 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <math.h>
#include <stdio.h>

t_gmap	*gmap_init(char *path)
{
	t_gmap	*gmap;

	gmap = malloc(sizeof(t_gmap));
	if (!gmap)
		return (perror("Error allocating gmap"), NULL);
	gmap->img = NULL;
	gmap->map = read_map(path);
	gmap->p_point = set_p_point(gmap->map);
	gmap->center = get_center(gmap->map);
	gmap->scale_factor = 0;
	return (gmap);
}

int	main(int argc, char **argv)
{
	mlx_t	*mlx;
	t_gmap	*gmap;
	t_map	*initial_2dmap;

	if(argc != 2)
		return (perror("Invalid argument count"), 1);
	if (!argv[1])
		return (perror("Error: no map path detected"), 1);
	gmap = gmap_init(argv[1]);
	initial_2dmap = set_2d_map(gmap);
	if (!initial_2dmap)
		return (1);
	mlx_set_setting(MLX_DECORATED, 1);
	mlx = mlx_init(WIDTH, HEIGHT, "fdf_test", 0);
	gmap->mlx = mlx;
	render_map(initial_2dmap, gmap);
	mlx_key_hook(mlx, &exit_keyhook, mlx);
	mlx_loop_hook(mlx, &rotate_wrapper, gmap);
	mlx_scroll_hook(mlx, &zoom_wrapper, gmap);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	clean_gmap(gmap);
}
