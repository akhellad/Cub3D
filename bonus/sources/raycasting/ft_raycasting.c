/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:50:46 by ahmedkhella       #+#    #+#             */
/*   Updated: 2023/12/17 14:41:26 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3Dbonus.h"

static void	ft_mlx_hook_loop(t_game *game)
{
	mlx_hook(game->mlx->win, 2, 1L << 0, ft_hook_keypress, game);
	mlx_hook(game->mlx->win, 3, 1L << 1, ft_hook_keyrelease, game);
	mlx_hook(game->mlx->win, 6, 1L << 6, ft_mouse_rot, game);
	mlx_hook(game->mlx->win, 17, 0, ft_exit, game);
	mlx_loop_hook(game->mlx->mlx, ft_loop, game);
	mlx_loop(game->mlx->mlx);
}

void	init_minimap(t_game *game)
{
	game->minimap.img = mlx_new_image(game->mlx->mlx, \
		MINIMAP_WIDTH, MINIMAP_HEIGHT);
	game->minimap.addr = mlx_get_data_addr(game->minimap.img, \
		&game->minimap.bits_per_pixel, &game->minimap.line_length, \
		&game->minimap.endian);
}

int	ft_raycasting(t_game *game)
{
	game->mlx->img.img = mlx_new_image(game->mlx->mlx, WIDTH, HEIGHT);
	game->mlx->img.addr = mlx_get_data_addr(game->mlx->img.img, \
		&game->mlx->img.bits_per_pixel, &game->mlx->img.line_length, \
		&game->mlx->img.endian);
	init_minimap(game);
	ft_init_ray(game);
	if (ft_init_textures(game))
		return (ft_free_mlx(game), 1);
	ft_mlx_hook_loop(game);
	return (0);
}
