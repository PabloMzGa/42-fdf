/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:27:12 by pablo             #+#    #+#             */
/*   Updated: 2025/03/11 19:18:14 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	rotate(t_gmap **gmap)
{
	t_map	*map_2d;
	double	radians;

	radians = ROT_DEG * M_PI / 180;
	(*gmap)->p_point = ft_vect_rotz3d((*gmap)->p_point, (*gmap)->center,
			radians);
	map_2d = set_2d_map((*gmap));
	render_map(map_2d, gmap);
	printf("Frame %i\n", (*gmap)->debug_counter++);
	clean_map(map_2d);
}

void	rotate_wrapper(void *param)
{
    rotate((t_gmap **)param);
}

