/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:06:24 by hsilverb          #+#    #+#             */
/*   Updated: 2023/12/16 18:29:06 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# include "libft.h"
# include "mlx.h"
# include "keycode.h"
# include "define.h"

enum
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
};

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_dpoint
{
	double	x;
	double	y;
}	t_dpoint;

typedef struct s_ray
{
	t_dpoint	pos;
	t_dpoint	dir;
	t_dpoint	plane;
	t_dpoint	raydir;
	t_dpoint	side_dist;
	t_dpoint	delta_dist;
	t_point		map;
	t_point		step_pos;
	t_point		tex;
	double		rot_speed;
	double		tex_pos;
	double		step;
	double		perp_wall_dist;
	int			draw_start;
	int			draw_end;
	int			side;
	int			boolean;
	double		angle;
}	t_ray;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_mlx;

typedef struct s_game
{
	char	**map;
	t_list	*map_list;
	t_mlx	*mlx;
	t_ray	*ray;
	t_img	texture[4];
	char	**file;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
	int		floor_color;
	int		ceiling_color;
	int		expanded;
	int		rot_left;
	int		rot_right;
	int		move_up;
	int		move_down;
	int		move_right;
	int		move_left;
	int		last_x;
	int		end;
	int		map_height;
	int		map_width;
	char	p;
	int		image_width;
	int		image_height;
}	t_game;

void			ft_parsing(t_game *game, char *cub_file);
int				ft_get_textures(char **file, t_game *game);
int				ft_get_colors(t_game *game);
void			ft_check_textures(t_game *game);
bool			ft_valid_tex_char(char c);
bool			ft_valid_map_char(char c);
bool			ft_valid_start_char(char c);
bool			ft_double(char *str, t_game *game);
void			check_map(t_game *game);
int				is_empty(char *s);
int				ft_strchr_index(const char *s, char *c);
char			*dup_line(char *src, int len);
int				in_set(char c, char *set);
char			**dup_map(t_game *game);

int				ft_raycasting(t_game *game);
void			ft_init_ray(t_game *game);
int				ft_init_textures(t_game *game);
void			ft_calculate_positions(t_game *game);
void			ft_draw_line(t_game *game, t_img *img, int x);
int				ft_loop(t_game *game);
void			ft_cast_ray(t_game *game);
void			ft_move(t_game *game);
void			ft_rot_left(t_game *game);
void			ft_rot_right(t_game *game);
int				ft_create_img(t_game *game, char *path, int side);
int				ft_init_window(t_game *game);
void			ft_mlx_pixel_put(t_img *data, int x, int y, int color);
void			ft_print_line(t_game *game, t_point p0, t_point p2, int color);
int				ft_hook_keypress(int key, t_game *game);
int				ft_hook_keyrelease(int key, t_game *game);

int				ft_error(int error_code);
int				ft_exit(t_game *game);
void			ft_init_struct(t_game *game);
void			ft_reset_ray(t_ray *ray);
void			ft_error_msg(char *str, t_game *game);
void			ft_perror_exit(void);
void			ft_free_mlx(t_game *game);
void			ft_free_str(char **str);
void			ft_free_struct(t_game *game);
void			ft_free_all(t_game *game);
void			tab_free(char **tab);

#endif
