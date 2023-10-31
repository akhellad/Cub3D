/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:33:52 by akhellad          #+#    #+#             */
/*   Updated: 2023/10/31 10:22:59 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	init_player(t_cub3d *cub)
{
	int		y;
	int		x;

	y = -1;
	cub->player.turn_speed = TURN_SPEED;
	cub->player.walk_speed = PLAYER_SPEED;
	cub->player.walk = 0;
	cub->player.turn = 0;
	while (cub->map[++y])
	{
		x = -1;
		while (cub->map[y][++x])
		{
			if (cub->map[y][x] == cub->p)
			{
				cub->player.x = (TILE_SIZE * x + TILE_SIZE / 2);
				cub->player.y = (TILE_SIZE * y) + TILE_SIZE / 2;
				return ;
			}
		}
	}
}

void	draw_player(t_cub3d *cub, float y_pos, float x_pos, int color)
{
	t_obj	img;

	cub->player.x = x_pos;
	cub->player.y = y_pos;
	img.x_pos = cub->player.x * SCALE_SIZE;
	img.y_pos = cub->player.y * SCALE_SIZE;
	if (img.x_pos > 10 * TILE_SIZE * SCALE_SIZE)
		img.x_pos = 10 * TILE_SIZE * SCALE_SIZE;
	if (img.y_pos > 10 * TILE_SIZE * SCALE_SIZE)
		img.y_pos = 10 * TILE_SIZE * SCALE_SIZE;
	new_obj(&cub->mini_img, img, color, 3);
}
