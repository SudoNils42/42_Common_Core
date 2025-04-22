/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:24:50 by nbonnet           #+#    #+#             */
/*   Updated: 2025/04/22 13:14:50 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_valid(t_map *map)
{
	if (!is_walled_in(map))
	{
		printf("Error: Map isnt walled in\n");
		return (0);
	}
	if (duplicate_player_elem(map))
		return (0);
	if (!check_map_chars(map))
		return (0);
	if (!valid_map_structure(map))
		return (0);
	return (1);
}

void	set_texture(char **texture, char *line, int offset, int *count)
{
	*texture = ft_strdup_trimmed(line + offset);
	(*count)++;
}

void	read_textures(char *line, t_map *map, int *map_info_count)
{
	if (ft_strnstr(line, "WE", 3))
		set_texture(&map->we_tex, line, 3, map_info_count);
	else if (ft_strnstr(line, "NO", 3))
		set_texture(&map->no_tex, line, 3, map_info_count);
	else if (ft_strnstr(line, "SO", 3))
		set_texture(&map->so_tex, line, 3, map_info_count);
	else if (ft_strnstr(line, "EA", 3))
		set_texture(&map->ea_tex, line, 3, map_info_count);
	else if (ft_strnstr(line, "F", 1))
		set_texture(&map->rgb_floor, line, 2, map_info_count);
	else if (ft_strnstr(line, "C", 1))
		set_texture(&map->rgb_ceiling, line, 2, map_info_count);
}

char	*create_padded_line(char *original, int target_len)
{
	char	*padded;
	int		i;
	int		orig_len;

	orig_len = ft_strlen(original);
	padded = malloc(target_len + 1);
	if (!padded)
		return (NULL);
	i = 0;
	while (i < orig_len)
	{
		padded[i] = original[i];
		i++;
	}
	while (i < target_len)
		padded[i++] = ' ';
	padded[i] = '\0';
	return (padded);
}

void	read_map(t_map *map, char **av)
{
	int		fd;
	char	*line;
	int		map_info_count;
	int		map_started;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Select a correct map path\n");
		exit(1) ;
	}
	init_map_read(map, &map_started, &map_info_count);
	line = get_next_line(fd);
	while (line)
	{
		if (!process_map_line(line, map, &map_info_count, &map_started))
		{
			free(line);
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	map->map_2d[map->len_y] = NULL;
	close(fd);
	pad_map(map);
}
