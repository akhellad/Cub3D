/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:26:04 by akhellad          #+#    #+#             */
/*   Updated: 2023/10/31 10:45:15 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

int	main(int ac, char **av)
{
	t_cub3d	cub;

	if (!check_args(&cub, ac, av[1]))
		exit(EXIT_FAILURE);
	init_cub(&cub, av[1]);
	draw_map(&cub);
	free_utils(cub);
	return (0);
}
