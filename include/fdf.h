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

# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "MLX42/MLX42.h"
# include "MLX42/MLX42_Int.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846264338327950288
# endif

/**
 * Scale of each dot of the grid. 0 means the dots size will be
 * equivalent to a single pixel
 */
# define POINT_RADIUS 0
/**
 * Color of the graph
 */
# define GRAPH_COLOR 0xFFFFFFF5
/**
 * Background color of  the graph
 */
# define BACKGROUND_COLOR 0x00000000
/**
 * Multiplier for the Z coordenate
 */
# define Z_MULTIPLIER 1
/**
 * The space between each point in XY
 */
# define SPACING 10
/**
 * Define how much degrees the model should rotate every frame
 */
# define ROT_DEG 0.5
# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_map
{
	double		**vertices;
	size_t		size_x;
	size_t		size_y;
}				t_map;

typedef struct s_global_map
{
	t_map		*map;
	double		*p_point;
	double		*center;
	mlx_t		*mlx;
	mlx_image_t	*img;
	double		scale_factor;
}				t_gmap;

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
void			exit_keyhook(mlx_key_data_t keydata, void *param);

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
t_map			*read_map(char *path);

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
t_map			*project_map(t_map *map, double *normal, double *a_point);

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
 * @return A t_map struct containing the size of p_map and the 2d vectors
 *
 * @note The caller is responsible for freeing the memory allocated for the
 * projected map and its vertices.
 */
t_map			*create_2d_map(t_map *p_map, double *normal, double *p_point);

/**
 * @brief Sets the camera normal vector based on the given gmap structure.
 *
 * This function calculates the normal vector for the camera by subtracting
 * the center point of the gmap from the p_point of the gmap. The resulting
 * vector is then normalized.
 *

 * @param gmap A pointer to the gmap structure containing the center and p_point.
 * @return A pointer to the normalized normal vector. The caller is responsible
 *         for freeing the returned pointer.
 */
double			*set_camera_normal(t_gmap *gmap);

/**
 * @brief Projects a 3D map to a 2D map and maps it to screen coordinates.
 *
 * This function takes a 3D map and projects it into a 2D map using the camera
 * normal and reference point. It then maps the 2D coordinates to screen
 * coordinates with a resolution of 1920x1080. The original map and intermediate
 * projected map are cleaned up before returning the final 2D map.
 *
 * @param map Pointer to the original 3D map structure.
 * @param p_point Pointer to the camera position or reference point.
 * @return Pointer to the final 2D map structure, or NULL if the input map is
 *         NULL.
 */
t_map			*set_2d_map(t_gmap *gmap);

/**
 * @brief Sets the perspective point for the map.
 *
 * This function calculates the perspective point (p_point) for the given map.
 * The perspective point is determined by taking the midpoint of the map's
 * width (size_x) and height (size_y), and half of the maximum value in the
 * third column of the map's vertices matrix.
 *
 * @param map Pointer to the map structure containing the map data.
 * @return A pointer to an array of three doubles representing the perspective
 *         point (p_point).
 * @note The caller is responsible for freeing the memory allocated for the
 * projected map and its vertices.
 */
double			*set_p_point(t_map *map);

//////////////////// RENDER //////////////////////////

/**
 * @brief Renders the map onto the global map (gmap) image.
 *
 * This function creates a new MLX image if it doesn't already exist, clears the
 * image to the background color, and then iterates through the map vertices to
 * draw points and lines using the Bresenham algorithm. Finally, it displays the
 * image in the MLX window.
 *
 * @param map Pointer to the map structure containing the vertices and
 *            dimensions.
 * @param gmap Double pointer to the global map structure containing the MLX
 *             image and context.
 */
int				render_map(t_map *map, t_gmap *gmap);

