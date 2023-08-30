/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:45:58 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/30 17:06:18 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	print_textures(t_map *m, int x, t_mlx_infos *mlx_infos)
{
	t_mlx_texture	*tex;
	int				i;

	tex = set_variables(m, mlx_infos, x);
	while (m->tex->d_start < m->tex->d_end)
	{
		m->tex->tex.y = (int)m->tex->t_pos & (64 - 1);
		m->tex->t_pos += m->tex->step;
		m->tex->color = get_pixel_color(tex, m->tex->tex.x / \
		(double)tex->width, m->tex->tex.y / (double)tex->height);
		m->buffer[x][m->tex->d_start] = m->tex->color;
		m->tex->d_start++;
	}
	i = m->tex->d_start;
	while (i < HEIGHT)
		m->buffer[x][i++] = rgb(mlx_infos->f_color[0], \
								mlx_infos->f_color[1], \
								mlx_infos->f_color[2], 255);
}

void	draw_buff(t_img *img_tmp, int32_t buffer[WIDTH][HEIGHT], t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
			my_mlx_pixel_put(img_tmp, i, j, buffer[i][j]);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, img_tmp->img, 0, 0);
}

t_mlx_texture	*get_texture(t_map *map, t_mlx_infos *mlx_infost_mlx_infos)
{
	if (map->side == 0 && map->ray.dir.x > 0)
		return (mlx_infost_mlx_infos->t_ea);
	if (map->side == 0 && map->ray.dir.x < 0)
		return (mlx_infost_mlx_infos->t_we);
	if (map->side == 1 && map->ray.dir.y > 0)
		return (mlx_infost_mlx_infos->t_no);
	if (map->side == 1 && map->ray.dir.y < 0)
		return (mlx_infost_mlx_infos->t_so);
	return (NULL);
}

void	set_tex_struct(t_map *map)
{
	map->tex->line_height = (int)(HEIGHT / map->ray.wall_dist);
	map->tex->d_start = -map->tex->line_height / 2 + HEIGHT / 2;
	if (map->tex->d_start < 0)
		map->tex->d_start = 0;
	map->tex->d_end = map->tex->line_height / 2 + HEIGHT / 2;
	if (map->tex->d_end >= HEIGHT)
		map->tex->d_end = HEIGHT - 1;
	map->tex->step = 1.0 * 64 / map->tex->line_height;
	map->tex->t_pos = (map->tex->d_start - HEIGHT / 2
			+ map->tex->line_height / 2) * map->tex->step;
}

t_mlx_texture	*set_variables(t_map *map, t_mlx_infos *m_d, int x)
{
	int	i;

	set_tex_struct(map);
	if (map->side == 0)
		map->ray.x_hit_point = map->player.pos.y
			+ map->ray.wall_dist * map->ray.dir.y;
	else
		map->ray.x_hit_point = map->player.pos.x
			+ map->ray.wall_dist * map->ray.dir.x;
	map->ray.x_hit_point -= (int)map->ray.x_hit_point;
	map->tex->tex.x = (int)((map->ray.x_hit_point) * (double)64);
	if ((map->side == 0 && map->ray.dir.x > 0)
		|| (map->side == 1 && map->ray.dir.y < 0))
		map->tex->tex.x = 64 - map->tex->tex.x - 1;
	i = 0;
	while (i < map->tex->d_start)
		map->buffer[x][i++] = rgb(m_d->c_color[0],
				m_d->c_color[1], m_d->c_color[2], 255);
	return (get_texture(map, m_d));
}
