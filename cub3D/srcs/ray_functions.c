/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-mt@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:03:39 by lfaria-m          #+#    #+#             */
/*   Updated: 2025/04/12 19:42:46 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_single_ray(t_mlx *mlx, t_map *map, t_player *player, int i)
{
	t_ray_params	params;
	double			fov;
	double			direction;
	t_ray_state		ray_state;
	double			distance;

	fov = (M_PI / 2);
	direction = atan2(player->dir_y, player->dir_x);
	params.ray_angle = direction - (fov / 2) + (i * fov / RES_WIDTH);
	ray_state.ray_dir_x = cos(params.ray_angle);
	ray_state.ray_dir_y = sin(params.ray_angle);
	params.mlx = mlx;
	params.ray_state = &ray_state;
	params.map = map;
	params.player = player;
	mlx->ray_x = player->pos_x;
	mlx->ray_y = player->pos_y;
	params.side_hit = 0;
	distance = raycast_distance(&params);
	draw_column(mlx, i, distance, &params);
}

double	raycast_distance(t_ray_params *params)
{
	t_ray_state	ray;
	double		perp_wall_dist;

	ray.pos_x = params->player->pos_x / 32.0;
	ray.pos_y = params->player->pos_y / 32.0;
	init_ray_dir(&ray, params->ray_angle);
	init_step_x(&ray, ray.pos_x);
	init_step_y(&ray, ray.pos_y);
	perp_wall_dist = dda_loop(&ray, params->map);
	params->side_hit = ray.side_hit;
	params->mlx->ray_x = ray.pos_x * 32.0 + perp_wall_dist * ray.ray_dir_x
		* 32.0;
	params->mlx->ray_y = ray.pos_y * 32.0 + perp_wall_dist * ray.ray_dir_y
		* 32.0;
	return (perp_wall_dist);
}

void	init_ray_dir(t_ray_state *ray, double ray_angle)
{
	ray->ray_dir_x = cos(ray_angle);
	ray->ray_dir_y = sin(ray_angle);
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

void	init_step_x(t_ray_state *ray, double pos_x_tile)
{
	ray->map_x = (int)pos_x_tile;
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (pos_x_tile - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - pos_x_tile) * ray->delta_dist_x;
	}
}

void	init_step_y(t_ray_state *ray, double pos_y_tile)
{
	ray->map_y = (int)pos_y_tile;
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (pos_y_tile - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - pos_y_tile) * ray->delta_dist_y;
	}
}
