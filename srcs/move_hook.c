/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:15:20 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/30 15:28:48 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

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

void	turn_left(t_player *playr)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = playr->dir.x;
	playr->dir.x = playr->dir.x * cos(-0.02) - playr->dir.y * sin(-0.02);
	playr->dir.y = old_dir_x * sin(-0.02) + playr->dir.y * cos(-0.02);
	old_plane_x = playr->plane.x;
	playr->plane.x = playr->plane.x * cos(-0.02) - playr->plane.y * sin(-0.02);
	playr->plane.y = old_plane_x * sin(-0.02) + playr->plane.y * cos(-0.02);
}

void	turn_right(t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir.x;
	player->dir.x = player->dir.x * cos(0.02) - player->dir.y * sin(0.02);
	player->dir.y = old_dir_x * sin(0.02) + player->dir.y * cos(0.02);
	old_plane_x = player->plane.x;
	player->plane.x = player->plane.x * cos(0.02) - player->plane.y * sin(0.02);
	player->plane.y = old_plane_x * sin(0.02) + player->plane.y * cos(0.02);
}
