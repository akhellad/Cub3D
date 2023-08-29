/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:15:20 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/29 23:54:24 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

bool	is_wall(int y, int x, char **matrix)
{
	if (matrix[y][x] == '1')
		return (true);
	return (false);
}

void	is_escape(t_infos *infos, int keycode)
{
	if (keycode == 65307)
	{
		free_infos(infos);
		exit(0);
	}
}

void	move_up(double y, double x, t_map *map)
{
	y -= map->player.dir.y * map->player.speed;
	x -= map->player.dir.x * map->player.speed;
	if (is_wall(y, x, map->matrix))
		return ;
	map->player.pos.y = y;
	map->player.pos.x = x;
	if (map->matrix[(int)y + 1][(int)x] == '1' && y - (int)y > 0.85)
		map->player.pos.y = (int)y + 0.89;
	if (map->matrix[(int)y][(int)x + 1] == '1' && x - (int)x > 0.85)
		map->player.pos.x = (int)x + 0.89;
}

void	move_down(double y, double x, t_map *map)
{
	y += map->player.dir.y * map->player.speed;
	x += map->player.dir.x * map->player.speed;
	if (is_wall(y, x, map->matrix))
		return ;
	map->player.pos.y = y;
	map->player.pos.x = x;
	if (map->matrix[(int)y + 1][(int)x] == '1' && y - (int)y > 0.85)
		map->player.pos.y = (int)y + 0.89;
	if (map->matrix[(int)y][(int)x + 1] == '1' && x - (int)x > 0.85)
		map->player.pos.x = (int)x + 0.89;
}

void	move_left(double y, double x, t_map *map)
{
	double	y_delta;
	double	x_delta;

	y_delta = map->player.dir.x * map->player.speed;
	x_delta = -map->player.dir.y * map->player.speed;
	if (!is_wall(y + y_delta, x + x_delta, map->matrix))
	{
		map->player.pos.y += y_delta;
		map->player.pos.x += x_delta;
	}
}

void	move_right(double y, double x, t_map *map)
{
	double	y_delta;
	double	x_delta;

	y_delta = -map->player.dir.x * map->player.speed;
	x_delta = map->player.dir.y * map->player.speed;
	if (!is_wall(y + y_delta, x + x_delta, map->matrix))
	{
		map->player.pos.y += y_delta;
		map->player.pos.x += x_delta;
	}
}

void	turn_left(t_player *playr)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = playr->dir.x;
	playr->dir.x = playr->dir.x * cos(-0.05) - playr->dir.y * sin(-0.05);
	playr->dir.y = old_dir_x * sin(-0.05) + playr->dir.y * cos(-0.05);
	old_plane_x = playr->plane.x;
	playr->plane.x = playr->plane.x * cos(-0.05) - playr->plane.y * sin(-0.05);
	playr->plane.y = old_plane_x * sin(-0.05) + playr->plane.y * cos(-0.05);
}

void	turn_right(t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir.x;
	player->dir.x = player->dir.x * cos(0.05) - player->dir.y * sin(0.05);
	player->dir.y = old_dir_x * sin(0.05) + player->dir.y * cos(0.05);
	old_plane_x = player->plane.x;
	player->plane.x = player->plane.x * cos(0.05) - player->plane.y * sin(0.05);
	player->plane.y = old_plane_x * sin(0.05) + player->plane.y * cos(0.05);
}

int	move_keys(int keycode, void *param)
{
	t_infos		*infos;
	t_player	*player;

	infos = (t_infos *)param;
	player = &infos->minimap->player;
	if (keycode == 122)
		move_down(player->pos.y, player->pos.x, infos->minimap);
	else if (keycode == 115)
		move_up(player->pos.y, player->pos.x, infos->minimap);
	if (keycode == 113)
		move_right(player->pos.y, player->pos.x, infos->minimap);
	else if (keycode == 100)
		move_left(player->pos.y, player->pos.x, infos->minimap);
	if (keycode == 65361)
		turn_left(player);
	else if (keycode == 65363)
		turn_right(player);
	draw(infos->minimap, infos->mlx_infos, infos->mlx);
	is_escape(infos, keycode);
	return (0);
}
