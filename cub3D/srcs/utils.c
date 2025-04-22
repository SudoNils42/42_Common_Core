/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-mt@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:23:35 by nbonnet           #+#    #+#             */
/*   Updated: 2025/04/12 19:40:43 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_mlx *mlx, int i, int y, int color)
{
	char	*dst;

	if (i >= 0 && i < RES_WIDTH && y >= 0 && y < RES_HEIGHT)
	{
		dst = mlx->img_addr + (y * mlx->line_length + i * (mlx->bits_per_pixel
					/ 8));
		*(unsigned int *)dst = color;
	}
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	is_valid_move(t_map *map, int new_x, int new_y)
{
	int	tile_x1;
	int	tile_x2;
	int	tile_y1;
	int	tile_y2;

	tile_x1 = (new_x - 4) / 32;
	tile_x2 = (new_x + 4) / 32;
	tile_y1 = (new_y - 4) / 32;
	tile_y2 = (new_y + 4) / 32;
	if (map->map_2d[tile_y1][tile_x1] == '1'
		|| map->map_2d[tile_y1][tile_x2] == '1'
		|| map->map_2d[tile_y2][tile_x1] == '1'
		|| map->map_2d[tile_y2][tile_x2] == '1')
		return (0);
	return (1);
}

int	close_window(t_data *data)
{
	cleanup(data);
	return (1);
}

int	check_map_chars(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->len_y)
	{
		j = 0;
		while (j < map->len_x)
		{
			if (!is_allowed_char(map->map_2d[i][j]))
			{
				printf("invalid map elem at [%d][%d]: '%c'\n", i, j,
					map->map_2d[i][j]);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
