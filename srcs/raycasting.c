/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:43:34 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/30 15:25:24 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	draw_map(t_map *m, t_mlx_infos *mlx_infos, t_mlx *mlx)
{
	int	i;
	int	hit;

	i = -1;
	while (++i < WIDTH)
	{
		hit = 0;
		m->ray.camera.x = ((2 * i) / (double)WIDTH) - 1;
		m->ray.dir.y = m->player.dir.y + m->player.plane.y * m->ray.camera.x;
		m->ray.dir.x = m->player.dir.x + m->player.plane.x * m->ray.camera.x;
		m->map_x = (int)m->player.pos.x;
		m->map_y = (int)m->player.pos.y;
		if (m->ray.delta_dist.x == 0)
			m->ray.delta_dist.x = DBL_MAX;
		else
			m->ray.delta_dist.x = fabs(1 / m->ray.dir.x);
		if (m->ray.delta_dist.y == 0)
			m->ray.delta_dist.y = DBL_MAX;
		else
			m->ray.delta_dist.y = fabs(1 / m->ray.dir.y);
		calculate_the_direction_of_the_ray(m);
		cast_the_ray_until_hits_the_wall(m, hit);
		print_textures(m, i, mlx_infos);
	}
	draw_buff(m->img_tmp, m->buffer, mlx);
}

void	set_ray_distance(t_map *map)
{
	if (map->ray.dir.y == 0)
		map->ray.delta_dist.y = 1e30;
	if (map->ray.dir.x == 0)
		map->ray.delta_dist.x = 1e30;
}

void	calculate_the_direction_of_the_ray(t_map *map)
{
	set_ray_distance(map);
	if (map->ray.dir.x < 0)
	{
		map->step.x = -1;
		map->ray.side_dist.x = (map->player.pos.x - map->map_x)
			* map->ray.delta_dist.x;
	}
	else
	{
		map->step.x = 1;
		map->ray.side_dist.x = (map->map_x + 1.0 - map->player.pos.x)
			* map->ray.delta_dist.x;
	}
	if (map->ray.dir.y < 0)
	{
		map->step.y = -1;
		map->ray.side_dist.y = (map->player.pos.y - map->map_y)
			* map->ray.delta_dist.y;
	}
	else
	{
		map->step.y = 1;
		map->ray.side_dist.y = (map->map_y + 1.0 - map->player.pos.y)
			* map->ray.delta_dist.y;
	}
}

void	cast_the_ray_until_hits_the_wall(t_map *map, int hit)
{
	while (hit == 0)
	{
		if (map->ray.side_dist.x < map->ray.side_dist.y)
		{
			map->ray.side_dist.x += map->ray.delta_dist.x;
			map->map_x += map->step.x;
			map->side = 0;
		}
		else
		{
			map->ray.side_dist.y += map->ray.delta_dist.y;
			map->map_y += map->step.y;
			map->side = 1;
		}
		if (map->matrix[(int)map->map_y][(int)map->map_x] > '0')
			hit = 1;
	}
	if (map->side == 0)
		map->ray.wall_dist = map->ray.side_dist.x - map->ray.delta_dist.x;
	else
		map->ray.wall_dist = map->ray.side_dist.y - map->ray.delta_dist.y;
	if (map->ray.wall_dist < 1e-4)
		map->ray.wall_dist = 0.4;
}

void	draw_rays(t_map *minimap, t_mlx *mlx)
{
	int		i;
	double	y;
	double	x;
	double	tmp_y;
	double	tmp_x;

	tmp_y = minimap->player.dir.y / 5;
	tmp_x = minimap->player.dir.x / 5;
	y = minimap->player.dir.y;
	x = minimap->player.dir.x;
	i = 0;
	while (i < 80)
	{
		my_mlx_pixel_put(minimap->img_map,
			MINIMAP_SIZE / 2 + x,
			MINIMAP_SIZE / 2 + y,
			rgb(0, 0, 255, 255));
		y += tmp_y;
		x += tmp_x;
		i++;
	}
	mlx_put_image_to_window(mlx->mlx,
		mlx->window, minimap->img_map->img, 0, 0);
}
