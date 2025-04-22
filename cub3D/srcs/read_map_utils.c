/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:40:37 by nbonnet           #+#    #+#             */
/*   Updated: 2025/04/18 15:24:26 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map_read(t_map *map, int *map_started, int *map_info_count)
{
	map->map_2d = malloc(sizeof(char *) * 1024);
	map->len_x = 0;
	map->len_y = 0;
	map->coor_y = 0;
	map->no_tex = NULL;
	map->so_tex = NULL;
	map->we_tex = NULL;
	map->ea_tex = NULL;
	map->rgb_floor = NULL;
	map->rgb_ceiling = NULL;
	(*map_info_count) = 0;
	(*map_started) = 0;
}

int	process_map_line(char *line, t_map *map, int *map_info_count,
		int *map_started)
{
	int	ret;

	if (!*map_started)
	{
		ret = handle_pre_map_content(line, map, map_info_count);
		if (ret == 0)
		{
			printf("Error: loading pre-map content\n");
			return (0);
		}
		if (ret == 2)
			*map_started = 1;
	}
	else if (!handle_map_content(line, map))
		return (0);
	return (1);
}

int	handle_map_content(char *line, t_map *map)
{
	if (is_empty_line(line))
	{
		printf("Error: empty line inside map\n");
		return (0);
	}
	strip_newline(line);
	map->map_2d[map->len_y++] = ft_strdup(line);
	if ((int)ft_strlen(line) > map->len_x)
		map->len_x = ft_strlen(line);
	return (1);
}

int	handle_pre_map_content(char *line, t_map *map, int *map_info_count)
{
	if (is_empty_line(line))
		return (1);
	else if (*map_info_count < 6)
	{
		if ((ft_strnstr(line, "WE", 3) && map->we_tex) || (ft_strnstr(line,
					"NO", 3) && map->no_tex) || (ft_strnstr(line, "SO", 3)
				&& map->so_tex) || (ft_strnstr(line, "EA", 3) && map->ea_tex)
			|| (ft_strnstr(line, "F", 1) && map->rgb_floor) || (ft_strnstr(line,
					"C", 1) && map->rgb_ceiling))
			return (0);
		read_textures(line, map, map_info_count);
		return (1);
	}
	else if (is_map_line(line))
	{
		strip_newline(line);
		map->map_2d[map->len_y++] = ft_strdup(line);
		if ((int)ft_strlen(line) > map->len_x)
			map->len_x = ft_strlen(line);
		return (2);
	}
	printf("Error: Unexpected line before map: %s\n", line);
	return (0);
}

void	pad_map(t_map *map)
{
	int		i;
	char	*padded;

	i = 0;
	while (i < map->len_y)
	{
		if ((int)ft_strlen(map->map_2d[i]) < map->len_x)
		{
			padded = create_padded_line(map->map_2d[i], map->len_x);
			if (padded)
			{
				free(map->map_2d[i]);
				map->map_2d[i] = padded;
			}
		}
		i++;
	}
}
