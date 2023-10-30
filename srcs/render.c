/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:49:43 by akhellad          #+#    #+#             */
/*   Updated: 2023/10/30 17:02:54 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	my_mlx_put_pixel(t_my_mlx *data, int y, int x, int color)
{
	char	*dst;

	dst = data->pixel_data
		+ (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_floor_sky(t_cub3d *cub)
{
	float	y;
	float	x;

	y = -1;
	while (++y < WINDOW_HEIGTH)
	{
		x = -1;
		while (y < WINDOW_HEIGTH / 2 && ++x < WINDOW_WIDTH)
			my_mlx_put_pixel(&cub->map_img, y, x, cub->ceil);
		while (y > WINDOW_HEIGTH / 2 && ++x < WINDOW_WIDTH)
			my_mlx_put_pixel(&cub->map_img, y, x, cub->floor);
	}
}

int render_2dmap(t_cub3d *cub)
{
    mlx_clear_window(cub->mlx.mlx_ptr, cub->mlx.win);
    new_black_obj(&cub->map_img, WINDOW_HEIGTH, WINDOW_WIDTH);
	cub->player.angel += cub->player.rotate;
	move_player(cub, cub->player.turn, cub->player.walk);
    draw_floor_sky(cub);
    raycast(cub);
    mlx_put_image_to_window(cub->mlx.mlx_ptr,
		cub->mlx.win, cub->map_img.img, 0, 0);
    return (1);
}