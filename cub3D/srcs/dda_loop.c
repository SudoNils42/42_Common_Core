/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-mt@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:02:06 by lfaria-m          #+#    #+#             */
/*   Updated: 2025/04/12 22:31:10 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

static char	get_direction(double ray_dir, char axis)
{
	if (axis == 'x')
	{
		if (ray_dir > 0)
			return ('E');
		return ('W');
	}
	if (ray_dir > 0)
		return ('S');
	return ('N');
}

double	get_wall_distance(char side_hit, double side_dist, double delta_dist)
{
	if (side_hit == 'E' || side_hit == 'W')
		return (side_dist - delta_dist);
	return (side_dist - delta_dist);
}

void	update_ray_position(t_ray_state *ray, char dir)
{
	if (dir == 'E' || dir == 'W')
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
	}
	ray->side_hit = dir;
}

double	wall_hit(t_ray_state *ray)
{
	if (ray->side_hit == 'E' || ray->side_hit == 'W')
		return ((ray->map_x - ray->pos_x + (1 - ray->step_x) / 2)
			/ ray->ray_dir_x);
	else
		return ((ray->map_y - ray->pos_y + (1 - ray->step_y) / 2)
			/ ray->ray_dir_y);
}

double	dda_loop(t_ray_state *ray, t_map *map)
{
	while (1)
	{
		if (ray->side_dist_x <= ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side_hit = get_direction(ray->ray_dir_x, 'x');
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side_hit = get_direction(ray->ray_dir_y, 'y');
		}
		if (ray->map_x < 0 || ray->map_x >= map->len_x || ray->map_y < 0
			|| ray->map_y >= map->len_y)
			return (1000);
		if (map->map_2d[ray->map_y][ray->map_x] == '1')
			return (wall_hit(ray));
	}
}
