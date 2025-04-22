/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:48:04 by nbonnet           #+#    #+#             */
/*   Updated: 2025/04/18 14:16:22 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map_textures(t_map *map)
{
	if (map->no_tex)
		free(map->no_tex);
	if (map->so_tex)
		free(map->so_tex);
	if (map->we_tex)
		free(map->we_tex);
	if (map->ea_tex)
		free(map->ea_tex);
	if (map->rgb_floor)
		free(map->rgb_floor);
	if (map->rgb_ceiling)
		free(map->rgb_ceiling);
}

void	free_map_2d(t_map *map)
{
	int	i;

	if (map->map_2d)
	{
		i = 0;
		while (i < map->len_y && map->map_2d[i])
		{
			free(map->map_2d[i]);
			i++;
		}
		free(map->map_2d);
	}
}

void	free_mlx_textures(t_mlx *mlx)
{
	if (mlx->no_tex && mlx->no_tex->wall_tex)
	{
		mlx_destroy_image(mlx->mlx, mlx->no_tex->wall_tex);
		free(mlx->no_tex);
	}
	if (mlx->so_tex && mlx->so_tex->wall_tex)
	{
		mlx_destroy_image(mlx->mlx, mlx->so_tex->wall_tex);
		free(mlx->so_tex);
	}
	if (mlx->we_tex && mlx->we_tex->wall_tex)
	{
		mlx_destroy_image(mlx->mlx, mlx->we_tex->wall_tex);
		free(mlx->we_tex);
	}
	if (mlx->ea_tex && mlx->ea_tex->wall_tex)
	{
		mlx_destroy_image(mlx->mlx, mlx->ea_tex->wall_tex);
		free(mlx->ea_tex);
	}
}

void	free_mlx_base(t_mlx *mlx)
{
	if (mlx->img && mlx->mlx)
		mlx_destroy_image(mlx->mlx, mlx->img);
	if (mlx->window_img && mlx->mlx)
		mlx_destroy_image(mlx->mlx, mlx->window_img);
	if (mlx->win && mlx->mlx)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
}

void	cleanup(t_data *data)
{
	if (data->map)
	{
		free_map_2d(data->map);
		free_map_textures(data->map);
	}
	if (data->mlx)
	{
		free_mlx_textures(data->mlx);
		free_mlx_base(data->mlx);
	}
	exit(0);
}
