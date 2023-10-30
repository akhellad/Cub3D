/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:42:07 by akhellad          #+#    #+#             */
/*   Updated: 2023/10/30 16:50:39 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	new_main_img(t_cub3d *cub, t_my_mlx *data, int width, int height)
{
	data->img = mlx_new_image(cub->mlx.mlx_ptr,
			width, height);
	data->pixel_data = mlx_get_data_addr(data->img, &(data->bits_per_pixel),
			&(data->size_line), &(data->endian));
	data->height = height;
	data->width = width;
}

void	new_black_obj(t_my_mlx *data, int hiegth, int width)
{
	int			y;
	int			x;

	y = 0;
	while (y < hiegth)
	{
		x = 0;
		while (x < width)
		{
			my_mlx_put_pixel(data, y, x, 0x00000000);
			x++;
		}
		y++;
	}
}
