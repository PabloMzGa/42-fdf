/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:30:14 by pabmart2          #+#    #+#             */
/*   Updated: 2025/03/06 21:38:51 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>

int	main(int argc, char **argv)
{
	mlx_t	*mlx;
	t_gmap	*gmap;
	t_map	*map;
	t_map	*initial_2dmap;

	if (!argv[1])
		return (perror("Error: no map path detected"), 1);
	gmap = malloc(sizeof(gmap));
	if(!gmap)
		return(perror("Error allocating gmap"), 1);
	map = read_map(argv[1]);
	gmap->p_point = set_p_point(map);
	gmap->center = get_center(map);
	gmap->map = map;
	initial_2dmap = set_2d_map(gmap);
	if (!initial_2dmap)
		return (1);
	mlx_set_setting(MLX_DECORATED, 1);
	mlx = mlx_init(1920, 1080, "fdf_test", 0);
	gmap->mlx = mlx;
	render_map(initial_2dmap, mlx);
	mlx_key_hook(mlx, &exit_keyhook, mlx);
	mlx_loop_hook(mlx, &rotate_wrapper, &gmap);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
