/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map_3d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-mt@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:32:40 by nbonnet           #+#    #+#             */
/*   Updated: 2025/04/12 13:51:07 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	upscale_image(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			if (x / (WINDOW_WIDTH / RES_WIDTH) < RES_WIDTH && y / (WINDOW_HEIGHT
					/ RES_HEIGHT) < RES_HEIGHT)
			{
				*(unsigned int *)(mlx->window_addr + y * mlx->window_line_length
						+ x * (mlx->window_bits_per_pixel
							/ 8)) = *(unsigned int *)(mlx->img_addr + (y
							/ (WINDOW_HEIGHT / RES_HEIGHT)) * mlx->line_length
						+ (x / (WINDOW_WIDTH / RES_WIDTH))
						* (mlx->bits_per_pixel / 8));
			}
			x++;
		}
		y++;
	}
}

void	draw_3d_view(t_mlx *mlx, t_player *player, t_map *map)
{
	int	i;

	i = -1;
	while (++i < RES_WIDTH)
		cast_single_ray(mlx, map, player, i);
	upscale_image(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->window_img, 0, 0);
}
