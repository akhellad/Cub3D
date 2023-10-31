/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:45:35 by akhellad          #+#    #+#             */
/*   Updated: 2023/10/31 10:43:52 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

int	key_pressed(int keycode, t_cub3d *cub)
{
	if (keycode == UP || keycode == UP_ARROW)
		cub->player.walk = -1;
	else if (keycode == DOWN || keycode == DOWN_ARROW)
		cub->player.walk = 1;
	else if (keycode == RIGHT)
		cub->player.turn = 1;
	else if (keycode == LEFT)
		cub->player.turn = -1;
	else if (keycode == LEFT_ARROW)
		cub->player.rotate = -TURN_SPEED;
	else if (keycode == RIGHT_ARROW)
		cub->player.rotate = TURN_SPEED;
	else if (keycode == ESC)
	{
		mlx_destroy_window(cub->mlx.mlx_ptr, cub->mlx.win);
		ft_exit(cub, 0);
	}
	return (1);
}

int	key_released(int keycode, t_cub3d *cub)
{
	if (keycode == UP || keycode == UP_ARROW)
		cub->player.walk = 0;
	else if (keycode == DOWN || keycode == DOWN_ARROW)
		cub->player.walk = 0;
	else if (keycode == RIGHT)
		cub->player.turn = 0;
	else if (keycode == LEFT)
		cub->player.turn = 0;
	else if (keycode == LEFT_ARROW)
		cub->player.rotate = 0;
	else if (keycode == RIGHT_ARROW)
		cub->player.rotate = 0;
	return (1);
}
