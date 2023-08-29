/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:06:20 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/29 23:46:47 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

int main(int ac, char **av)
{
    t_infos	infos;

	initialisation(ac, av, &infos);
    mlx_put_image_to_window(infos.mlx->mlx, infos.mlx->window, infos.minimap->img_tmp->img, 0, 0);
	mlx_hook(infos.mlx->window, 2, 1L << 0, &move_keys, &infos);
	mlx_loop(infos.mlx->mlx);
	free_infos(&infos);
	exit(0);
}