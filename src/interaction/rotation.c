/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:27:12 by pablo             #+#    #+#             */
/*   Updated: 2025/03/06 21:43:08 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * TODO: Puede que sea por el crear una imagen cada vez, pero parece que no
 * está rotando bien.
 */
void	rotate(t_gmap **gmap)
{
	t_map	*map_2d;
	double	radians;

	radians = ROT_DEG * M_PI / 180;
	(*gmap)->p_point = ft_vect_rotz3d((*gmap)->p_point, (*gmap)->center,
			radians);
	map_2d = set_2d_map((*gmap));
	render_map(map_2d, (*gmap)->mlx);
	clean_map(map_2d);
}

void	rotate_wrapper(void *param)
{
    rotate((t_gmap **)param);
}

