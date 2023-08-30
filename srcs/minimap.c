/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:13:34 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/30 14:06:18 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"


void	draw_minimap(t_map *m, t_vector *p, int i, t_mlx *mlx)
{
	int	k;

	m->y = -1;
	while (++m->y < MINIMAP_SIZE)
	{
		k = ((MINIMAP_SIZE / R) / 2) * (-1);
		m->x = -1;
		while (++m->x < MINIMAP_SIZE)
		{
			if (m->matrix[(int)p->y + i][(int)p->x + k] == '1'
				|| (m->x % R == (int)m->player.pos.x - (int)m->player.pos.x * 10))
				my_mlx_pixel_put(m->img_map, m->x, m->y, rgb(230, 0, 0, 200));
			else if (m->matrix[(int)p->y + i][(int)p->x + k] == '0'
				|| (m->x % R == (int)m->player.pos.x - (int)m->player.pos.x * 10))
				my_mlx_pixel_put(m->img_map, m->x, m->y, rgb(145, 145, 145, 200));
			else if (m->matrix[(int)p->y + i][(int)p->x + k] == 'D'
				|| (m->x % R == (int)m->player.pos.x - (int)m->player.pos.x * 10))
				my_mlx_pixel_put(m->img_map, m->x, m->y, rgb(145, 0, 145, 200));
			else
				my_mlx_pixel_put(m->img_map, m->x, m->y, rgb(160, 190, 150, 100));
			if (m->x % R == 0)
				k++;
		}
		if ((m->y) % (R) == 0)
			i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, m->img_map->img, 0, 0);
}