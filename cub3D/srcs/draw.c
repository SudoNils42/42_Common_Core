/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-mt@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:22:06 by lfaria-m          #+#    #+#             */
/*   Updated: 2025/04/12 22:23:43 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_tex	*get_wall_texture(t_mlx *mlx, char side_hit)
{
	if (side_hit == 'N')
		return (mlx->no_tex);
	else if (side_hit == 'S')
		return (mlx->so_tex);
	else if (side_hit == 'E')
		return (mlx->ea_tex);
	else
		return (mlx->we_tex);
}

static int	get_texture_x(t_mlx *mlx, char side_hit, double ray_dir_x,
		double ray_dir_y)
{
	double	wall_x;
	t_tex	*tex;
	int		tex_x;

	tex = get_wall_texture(mlx, side_hit);
	if (side_hit == 'E' || side_hit == 'W')
		wall_x = mlx->ray_y / 32.0 - floor(mlx->ray_y / 32.0);
	else
		wall_x = mlx->ray_x / 32.0 - floor(mlx->ray_x / 32.0);
	tex_x = (int)(wall_x * tex->tex_width);
	if ((side_hit == 'E' && ray_dir_x < 0) || (side_hit == 'W' && ray_dir_x > 0)
		|| (side_hit == 'N' && ray_dir_y > 0) || (side_hit == 'S'
			&& ray_dir_y < 0))
		tex_x = tex->tex_width - tex_x - 1;
	return (tex_x);
}

int	rgb_string_to_hex(const char *str)
{
	char	*end;
	int		r;
	int		g;
	int		b;

	r = ft_atoi(str);
	end = (char *)str;
	while (*end && *end != ',')
		end++;
	if (*end == ',')
		end++;
	g = atoi(end);
	while (*end && *end != ',')
		end++;
	if (*end == ',')
		end++;
	b = atoi(end);
	return ((r << 16) | (g << 8) | b);
}

void	draw_floor_ceiling(t_mlx *mlx, int i, t_draw *draw,
		t_ray_params *ray_params)
{
	int	y;
	int	color;

	y = 0;
	while (y < draw->draw_start)
	{
		my_mlx_pixel_put(mlx, i, y,
			rgb_string_to_hex(ray_params->map->rgb_ceiling));
		y++;
	}
	while (y < draw->draw_end)
	{
		draw->tex_y = (int)draw->tex_pos & (draw->curr_tex->tex_height - 1);
		draw->tex_pos += draw->step;
		color = *(unsigned int *)(draw->curr_tex->wall_tex_addr + draw->tex_y
				* draw->curr_tex->tex_ll + draw->tex_x
				* (draw->curr_tex->tex_bpp / 8));
		my_mlx_pixel_put(mlx, i, y++, color);
	}
	while (y < RES_HEIGHT)
	{
		my_mlx_pixel_put(mlx, i, y,
			rgb_string_to_hex(ray_params->map->rgb_floor));
		y++;
	}
}

void	draw_column(t_mlx *mlx, int i, double perp_wall_dist,
		t_ray_params *ray_params)
{
	t_draw	draw;

	draw.wall_height = (int)(RES_HEIGHT / perp_wall_dist);
	draw.draw_start = -draw.wall_height / 2 + RES_HEIGHT / 2;
	if (draw.draw_start < 0)
		draw.draw_start = 0;
	draw.draw_end = draw.wall_height / 2 + RES_HEIGHT / 2;
	if (draw.draw_end >= RES_HEIGHT)
		draw.draw_end = RES_HEIGHT - 1;
	draw.curr_tex = get_wall_texture(mlx, ray_params->side_hit);
	draw.tex_x = get_texture_x(mlx, ray_params->side_hit,
			ray_params->ray_state->ray_dir_x, ray_params->ray_state->ray_dir_y);
	draw.step = 1.0 * draw.curr_tex->tex_height / draw.wall_height;
	draw.tex_pos = (draw.draw_start - RES_HEIGHT / 2 + draw.wall_height / 2)
		* draw.step;
	draw_floor_ceiling(mlx, i, &draw, ray_params);
}
