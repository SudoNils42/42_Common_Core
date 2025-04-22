/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-mt@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:29:21 by nbonnet           #+#    #+#             */
/*   Updated: 2025/04/12 19:41:40 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_player *player, double angle)
{
	double	old_dir_x;
	double	old_dir_y;
	double	rad;

	old_dir_x = player->dir_x;
	old_dir_y = player->dir_y;
	rad = angle * M_PI / 180.0;
	player->dir_x = old_dir_x * cos(rad) - old_dir_y * sin(rad);
	player->dir_y = old_dir_x * sin(rad) + old_dir_y * cos(rad);
}

void	update_player(t_player *player)
{
	int	i;
	int	j;

	i = player->old_pos_y - 4;
	while (i < player->old_pos_y + 4)
	{
		j = player->old_pos_x - 4;
		while (j < player->old_pos_x + 4)
			j++;
		i++;
	}
	i = player->pos_y - 4;
	while (i < player->pos_y + 4)
	{
		j = player->pos_x - 4;
		while (j < player->pos_x + 4)
			j++;
		i++;
	}
	player->old_pos_x = player->pos_x;
	player->old_pos_y = player->pos_y;
}

int	handle_direction_init(t_player *player, char dir)
{
	if (dir == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	else if (dir == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (dir == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
	else if (dir == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
	return (0);
}
