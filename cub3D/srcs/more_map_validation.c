/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_map_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 11:58:13 by luccamourao       #+#    #+#             */
/*   Updated: 2025/04/18 15:33:41 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_rgb_valid(char *rgb)
{
	char	**split;
	int		count;
	int		r;
	int		g;
	int		b;

	if (!rgb)
		return (0);
	split = ft_split(rgb, ',');
	if (!split)
		return (0);
	count = 0;
	while (split[count])
		count++;
	if (count != 3)
		return (free_split(split), 0);
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (free_split(split), 0);
	return (free_split(split), 1);
}

int	is_valid_texture(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 5 || ft_strncmp(path + len - 4, ".xpm", 4) != 0)
	{
		printf("Error: Invalid texture extension for %s\n", path);
		return (0);
	}
	if (access(path, R_OK) != 0)
	{
		printf("Error accessing texture file\n");
		return (0);
	}
	return (1);
}

int	valid_map_structure(t_map *map)
{
	if (!map->no_tex || !map->so_tex || !map->we_tex || !map->ea_tex)
		return (printf("Missing texture path\n"), 0);
	if (!map->rgb_floor || !map->rgb_ceiling)
		return (printf("Missing RGB colors\n"), 0);
	if (!is_rgb_valid(map->rgb_floor) || !is_rgb_valid(map->rgb_ceiling))
		return (0);
	if (!is_valid_texture(map->no_tex) || !is_valid_texture(map->so_tex)
		|| !is_valid_texture(map->we_tex) || !is_valid_texture(map->ea_tex))
		return (0);
	return (1);
}

int	duplicate_player_elem(t_map *map)
{
	int	i;
	int	j;
	int	spawn_count;

	spawn_count = 0;
	i = 0;
	while (i < map->len_y)
	{
		j = 0;
		while (j < map->len_x)
		{
			if (map->map_2d[i][j] == 'N' || map->map_2d[i][j] == 'S'
				|| map->map_2d[i][j] == 'E' || map->map_2d[i][j] == 'W')
				spawn_count++;
			j++;
		}
		i++;
	}
	if (spawn_count != 1)
	{
		printf("Error: Invalid map file\n");
		return (1);
	}
	return (0);
}

int	is_allowed_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ');
}
