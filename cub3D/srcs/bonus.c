/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:21:40 by nbonnet           #+#    #+#             */
/*   Updated: 2025/04/18 14:17:03 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	bonus_mouse_move(int x, int y, t_data *data)
{
	int		delta_x;
	double	angle;

	(void)y;
	delta_x = x - WINDOW_WIDTH / 2;
	if (delta_x != 0)
	{
		angle = delta_x * MOUSE_SENSITIVITY;
		rotate_player(data->player, angle);
		mlx_mouse_move(data->mlx->mlx, data->mlx->win,
			WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		data->needs_redraw = 1;
	}
	return (0);
}
