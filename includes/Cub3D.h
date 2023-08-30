/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:08:40 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/30 15:23:30 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
/*ne passe pas la norme*/
# include <float.h>
# include <stdbool.h>
# include <stdint.h>
# include "../libft/includes/libft.h"
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
# define MINIMAP_SIZE 150

typedef struct s_img
{
	void	*img;
	char	*adrr;
	int		bpp;
	int		lengh;
	int		endian;
}		t_img;

typedef struct s_mlx_texture
{
	t_img	*img_ptr;
	int		width;
	int		height;
}	t_mlx_texture;

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
	t_mlx_texture	*t_no;
	t_mlx_texture	*t_so;
	t_mlx_texture	*t_we;
	t_mlx_texture	*t_ea;
	t_mlx_texture	*door;
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

typedef struct s_map
{
	int			x;
	int			y;
	int			hit;
	t_ray		ray;
	t_tex		*tex;
	int			side;
	t_vector	step;
	int			map_x;
	int			map_y;
	t_player	player;
	t_img		*img_map;
	t_img		*img_tmp;
	char		**matrix;
	int			buffer[WIDTH][HEIGHT];
}	t_map;

typedef struct s_mlx
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
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
int				commacounter(char *line);
int				ft_strcmp(char *s1, char *s2);
char			*get_line(int fd, char *line);

/*arg_check.c*/
int				arg_check(int ac, char *av, t_mlx_infos *infos);
int				valid_args(char	*map_file, t_mlx_infos *infos);

/*initialisation.c*/
int				initialisation(int ac, char **av, t_infos *infos);
t_mlx_infos		*init_infos(void);
void			init_textures(t_infos *infos);

/*mlx_image.c*/
t_mlx			*init_mlx(char *title);
void			free_mlx_infos_on_error(t_mlx_infos *mlx_infos, t_infos *infos);
t_mlx			*mlx_del(t_mlx *mlx);
t_img			*new_image(void *mlx);
t_img			*del_image(t_mlx *mlx, t_img *img);

/*mlx_image_utils.c*/
int				get_pixel_color(t_mlx_texture *tex, double tex_x, double tex_y);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);

/*valid_options.c*/
int				valid_options(char *line, t_mlx_infos *infos);
int				check_options(char *line);
int				check_double(char *line, t_mlx_infos *infos);
int				validate_texture(char *line, t_mlx_infos *infos);
int				can_be_opened(char *file);

/*valid_options_utils.c*/
int				validate_we_ea(char *line, t_mlx_infos *infos);
int				validate_no_so(char *line, t_mlx_infos *infos);
void			save_color_to_infos(char **rgb, t_mlx_infos *infos, \
									char option);
void			free_char_array(char **array);
void			save_texture_to_infos(char *file, t_mlx_infos *infos, \
									char option);

/*handle_colors.c*/
int				validate_color(char *line, t_mlx_infos *infos);
char			**split_rgb(char *line, char *trim_with);
int				has_duplicate_rgb(char *line);
int				valid_rgb(char **rgb);
int				rgb_contains_letters(char *line);

/*handle_map_utils.c*/
char			**copy_2d_char_array(char **array);
void			get_map_length(int fd, char *map_file, t_mlx_infos *infos);
int				line_cotains_only_spaces(char *line);
void			get_player_pos(char **map, int *py, int *px);
void			dfs(char **map, int y, int x, t_mlx_infos *infos);

/*handle_map.c*/
int				line_has_invalid_chars(char *line);
int				handle_map(t_mlx_infos *infos, int fd);
int				map_has_multiple_players_or_none(char c, char option);
int				check_maps(t_mlx_infos *infos, int i);
char			*copy_map_line(char *content);

/*init_map_utils.c*/
double			get_angle(char c);
void			set_plan(t_vector *plane, char c);
int				get_longest_line(char **map);
char			*dup3(int size, char ch);
char			*ft_strdup2(char *str, int start, int end);

/*init_map.c*/
t_map			*init_map(t_mlx_infos *mlx_infos, void *mlx);
char			*init_line(char *old_line, int l);
char			**init_matrix(char **m, int height);
void			set_player_position(t_map *minimap);
t_img			*my_mlx_new_image(void *mlx, uint32_t width, uint32_t height);

/*movements.c*/
void			move_right(double y, double x, t_map *map);
void			move_left(double y, double x, t_map *map);
void			move_down(double y, double x, t_map *map);
void			move_up(double y, double x, t_map *map);

/*move_hook.c*/
int				move_keys(int keycode, void *param);
void			turn_left(t_player *playr);
void			turn_right(t_player *player);
void			is_escape(t_infos *infos, int keycode);
bool			is_wall(int y, int x, char **matrix);

/*free.c*/
void			free_infos(t_infos *infos);
void			mlx_delete_texture(t_mlx_infos *mlx_infos, t_infos *infos);
void			free_mlx_infos(t_infos *infos, t_mlx_infos *mlx_infos);
void			free_map(t_infos *infos, t_map *map);

/*print_texture.c*/
void			print_textures(t_map *m, int x, t_mlx_infos *mlx_infos);
void			draw_buff(t_img *img_tmp, int32_t buffer[WIDTH][HEIGHT], \
							t_mlx *mlx);
t_mlx_texture	*get_texture(t_map *map, t_mlx_infos *mlx_infost_mlx_infos);
void			set_tex_struct(t_map *map);
t_mlx_texture	*set_variables(t_map *map, t_mlx_infos *m_d, int x);

/*raycasting.c*/
void			draw_rays(t_map *minimap, t_mlx *mlx);
void			draw_map(t_map *m, t_mlx_infos *mlx_infos, t_mlx *mlx);
void			cast_the_ray_until_hits_the_wall(t_map *map, int hit);
void			calculate_the_direction_of_the_ray(t_map *map);
void			set_ray_distance(t_map *map);

/*main.c*/
void			draw(t_map *map, t_mlx_infos *mlx_infos, t_mlx *mlx);
int				mouse_move(int x, int y, t_infos *infos);

/*handle_colors_utils.c*/
uint32_t		rgb(int r, int g, int b, int a);
void			set_map_error(t_mlx_infos *infos);

/*draw_minimap.c*/
void			draw_minimap(t_map *m, t_vector *p, int i, t_mlx *mlx);

#endif