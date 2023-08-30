/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:19:00 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/30 15:38:57 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->adrr + (y * data->lengh + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel_color_util(int x, int y, t_mlx_texture *tex)
{
	int				pixel_index;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;

	pixel_index = (y * tex->width + x) * (tex->img_ptr->bpp / 8);
	r = tex->img_ptr->adrr[pixel_index];
	g = tex->img_ptr->adrr[pixel_index + 1];
	b = tex->img_ptr->adrr[pixel_index + 2];
	a = tex->img_ptr->adrr[pixel_index + 3];
	return (rgb(r, g, b, a));
}

int	get_pixel_color(t_mlx_texture *tex, double tex_x, double tex_y)
{
	int	x;
	int	y;

	x = (int)(tex_x * (tex->width - 1));
	y = (int)(tex_y * (tex->height - 1));
	return (get_pixel_color_util(x, y, tex));
}
