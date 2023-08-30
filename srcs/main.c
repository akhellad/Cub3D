/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:06:20 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/30 16:01:19 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	draw(t_map *map, t_mlx_infos *mlx_infos, t_mlx *mlx)
{
	draw_map(map, mlx_infos, mlx);
}

int	mouse_move(int x, int y, t_infos *infos)
{
	t_player	*player;
	float		last_m_x;

	(void)y;
	last_m_x = infos->mouse_x;
	player = &infos->minimap->player;
	if (last_m_x < x)
		turn_right(player);
	else if (last_m_x > x)
		turn_left(player);
	infos->mouse_x = x;
	draw(infos->minimap, infos->mlx_infos, infos->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_infos	infos;

	initialisation(ac, av, &infos);
	mlx_put_image_to_window(infos.mlx->mlx, infos.mlx->window, \
				infos.minimap->img_tmp->img, 0, 0);
	mlx_put_image_to_window(infos.mlx->mlx, infos.mlx->window, \
				infos.minimap->img_map->img, 0, 0);
	mlx_hook(infos.mlx->window, 6, 1L << 6, &mouse_move, &infos);
	mlx_hook(infos.mlx->window, 2, 1L << 0, &move_keys, &infos);
	mlx_loop(infos.mlx->mlx);
	free_infos(&infos);
	exit(0);
}
