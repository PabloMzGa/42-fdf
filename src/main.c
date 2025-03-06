/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:30:14 by pabmart2          #+#    #+#             */
/*   Updated: 2025/03/04 13:37:35 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	mlx_t	*mlx;
	t_map	*screen_map;
	t_map	*map;

	if (!argv[1])
		return (perror("Error: no map path detected"), 1);
	map = read_map(argv[1]);
	double	*p_point;
	p_point = set_p_point(map);
	screen_map = set_2d_map(map, p_point);
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