/**
  * @brief Draws a line between two points on an image.
 *
 * This function determines whether to draw the line horizontally or vertically
 * based on the difference between the x and y coordinates. It ensures that the
 * coordinates are within a safe range before proceeding.
 *
 * It's based on the Bresenham's Line Algorithm
 *
 * @param p0 A pointer to an array containing the x and y coordinates of the
 *           first point.
 * @param p1 A pointer to an array containing the x and y coordinates of the
 *           second point.
 * @param img A pointer to the image where the line will be drawn.
 *
 * @note If any of the coordinates exceed INT32_MAX, an error message is printed
 *       and the function returns without drawing the line.
 */
void			draw_line(double p0[], double p1[], mlx_image_t *img);

//////////////////// HELPERS //////////////////////////
/**
 * @brief Inverts the coordinates of two points.
 *
 * This function swaps the x and y coordinates of two points.
 *
 * @param x0 Pointer to the x coordinate of the first point.
 * @param y0 Pointer to the y coordinate of the first point.
 * @param x1 Pointer to the x coordinate of the second point.
 * @param y1 Pointer to the y coordinate of the second point.
 */
void			invert_coords(double *x0, double *y0, double *x1, double *y1);

/**
 * @brief - Calculates the center coordinates of a given map.
 *
 * This function allocates memory for a 3-element array of doubles and
 * calculates the center coordinates of the map. The center coordinates
 * are determined by taking the midpoint of the map's width (size_x),
 * height (size_y), and the maximum z-coordinate value (max_z).
 *
 * @param map Pointer to the t_map structure containing the map data.
 * @return A pointer to a dynamically allocated array of doubles
 *         containing the center coordinates [center_x, center_y, center_z].
 *         Returns NULL if memory allocation fails.
 * @note The caller is responsible for freeing the memory allocated for the
 *       vector
 */
double			*get_center(t_map *map);

/**
 * @brief Allocates and initializes a 2D map structure.
 *
 * This function allocates memory for a new t_map structure, initializes its
 * vertices with the provided 2D array, and copies the size information from
 * the original map. If memory allocation fails, it prints an error message
 * and returns NULL.
 *
 * @param p_map Pointer to the original map structure containing size
 *              information.
 * @param vects_2d 2D array of vertices to be assigned to the new map.
 * @return Pointer to the newly allocated and initialized t_map structure,
 *         or NULL if memory allocation fails.
 */
t_map			*alloc_2d_map(t_map *p_map, double **vects_2d);

//////////////////// CLEAN UTILS //////////////////////

/**
 * @brief Frees the memory allocated for a t_map structure.
 *
 * This function iterates through the vertices array in the t_map structure,
 * freeing each individual vertex. After all vertices are freed, it frees the
 * vertices array itself and finally frees the t_map structure.
 *
 * @param map Pointer to the t_map structure to be cleaned.
 */
void			clean_map(t_map *map);

/**
 * @brief Cleans up and frees memory allocated for a t_smap structure.
 *
 * This function first calls clean_map to free the memory allocated for the map
 * within the t_smap structure. It then frees the memory allocated for the
 * p_point and finally frees the t_smap structure itself.
 *
 * @param smap Pointer to the t_smap structure to be cleaned up.
 */
void			clean_gmap(t_gmap *smap);

/**
 * @brief Frees the memory allocated for the projected vertices and the
 * projected map.
 *
 * This function iterates through the projected vertices array in reverse
 * order, freeing each vertex. After all vertices are freed, it frees the
 * array itself and finally the projected map structure.
 *
 * @param i The number of vertices in the projected map.
 * @param projected_map Pointer to the projected map structure containing the
 *                      vertices to be freed.
 */
void			clean_porjected_map(size_t i, t_map *projected_map);

//////////////////// WRAPPERS //////////////////////

/**
 * @brief Wrapper function to perform rotation on a given map.
 *
 * This function serves as a wrapper to the rotate function, casting the
 * provided parameter to the appropriate type and passing it to the rotate
 * function.
 *
 * @param param A void pointer to the parameter that will be cast to a
 *              t_gmap type and passed to the rotate function.
 */
void			rotate_wrapper(void *param);

#endif
