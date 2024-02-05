/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:53:58 by akhellad          #+#    #+#             */
/*   Updated: 2023/12/19 14:10:06 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3Dbonus.h"

static void	ft_move_up(t_game *game)
{
	t_point	value;

	value.x = game->map[(int)(game->ray->pos.x + game->ray->dir.x * \
		MOVE_SPEED)][(int)game->ray->pos.y];
	value.y = game->map[(int)game->ray->pos.x][(int)(game->ray->pos.y + \
		game->ray->dir.y * MOVE_SPEED)];
	if (value.x != '1')
		game->ray->pos.x += game->ray->dir.x * MOVE_SPEED;
	if (value.y != '1')
		game->ray->pos.y += game->ray->dir.y * MOVE_SPEED;
}

static void	ft_move_down(t_game *game)
{
	t_point	value;

	value.x = game->map[(int)(game->ray->pos.x - game->ray->dir.x * \
		MOVE_SPEED)][(int)game->ray->pos.y];
	value.y = game->map[(int)game->ray->pos.x][(int)(game->ray->pos.y - \
		game->ray->dir.y * MOVE_SPEED)];
	if (value.x != '1')
		game->ray->pos.x -= game->ray->dir.x * MOVE_SPEED;
	if (value.y != '1')
		game->ray->pos.y -= game->ray->dir.y * MOVE_SPEED;
}

static void	ft_move_left(t_game *game)
{
	t_point	value;

	value.x = game->map[(int)(game->ray->pos.x - game->ray->dir.y * \
			MOVE_SPEED)][(int)game->ray->pos.y];
	value.y = game->map[(int)game->ray->pos.x][(int)(game->ray->pos.y \
			+ game->ray->dir.x * MOVE_SPEED)];
	if (value.x != '1')
		game->ray->pos.x -= game->ray->dir.y * MOVE_SPEED;
	if (value.y != '1')
		game->ray->pos.y += game->ray->dir.x * MOVE_SPEED;
}

static void	ft_move_right(t_game *game)
{
	t_point	value;

	value.x = game->map[(int)(game->ray->pos.x + game->ray->dir.y * \
			MOVE_SPEED)][(int)game->ray->pos.y];
	value.y = game->map[(int)game->ray->pos.x][(int)(game->ray->pos.y \
			- game->ray->dir.x * MOVE_SPEED)];
	if (value.x != '1')
		game->ray->pos.x += game->ray->dir.y * MOVE_SPEED;
	if (value.y != '1')
		game->ray->pos.y -= game->ray->dir.x * MOVE_SPEED;
}

void	ft_move(t_game *game)
{
	if (game->rot_left)
		ft_rot_left(game);
	if (game->rot_right)
		ft_rot_right(game);
	if (game->move_up)
		ft_move_up(game);
	if (game->move_down)
		ft_move_down(game);
	if (game->move_right)
		ft_move_right(game);
	if (game->move_left)
		ft_move_left(game);
}
