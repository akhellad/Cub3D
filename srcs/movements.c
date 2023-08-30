/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:27:32 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/30 15:28:35 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

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
