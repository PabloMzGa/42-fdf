/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:05:27 by pabmart2          #+#    #+#             */
/*   Updated: 2025/02/07 18:06:18 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

/**
 * @brief Creates a vertex with the given x, y, and z coordinates.
 *
 * This function initializes a t_vert structure with the provided
 * x, y, and z values and returns the initialized structure.
 *
 * @param x The x-coordinate of the vertex.
 * @param y The y-coordinate of the vertex.
 * @param z The z-coordinate of the vertex.
 * @return A t_vert structure initialized with the given coordinates.
 */
static double	*create_vert(int x, int y, int z)
{
	double	*vert;

	vert = malloc(sizeof(double) * 3);
	if (!vert)
		return (perror("Error allocating memory for vert"), NULL);
	vert[0] = x;
	vert[1] = y;
	vert[2] = z;
	return (vert);
}

/**
 * @brief Processes a line of input and updates the map structure with vertices.
 *
 * This function takes a line of input, parses it to extract vertex information,
 * and updates the map structure with the new vertices. It also updates the map
 * size and the x-dimension of the map.
 *
 * @param line The input line to be processed.
 * @param map The map structure to be updated.
 * @param y The y-coordinate for the vertices being processed.
 * @param map_size A pointer to the current size of the map, which will be
 *                 updated.
 * @return A pointer to the updated map structure.
 */
static t_map	*process_line(char *line, t_map *map, int y, size_t *map_size)
{
	size_t	x;

	x = 0;
	map->vertices[*map_size] = create_vert(x, y, ft_atoi(line));
	++(*map_size);
	++x;
	while (*line)
	{
		if (*line == ' ')
		{
			map->vertices = ft_realloc(map->vertices, (*map_size)
					* sizeof(double *), ((*map_size) + 1) * sizeof(double *));
			map->vertices[*map_size] = create_vert(x++, y, ft_atoi(line));
			(*map_size)++;
		}
		++line;
	}
	map->vertices = ft_realloc(map->vertices, (*map_size) * sizeof(double *),
			((*map_size) + 1) * sizeof(double *));
	map->size_x = x;
	return (map);
}

/**
 * @brief Processes a file and populates a t_map structure with its contents.
 *
 * This function reads lines from a file descriptor and processes each line to
 * populate a t_map structure. It uses the ft_get_next_line function to read
 * each line and the process_line function to process each line and update the
 * t_map structure.
 *
 * @param fd The file descriptor to read from.
 * @param map A pointer to the t_map structure to populate.
 * @return A pointer to the populated t_map structure.
 */
static t_map	*process_file(int fd, t_map *map)
{
	char	*line;
	size_t	y;
	size_t	map_size;

	map_size = 0;
	y = 0;
	line = ft_get_next_line(fd);
	while (line)
	{
		map = process_line(line, map, y, &map_size);
		free(line);
		line = ft_get_next_line(fd);
		++y;
	}
	map->size_y = y;
	// display_vertices(map);
	return (map);
}

t_map	*read_map(char *path)
{
	int		fd;
	t_map	*map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (perror("Error opening the file"), NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (perror("Error allocating the map"), NULL);
	map->vertices = malloc(sizeof(double *));
	if (!map->vertices)
		return (perror("Error allocating vertices array"), NULL);
	map->size_x = 0;
	map->size_y = 0;
	return (process_file(fd, map));
}
