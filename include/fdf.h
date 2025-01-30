/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/6 12:44:52 by pabmart2          #+#    #+#             */
/*   Updated: 2024/11/29 17:55:45 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "MLX42/MLX42.h"
# include "MLX42/MLX42_Int.h"
# include "libft.h"
# include <fcntl.h>

# define IMAGE_SCALE 5
# define IMAGE_SPACING 40

typedef struct s_vertex
{
	int		x;
	int		y;
	int		z;
}			t_vert;

typedef struct s_map
{
	t_vert	*vertices;
	int		size_x;
	int		size_y;
}			t_map;

/////////////////// HOOKS ///////////////////////

/**
 * @brief Handles the key press event to close the window.
 *
 * This function is called when a key press event occurs. If the 'Escape' key
 * is pressed, it will close the window.
 *
 * @param keydata The key data containing information about the key event.
 * @param param A pointer to the window or application context.
 */
void		exit_keyhook(mlx_key_data_t keydata, void *param);

///////////////////// FILE UTILS //////////////////////

/**
 * @brief Reads a map from a file and converts it into a matrix of vertices.
 *
 * This function opens the file at the given path, reads its content line by
 * line, and converts each line into a list of vertices. It then combines these
 * lists into a matrix of vertices and returns it.
 *
 * @param path The path to the file containing the map.
 * @return A pointer to the matrix of vertices.
 */
t_map	*read_map(char *path);

#endif
