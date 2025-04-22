/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:24:45 by nbonnet           #+#    #+#             */
/*   Updated: 2025/04/18 15:12:27 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define RES_WIDTH 960
# define RES_HEIGHT 540
# define WINDOW_WIDTH 1920  // 3840
# define WINDOW_HEIGHT 1080 // 2160
# define MOUSE_SENSITIVITY 0.015

typedef struct s_map
{
	char		**map_2d;
	int			coor_x;
	int			coor_y;
	int			len_x;
	int			len_y;
	char		*no_tex;
	char		*so_tex;
	char		*we_tex;
	char		*ea_tex;
	char		*rgb_floor;
	char		*rgb_ceiling;

}				t_map;

typedef struct s_tex
{
	void		*wall_tex;
	char		*wall_tex_addr;
	int			tex_width;
	int			tex_height;
	int			tex_bpp;
	int			tex_ll;
	int			tex_endian;
}				t_tex;

typedef struct s_draw
{
	int			wall_height;
	int			tex_x;
	int			tex_y;
	double		tex_pos;
	double		step;
	t_tex		*curr_tex;
	char		*tex_pixel;
	int			draw_start;
	int			draw_end;
}				t_draw;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_addr;
	int			line_length;
	int			bits_per_pixel;
	int			endian;
	void		*window_img;
	char		*window_addr;
	int			window_line_length;
	int			window_bits_per_pixel;
	int			window_endian;
	t_tex		*no_tex;
	t_tex		*so_tex;
	t_tex		*we_tex;
	t_tex		*ea_tex;
	double		ray_x;
	double		ray_y;

}				t_mlx;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		old_pos_x;
	double		old_pos_y;
	double		dir_x;
	double		dir_y;
}				t_player;

typedef struct s_ray_state
{
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	char		side_hit;
	double		pos_x;
	double		pos_y;
	double		ray_dir_x;
	double		ray_dir_y;
}				t_ray_state;

typedef struct s_ray_params
{
	t_mlx		*mlx;
	t_map		*map;
	t_player	*player;
	t_ray_state	*ray_state;
	double		ray_angle;
	char		side_hit;
}				t_ray_params;

typedef struct s_data
{
	t_map		*map;
	t_mlx		*mlx;
	t_player	*player;
	int			mouse_x;
	int			needs_redraw;
	int			keys[6];
	int			flashlight_on;
}				t_data;

// display_map_3d
void			draw_3d_view(t_mlx *mlx, t_player *player, t_map *map);
void			cast_single_ray(t_mlx *mlx, t_map *map, t_player *player,
					int i);
double			raycast_distance(t_ray_params *params);
void			init_ray_dir(t_ray_state *ray, double ray_angle);
void			init_step_x(t_ray_state *ray, double pos_x_tile);
void			init_step_y(t_ray_state *ray, double pos_y_tile);

// draw
void			draw_column(t_mlx *mlx, int i, double perp_wall_dist,
					t_ray_params *ray_params);

// check_map
void			read_map(t_map *map, char **av);
int				is_walled_in(t_map *map);
int				duplicate_player_elem(t_map *map);
int				is_map_valid(t_map *map);
int				valid_map_structure(t_map *map);
int				is_allowed_char(char c);
int				duplicate_player_elem(t_map *map);
int				valid_map_structure(t_map *map);
int				is_valid_texture(char *path);
int				is_rgb_valid(char *rgb);
void			strip_newline(char *line);
int				is_map_line(char *line);
char			*ft_strdup_trimmed(char *str);
int				is_empty_line(char *line);
void			init_map_read(t_map *map, int *map_started,
					int *map_info_count);
int				process_map_line(char *line, t_map *map, int *map_info_count,
					int *map_started);
int				handle_map_content(char *line, t_map *map);
int				handle_pre_map_content(char *line, t_map *map,
					int *map_info_count);
void			pad_map(t_map *map);
char			*create_padded_line(char *original, int target_len);
void			read_textures(char *line, t_map *map, int *map_info_count);

// keyboard_movements
int				close_window(t_data *data);
int				update_game(t_data *data);
int				key_release(int keycode, t_data *data);
int				key_press(int keycode, t_data *data);

// init
void			init_data(t_data *data, t_mlx *mlx, t_map *map,
					t_player *player);
void			init_mlx(t_mlx *mlx);
void			init_player(t_map *map, t_player *player);
int				load_textures(t_mlx *mlx, t_map *map);

// player
void			rotate_player(t_player *player, double angle);
void			update_player(t_player *player);
void			init_player(t_map *map, t_player *player);
int				handle_direction_init(t_player *player, char dir);

// bonus
int				bonus_mouse_move(int x, int y, t_data *data);

// free
void			cleanup(t_data *data);

void			free_map_2d(t_map *map);
void			free_map_textures(t_map *map);

// utils
void			my_mlx_pixel_put(t_mlx *mlx, int i, int y, int color);
int				close_window(t_data *data);
int				is_valid_move(t_map *map, int new_x, int new_y);
void			free_split(char **split);
int				check_map_chars(t_map *map);

// dda
double			dda_loop(t_ray_state *ray, t_map *map);
void			update_ray_position(t_ray_state *ray, char dir);
double			get_wall_distance(char side_hit, double side_dist,
					double delta_dist);

#endif
