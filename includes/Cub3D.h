/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:26:30 by akhellad          #+#    #+#             */
/*   Updated: 2023/10/30 17:08:40 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "math.h"
# include "stdbool.h"
# include "stdlib.h"
# include "stdio.h"
# include "fcntl.h"
# include "unistd.h"
# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"

# define NO 				0
# define EA 				1
# define SO 				2
# define WE 				3
# define RED 				0x00cc5803
# define GREEN 				0x00e2711d
# define BLUE 				0x00ff9505
# define YELLOW 			0x00ffb627
# define LINE_COLOR 		0x00ff0000
# define LINE_GREEN_COLOR	0x0000ff00
# define WALL_COLOR 		0x00ffffff
# define FLOOR_COLOR 		0x0000ffff
# define PLAYER_COLOR 		0x00ff0000
# define TILE_SIZE			100
# define SCALE_SIZE 		0.07
# define PI					3.141592653589793238
# define UP					119
# define UP_ARROW			126
# define DOWN				115
# define DOWN_ARROW			125
# define RIGHT				100
# define LEFT				97
# define ESC				65307
# define RIGHT_ARROW		65363
# define LEFT_ARROW			65361
# define PLAYER_SPEED		10
# define TURN_SPEED			2
# define ONE_DEGRESS 		0.0174533
# define WINDOW_WIDTH 		1980
# define WINDOW_HEIGTH 		1080
# define ID					1
# define CONTENT			0
# define TEXTURE			1
# define COLOR				2

typedef struct s_walls_draw
{
	float	dist;
	float	wall_len;
	int		start_y;
	int		text_start_pixel;
	int		offset_y;
	float	real_wall_len;
	int		direction;
}	t_walls_draw;

typedef struct s_raycast
{
	float		y;
	float		x;
	float		rad;
	float		angel;
	int			rays;
	float		dist;
	float		wall_len;
	int			start_y;
	int			start_x;
}	t_raycast;

typedef struct s_textures
{
	int		width;
	int		height;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*pixel_data;
	void	*img;
	int		*addr;
}	t_textures;

typedef struct s_info
{
	char	*id;
	char	*content;
}	t_info;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
}	t_mlx;

typedef struct s_my_mlx
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*pixel_data;
	void	*img;
	int		width;
	int		height;
	int		color;
}	t_my_mlx;

typedef struct s_obj
{
	int	y_pos;
	int	x_pos;
}	t_obj;

typedef struct s_player
{
	float	y;
	float	x;
	float	dir_x;
	float	dir_y;
	float	dif_x;
	float	dif_y;
	float	steps;
	float	x_inc;
	float	y_inc;
	float	angel;
	float	turn_speed;
	float	walk_speed;
	int		turn;
	int		walk;
	int		rotate;
	int		direction;
	int		last_x;
}	t_player;

typedef struct s_cub3d
{
	t_my_mlx	mini_img;
	t_my_mlx	map_img;
	char		**full_file;
	t_info		*info;
	char		**map;
	int			info_size;
	int			lines;
	int			map_height;
	int			map_width;
	int			window_height;
	int			window_width;
	t_mlx		mlx;
	t_mlx		map_mlx;
	t_player	player;
	t_textures	*textures;
	char		p;
	int			ceil;
	int			floor;
}	t_cub3d;

/*initialisation.c*/
int		check_args(t_cub3d *cub, int ac, char *file);
char	**malloc_2nd_char(t_cub3d *cub, int fd);
void	init_cub(t_cub3d *cub, char *file);
void	check_infos(t_cub3d *cub);

/*utils.c*/
int 	is_empty(char *s);
int		is_info(char *line);
int		in_set(char c, char *set);
char	*dup_line(char *src, int len);

char    **ft_2nd_split(char const	*s, char *set, int *len);

/*free_utils.c*/
void	tab_free(char **tab);
void	ft_exit(t_cub3d *cub, int error);
int		exit_btn(t_cub3d *cub);
void	free_utils(t_cub3d cub);

/*infos.c*/
void    parse_info(t_cub3d *cub, t_info *info, char *file);

/*check_map.c*/
void    init_map(t_cub3d *cub);

/*game.c*/
void    draw_map(t_cub3d *cub);
void	move_player(t_cub3d *cub, float x, float y);
int		check_wall(t_cub3d *cub, float new_x, float new_y);

/*player.c*/
void    init_player(t_cub3d *cub);

/*draw_utils.c*/
char	*get_info_value(t_cub3d *cub, const char *id);
int		my_abs(int x);

/*images.c*/
void	new_main_img(t_cub3d *cub, t_my_mlx *data, int width, int height);
void	new_black_obj(t_my_mlx *data, int hiegth, int width);

/*hooks.c*/
int		key_pressed(int keycode, t_cub3d *cub);
int		key_released(int keycode, t_cub3d *cub);

/*draw.c*/
void	draw_walls(t_cub3d *cub, t_raycast ray);

/*raycasting.c*/
void	raycast(t_cub3d *cub);

/*render.c*/
int		render_2dmap(t_cub3d *cub);
void	my_mlx_put_pixel(t_my_mlx *data, int y, int x, int color);

#endif