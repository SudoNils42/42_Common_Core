/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:24:11 by nbonnet           #+#    #+#             */
/*   Updated: 2025/04/18 14:25:51 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	call_hooks(t_mlx *mlx, t_data *data)
{
	mlx_hook(mlx->win, 17, 0, close_window, data);
	mlx_hook(mlx->win, 2, 1L << 0, key_press, data);
	mlx_hook(mlx->win, 3, 1L << 1, key_release, data);
	mlx_hook(mlx->win, 6, 1L << 6, bonus_mouse_move, data);
}

int	main(int ac, char **av)
{
	t_map		map;
	t_mlx		mlx;
	t_player	player;
	t_data		data;

	(void)ac;
	init_data(&data, &mlx, &map, &player);
	data.mlx = &mlx;
	read_map(&map, av);
	if (!is_map_valid(&map))
		cleanup(&data);
	init_mlx(&mlx);
	load_textures(&mlx, &map);
	init_player(&map, &player);
	draw_3d_view(&mlx, &player, &map);
	update_player(&player);
	rotate_player(data.player, 0);
	call_hooks(&mlx, &data);
	mlx_loop_hook(mlx.mlx, update_game, &data);
	mlx_loop(mlx.mlx);
	cleanup(&data);
	return (0);
}
