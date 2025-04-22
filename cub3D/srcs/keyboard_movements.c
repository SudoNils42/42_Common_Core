/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_movements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:31:18 by nbonnet           #+#    #+#             */
/*   Updated: 2025/04/18 14:34:15 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == 119)
		data->keys[0] = 1;
	if (keycode == 115)
		data->keys[1] = 1;
	if (keycode == 97)
		data->keys[2] = 1;
	if (keycode == 100)
		data->keys[3] = 1;
	if (keycode == 65361)
		data->keys[4] = 1;
	if (keycode == 65363)
		data->keys[5] = 1;
	if (keycode == 65307)
		cleanup(data);
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == 119)
		data->keys[0] = 0;
	if (keycode == 115)
		data->keys[1] = 0;
	if (keycode == 97)
		data->keys[2] = 0;
	if (keycode == 100)
		data->keys[3] = 0;
	if (keycode == 65361)
		data->keys[4] = 0;
	if (keycode == 65363)
		data->keys[5] = 0;
	return (0);
}

void	calculate_deltas(t_data *data, int *delta_x, int *delta_y)
{
	int	speed;

	speed = 4;
	if (data->keys[0])
	{
		*delta_x += (data->player->dir_x * speed);
		*delta_y += (data->player->dir_y * speed);
	}
	if (data->keys[1])
	{
		*delta_x -= (data->player->dir_x * speed);
		*delta_y -= (data->player->dir_y * speed);
	}
	if (data->keys[2])
	{
		*delta_x += (data->player->dir_y * speed);
		*delta_y -= (data->player->dir_x * speed);
	}
	if (data->keys[3])
	{
		*delta_x -= (data->player->dir_y * speed);
		*delta_y += (data->player->dir_x * speed);
	}
}

void	handle_player_input(t_data *data, int delta_x, int delta_y)
{
	int	new_x;
	int	new_y;

	new_x = data->player->pos_x + delta_x;
	new_y = data->player->pos_y + delta_y;
	if (delta_x != 0 || delta_y != 0)
	{
		if (is_valid_move(data->map, new_x, new_y))
		{
			data->player->pos_x = new_x;
			data->player->pos_y = new_y;
		}
	}
	if (data->keys[4])
		rotate_player(data->player, -5);
	if (data->keys[5])
		rotate_player(data->player, 5);
}

int	update_game(t_data *data)
{
	int	delta_x;
	int	delta_y;

	delta_x = 0;
	delta_y = 0;
	calculate_deltas(data, &delta_x, &delta_y);
	handle_player_input(data, delta_x, delta_y);
	update_player(data->player);
	draw_3d_view(data->mlx, data->player, data->map);
	data->needs_redraw = 0;
	return (0);
}
