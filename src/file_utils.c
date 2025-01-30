/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabmart2 <pabmart2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:05:27 by pabmart2          #+#    #+#             */
/*   Updated: 2025/01/30 21:06:50 by pabmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	print_vertices(t_map *map)
{
	t_vert	vertex;

	for (int i = 0; i < map->size_y; i++)
	{
		for (int j = 0; j < map->size_x; j++)
		{
			vertex = map->vertices[i * map->size_x + j];
			printf("Vertex at (%d, %d): x = %d, y = %d, z = %d\n", i, j,
				vertex.x, vertex.y, vertex.z);
		}
	}
}

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
t_vert	create_vert(int x, int y, int z)
{
	t_vert	vert;

	vert.x = x;
	vert.y = y;
	vert.z = z;
	ft_printf("Vertice creado {%d, %d, %d}\n", x, y, z);
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
t_map	*process_line(char *line, t_map *map, int y, size_t *map_size)
{
	int	x;

	x = 0;
	map->vertices[*map_size] = create_vert(x, y, ft_atoi(line));
	++(*map_size);
	++x;
	while (*line)
	{
		if (*line == ' ')
		{
			map->vertices = ft_realloc(map->vertices, *map_size, ((*map_size)
						+ 1) * sizeof(t_vert));
			map->vertices[*map_size] = create_vert(x++, y, ft_atoi(line));
			(*map_size)++;
		}
		++line;
	}
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
t_map	*process_file(int fd, t_map *map)
{
	char	*line;
	int		y;
	size_t	map_size;

	map_size = 0;
	y = 0;
	line = ft_get_next_line(fd);
	while (line)
	{
		map = process_line(line, map, y, &map_size);
		line = ft_get_next_line(fd);
		++y;
	}
	// map->size_y = y;
	print_vertices(map);
	return (map);
}

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
t_map	*read_map(char *path)
{
	int		fd;
	t_map	*map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening the file");
		return (NULL);
	}
	map = malloc(sizeof(t_map));
	if (!map)
	{
		perror("Error allocating the map");
		return (NULL);
	}
	map->vertices = malloc(sizeof(t_vert));
	map->size_x = 0;
	map->size_y = 0;
	return (process_file(fd, map));
}
