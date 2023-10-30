/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:33:52 by akhellad          #+#    #+#             */
/*   Updated: 2023/10/30 16:36:29 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void    init_player(t_cub3d *cub)
{
	int	x;
	int	y;

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