/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:12:58 by pablo             #+#    #+#             */
/*   Updated: 2025/03/20 12:29:04 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Adjusts the zoom level of the graphical map.
 *
 * This function modifies the scale factor of the graphical map (gmap) based on
 * the input delta value (y_delta). The scale factor is adjusted by a factor of
 * ZOOM and the current scale factor. The resulting scale factor is then clamped
 * between the predefined minimum (MIN_SCALE) and maximum (MAX_SCALE) scale
 * values.
 *
 * @param y_delta The change in the zoom level, typically derived from user
 *                input.
 * @param gmap A pointer to the graphical map structure whose scale factor is
 *             to be adjusted.
 */
static void	zoom(double y_delta, t_gmap *gmap)
{

	gmap->scale_factor += y_delta * ZOOM * gmap->scale_factor;
	if (gmap->scale_factor < MIN_SCALE)
		gmap->scale_factor = MIN_SCALE;
	else if (gmap->scale_factor > MAX_SCALE)
		gmap->scale_factor = MAX_SCALE;
}

void	zoom_wrapper(double x_delta, double y_delta, void *param)
{
	(void)x_delta;
	zoom(y_delta, (t_gmap *)param);
}
