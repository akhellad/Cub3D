/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:10:04 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/30 00:15:16 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <float.h>
# include <stdbool.h>
# include <stdint.h>
# include <math.h>

#include "../libft/includes/libft.h"
# include "../mlx/mlx.h"

# define MALLOC_FAIL "Error! Malloc failed.\n"
# define TMA "Error! Wrong number of arguments.\n"
# define INVALID_MAP "Error! The map is invalid.\n"
# define RGB_IS "Error! The RGB color is out of range, "
# define CANNOT_OPEN "Error! This map cannot be opened.\n"
# define MISSING_PLAYER "Error! No players found on the map.\n"
# define OUT_OF_RANGE "all numbers must be between 0 and 255.\n"
# define RGB_DUPLICATE "Error! To many rgb values on the map.\n"
# define TOO_MANY_PLAYERS "Error! Too many players on the map.\n"
# define NOA "Error! No arguments, please add a map.\n"
# define INVALID_CHAR "Error! Map has at least one invalid char: "
# define PLAYER_DUPLICATE "Error! Player duplicates on the map.\n"
# define WRONG_ATTRIBUTES "Error! Wrong attributes in the map file.\n"
# define COMMA "Error! The amount of comma in the RGB list is wrong.\n"
# define TEX_FILE_WRONG "Error! The texture file cannot be opened.\n"
# define DFS_ERROR "Error! The DFS algorithm found a problem on the map.\n"
# define MISSING_ATTRIBUTES "Error! Attributes are missing from the map.\n"
# define WRONG_EXTENSION "Error! Map file is wrong. It needs .cub format.\n"
# define DUPLICATE "Error! Duplicates found on the map for the attributes.\n"

# define R 20
# define WIDTH 1080
# define HEIGHT 720
# define MINIMAP_SIZE 260

typedef struct s_img
{
	void	*img;
	char	*adrr;
	int		bpp;
	int		lengh;
	int		endian;
}		t_img;

typedef struct mlx_texture
{
    t_img *img_ptr;
    int width;
    int height;
}	mlx_texture_t;


typedef struct s_vector
{
	double	y;
	double	x;
}	t_vector;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	double		angle;
	double		speed;
	bool		speed_is_life;
}	t_player;

typedef struct s_ray
{
	t_vector	dir;
	t_vector	camera;
	t_vector	side_dist;
	double		wall_dist;
	t_vector	delta_dist;
	double		x_hit_point;
}	t_ray;

typedef struct s_mlx_infos
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				error;
	mlx_texture_t	*t_no;
	mlx_texture_t	*t_so;
	mlx_texture_t	*t_we;
	mlx_texture_t	*t_ea;
	mlx_texture_t	*door;
	t_player		*player;
	char			**raw_map;
	int				f_color[3];
	int				c_color[3];
	int				map_length;
	char			**map_copy;
	int				reading_pos;
}	t_mlx_infos;

typedef struct s_tex
{
	t_vector	tex;
	double		step;
	double		t_pos;
	uint32_t	color;
	int			d_end;
	int			d_start;
	int			line_height;
}	t_tex;

typedef struct s_fc_tex
{
	int				x;
	int				y;
	int				p;
	int				tex_x;
	int				tex_y;
	float			pos_z;
	int				cell_x;
	int				cell_y;
	float			floor_x;
	float			floor_y;
	float			f_step_x;
	float			f_step_y;
	float			ray_dir_x0;
	float			ray_dir_y0;
	float			ray_dir_x1;
	float			ray_dir_y1;
	float			row_distance;
}	t_fc_tex;

typedef struct s_sprite
{
	double			x;
	double			y;
	int				d;
	int				d_y;
	t_vector		pos;
	int				fps;
	t_vector		size;
	uint32_t		color;
	int				index;
	int				stripe;
	double			inv_det;
	t_vector		draw_end;
	int				screen_x;
	double			distance;
	int				texture_x;
	int				texture_y;
	t_vector		draw_start;
	double			transform_x;
	double			transform_y;
	int				v_move_screen;
}	t_sprite;

typedef struct s_map
{
	int			x;
	int			y;
	t_fc_tex	fc;
	int			hit;
	t_ray		ray;
	t_tex		*tex;
	int			side;
	t_vector	step;
	int			map_x;
	int			map_y;
	int			op_min;
	int			op_mid;
	int			op_max;
	t_player	player;
	t_sprite	sprite;
	t_img		*img_map;
	t_img		*img_tmp;
	bool		has_key;
	char		**matrix;
	bool		draw_minimap;
	double		z_buffer[WIDTH];
	int			buffer[WIDTH][HEIGHT];
}	t_map;

typedef struct				s_mlx
{
	void		*mlx;
	void		*window;
	t_img		*img;
}				t_mlx;

typedef struct s_infos
{
	t_mlx		*mlx;
	int			mouse_x;
	t_map		*minimap;
	t_mlx_infos	*mlx_infos;
}	t_infos;

/*utils.c*/
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
int		commacounter(char *line);
int		ft_strcmp(char *s1, char *s2);
char	*get_line(int fd, char *line);

/*arg_check.c*/
int		arg_check(int ac, char *av, t_mlx_infos *infos);
t_mlx	*init_mlx(char *title);

/*initialisation.c*/
int		initialisation(int ac, char **av, t_infos *infos);

/*mlx_image.c*/
t_mlx	*init_mlx(char *title);
void	free_mlx_infos_on_error(t_mlx_infos *mlx_infos, t_infos *infos);
t_mlx	*mlx_del(t_mlx *mlx);
t_img	*new_image(void *mlx);
t_img	*del_image(t_mlx *mlx, t_img *img);

/*valid_options.c*/
int		valid_options(char *line, t_mlx_infos *infos);

/*valid_options_utils.c*/
int		validate_we_ea(char *line, t_mlx_infos *infos);
int		validate_no_so(char *line, t_mlx_infos *infos);
void	save_color_to_infos(char **rgb, t_mlx_infos *infos, char option);
void	free_char_array(char **array);

/*handle_colors.c*/
int		validate_color(char *line, t_mlx_infos *infos);

/*handle_map.c*/
int		line_cotains_only_spaces(char *line);
int		map_has_multiple_players_or_none(char c, char option);
char	**copy_2d_char_array(char **array);
void	get_player_pos(char **map, int *py, int *px);
void	dfs(char **map, int y, int x, t_mlx_infos *infos);
char	*copy_map_line(char *content);
void	get_map_length(int fd, char *map_file, t_mlx_infos *infos);
int		handle_map(t_mlx_infos *infos, int fd);

/*init_map_utils.c*/
double	get_angle(char c);
void	set_plan(t_vector *plane, char c);
int		get_longest_line(char **map);
char	*dup3(int size, char ch);

/*init_map.c*/
t_map	*init_map(t_mlx_infos *mlx_infos, void *mlx);

/*movements.c*/
int		move_keys(int keycode, void *param);

/*free.c*/
void	free_infos(t_infos *infos);

/*print.c*/
void	print_textures(t_map *m, int x, t_mlx_infos *mlx_infos);
void	draw_buff(t_img *img_tmp, int32_t buffer[WIDTH][HEIGHT], t_mlx *mlx);

/*raycasting.c*/
void	draw(t_map *map, t_mlx_infos *mlx_infos, t_mlx *mlx);

#endif