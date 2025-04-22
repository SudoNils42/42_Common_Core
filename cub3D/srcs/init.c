/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:40:37 by nbonnet           #+#    #+#             */
/*   Updated: 2025/04/18 15:27:30 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data, t_mlx *mlx, t_map *map, t_player *player)
{
	int	i;

	i = 0;
	data->player = player;
	data->map = map;
	data->needs_redraw = 1;
	data->mouse_x = 480;
	data->flashlight_on = -1;
	while (i < 6)
	{
		data->keys[i] = 0;
		i++;
	}
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->window_img = NULL;
	mlx->no_tex = NULL;
	mlx->so_tex = NULL;
	mlx->we_tex = NULL;
	mlx->ea_tex = NULL;
	mlx->ray_x = 0;
	mlx->ray_y = 0;
}

int	init_texture(t_tex **tex, void *mlx, char *path, char *dir)
{
	*tex = malloc(sizeof(t_tex));
	if (!*tex)
	{
		printf("Error: Texture malloc failed\n");
		return (0);
	}
	(*tex)->wall_tex = mlx_xpm_file_to_image(mlx, path, &(*tex)->tex_width,
			&(*tex)->tex_height);
	if (!(*tex)->wall_tex)
	{
		perror(dir);
		free(*tex);
		return (0);
	}
	(*tex)->wall_tex_addr = mlx_get_data_addr((*tex)->wall_tex,
			&(*tex)->tex_bpp, &(*tex)->tex_ll, &(*tex)->tex_endian);
	return (1);
}

int	load_textures(t_mlx *mlx, t_map *map)
{
	if (!init_texture(&mlx->no_tex, mlx->mlx, map->no_tex, "NO texture"))
		return (0);
	if (!init_texture(&mlx->so_tex, mlx->mlx, map->so_tex, "SO texture"))
		return (0);
	if (!init_texture(&mlx->we_tex, mlx->mlx, map->we_tex, "WE texture"))
		return (0);
	if (!init_texture(&mlx->ea_tex, mlx->mlx, map->ea_tex, "EA texture"))
		return (0);
	return (1);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D");
	mlx->img = mlx_new_image(mlx->mlx, RES_WIDTH, RES_HEIGHT);
	mlx->img_addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	mlx->window_img = mlx_new_image(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx->window_addr = mlx_get_data_addr(mlx->window_img,
			&mlx->window_bits_per_pixel, &mlx->window_line_length,
			&mlx->window_endian);
	mlx_mouse_hide(mlx->mlx, mlx->win);
}

void	init_player(t_map *map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->len_y)
	{
		j = 0;
		while (map->map_2d[i][j] && j < map->len_x)
		{
			if (map->map_2d[i][j] == 'N' || map->map_2d[i][j] == 'S'
				|| map->map_2d[i][j] == 'E' || map->map_2d[i][j] == 'W')
			{
				player->pos_x = j * 32 + 16;
				player->pos_y = i * 32 + 16;
				player->old_pos_x = player->pos_x;
				player->old_pos_y = player->pos_y;
				handle_direction_init(player, map->map_2d[i][j]);
				map->map_2d[i][j] = 'P';
				break ;
			}
			j++;
		}
		i++;
	}
}
