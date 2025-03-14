/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:27:12 by pablo             #+#    #+#             */
/*   Updated: 2025/03/14 17:28:55 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

/**
 * @brief Rotates the 3D points in the given gmap structure around the Z-axis.
 *
 * This function performs a rotation transformation on the 3D points stored in
 * the gmap structure. The rotation is performed around the Z-axis by a fixed
 * angle defined by the macro ROT_DEG. The function then updates the 2D map
 * representation and renders the updated map.
 *
 * @param gmap Pointer to the gmap structure containing the 3D points and other
 * relevant data.
 */
static void	rotate(t_gmap *gmap)
{
	t_map	*map_2d;
	double	radians;
	double	*prev_p;

	radians = ROT_DEG * M_PI / 180;
	prev_p = gmap->p_point;
	gmap->p_point = ft_vect_rotz3d(gmap->p_point, gmap->center, radians);
	free(prev_p);
	map_2d = set_2d_map(gmap);
	if (!map_2d)
		return ;
	render_map(map_2d, gmap);
}

void	rotate_wrapper(void *param)
{
	rotate((t_gmap *)param);
}
