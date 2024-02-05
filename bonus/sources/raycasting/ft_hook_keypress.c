/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_keypress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:56:42 by akhellad          #+#    #+#             */
/*   Updated: 2023/12/14 23:05:55 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3Dbonus.h"

int	ft_hook_keypress(int key, t_game *game)
{
	if (key == ESC)
		ft_exit(game);
	if (key == LEFT)
		game->rot_left = 1;
	else if (key == RIGHT)
		game->rot_right = 1;
	else if (key == W)
		game->move_up = 1;
	else if (key == S)
		game->move_down = 1;
	else if (key == A)
		game->move_left = 1;
	else if (key == D)
		game->move_right = 1;
	return (0);
}

int	ft_hook_keyrelease(int key, t_game *game)
{
	(void)key;
	if (key == LEFT)
		game->rot_left = 0;
	else if (key == RIGHT)
		game->rot_right = 0;
	else if (key == W)
		game->move_up = 0;
	else if (key == S)
		game->move_down = 0;
	else if (key == A)
		game->move_left = 0;
	else if (key == D)
		game->move_right = 0;
	return (0);
}
