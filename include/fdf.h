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

typedef struct s_map
{
	double	**vertices;
	size_t	size_x;
	size_t	size_y;
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

///////////////////// VERTEX PROCESSING //////////////////////

/**
 * read_map - Reads a map from a file and processes it.
 * @path: The path to the file to be read.
 *
 * This function opens the file specified by @path in read-only mode. If the
 * file cannot be opened, it prints an error message and returns NULL. It then
 * allocates memory for a t_map structure. If the memory allocation fails, it
 * prints an error message and returns NULL. It initializes the map's vertices
 * pointer and sets the size_x and size_y fields to 0. Finally, it processes
 * the file and returns the resulting map.
 *
 * Return: A pointer to the processed t_map structure, or NULL on failure.
 */
t_map		*read_map(char *path);

/**
 * @brief Projects the vertices of a map onto a plane defined by a normal vector
 * and a point.
 *
 * This function allocates memory for a new map structure and projects each
 * vertex of the input map onto a plane defined by the given normal vector and
 * point. The projected vertices are stored in the new map structure.
 *
 * @param map Pointer to the input map structure containing the vertices to be
 * projected.
 * @param normal Pointer to a double array representing the normal vector of the
 * projection plane.
 * @param a_point Pointer to a double array representing a point on the
 * projection plane.
 * @return Pointer to the newly allocated map structure containing the projected
 * vertices, or NULL if an error occurs during allocation or projection.
 *
 * @note The caller is responsible for freeing the memory allocated for the
 * projected map and its vertices.
 */
t_map	*project_map(t_map *map, double *normal, double *a_point);

/**
 * @brief Creates a 2D map from a 3D map using a normal vector and a
 *        reference point.
 * @param p_map Pointer to the 3D map structure containing vertices
 *        and dimensions.
 * @param normal Pointer to the normal vector used for projection.
 * @param p_point Pointer to the reference point used for projection.
 *
 * This function allocates memory for a 2D map and projects each vertex of the
 * 3D map onto a 2D plane defined by the normal vector and reference point.
 * The 3D map must be already projected onto the plane defined by normal and
 * p_point.
 *
 * It calculates the u and v vectors for the plane, then computes the dot
 * product of the difference vector with these u and v vectors to get the 2D
 * coordinates.
 *
 * @return Pointer to the 2D map (array of 2D vectors) on success,
 *         or NULL on failure.
 *
 * @note The caller is responsible for freeing the memory allocated for the
 * projected map and its vertices.
 */
double	**create_2d_map(t_map *p_map, double *normal, double *p_point);

//////////////////// CLEAN UTILS //////////////////////

/**
 * clean_map - Frees the memory allocated for a t_map structure.
 * @map: Pointer to the t_map structure to be cleaned.
 *
 * This function iterates through the vertices array in the t_map structure,
 * freeing each individual vertex. After all vertices are freed, it frees the
 * vertices array itself and finally frees the t_map structure.
 */
void	clean_map(t_map *map);

/**
 * @brief Frees the memory allocated for a 2D matrix.
 *
 * This function iterates through each row of the matrix, freeing the memory
 * allocated for each row, and then frees the memory allocated for the matrix
 * itself.
 *
 * @param matrix A pointer to the 2D matrix to be freed.
 * @param size The number of rows in the matrix.
 */
void	clean_matrix(double	**matrix, size_t size);

#endif
