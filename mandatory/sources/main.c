/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:15:24 by hsilverb          #+#    #+#             */
/*   Updated: 2023/12/11 17:15:25 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_init_window(t_game *game)
{
	game->mlx->mlx = mlx_init();
	if (!game->mlx->mlx)
		ft_error_msg(ERR_MALLOC, game);
	game->mlx->win = mlx_new_window(game->mlx->mlx, WIDTH, HEIGHT, "Cub3D");
	if (!game->mlx->win)
		ft_error_msg(ERR_MALLOC, game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		printf(ERR_ARG);
		printf("\n");
		return (1);
	}
	ft_init_struct(&game);
	ft_parsing(&game, argv[1]);
	ft_init_window(&game);
	ft_raycasting(&game);
	return (0);
}
