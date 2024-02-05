/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:52:48 by akhellad          #+#    #+#             */
/*   Updated: 2024/01/04 13:16:47 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3Dbonus.h"

void	update_rays(t_game *game)
{
	game->ray->dir.y = cos(game->ray->angle);
	game->ray->dir.x = sin(game->ray->angle);
	game->ray->plane.y = -game->ray->dir.x * 0.8;
	game->ray->plane.x = game->ray->dir.y * 0.8;
}

static void	check_and_recenter_mouse(int x, int y, t_game *game)
{
	int	threshold_x;
	int	threshold_y;

	threshold_x = WIDTH * 0.06;
	threshold_y = HEIGHT * 0.1;
	if (x < threshold_x || x > WIDTH - threshold_x || y < threshold_y \
			|| y > HEIGHT - threshold_y)
	{
		mlx_mouse_move(game->mlx->mlx, game->mlx->win, WIDTH >> 1, HEIGHT >> 1);
		game->mouse_ignore = 1;
	}
}

int	ft_mouse_rot(int x, int y, t_game *game)
{
	static int	last_x = -1;
	int			delta_x;

	if (last_x == -1)
	{
		last_x = WIDTH / 2;
	}
	if (game->mouse_ignore)
	{
		last_x = WIDTH / 2;
		game->mouse_ignore = 0;
		return (0);
	}
	delta_x = x - last_x;
	last_x = x;
	game->ray->angle += delta_x * MOUSE_SENSITIVITY;
	update_rays(game);
	mlx_mouse_hide(game->mlx->mlx, game->mlx->win);
	check_and_recenter_mouse(x, y, game);
	return (0);
}

void	ft_rot_left(t_game *game)
{
	game->ray->angle -= ROT_SPEED;
	update_rays(game);
}

void	ft_rot_right(t_game *game)
{
	game->ray->angle += ROT_SPEED;
	update_rays(game);
}
