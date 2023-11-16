/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:57:52 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/16 15:16:21 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	colored_pixel_draw(t_cub3d *cub, t_walls_draw *obj, int start_x, \
							int texture_offset_x)
{
	int	texture_index;
	int	texture_height;
	int	texture_width;
	int	texture_pixel_index;

	texture_width = cub->textures[texture_index].width;
	texture_height = cub->textures[texture_index].height;
	texture_index = obj->direction;
	obj->offset_y = (obj->start_y - obj->text_start_pixel) * \
				((float)texture_height / obj->real_wall_len);
	texture_offset_x %= texture_width;
	obj->offset_y %= texture_height;
	texture_pixel_index = (int)obj->offset_y * texture_width + texture_offset_x;
	if (obj->start_y >= 0 && obj->start_y < WINDOW_HEIGTH)
		my_mlx_put_pixel(&cub->map_img, obj->start_y, start_x, \
		cub->textures[texture_index].addr[texture_pixel_index]);
}

void	draw_walls(t_cub3d *cub, t_raycast ray)
{
	t_walls_draw	obj;
	int				texture_offset_x;

	obj.dist = sqrt(pow(ray.x - cub->player.x, 2) + \
				pow(ray.y - cub->player.y, 2));
	obj.dist *= cos(cub->player.angel * (PI / 180.0) - \
				ray.angel * (PI / 180.0));
	obj.wall_len = (TILE_SIZE * WINDOW_HEIGTH) / obj.dist;
	obj.real_wall_len = obj.wall_len;
	if (obj.wall_len > WINDOW_HEIGTH)
		obj.wall_len = WINDOW_HEIGTH;
	obj.start_y = (WINDOW_HEIGTH - obj.wall_len) / 2;
	obj.text_start_pixel = (WINDOW_HEIGTH - obj.real_wall_len) / 2;
	obj.direction = cub->player.direction;
	while (obj.wall_len-- > 0)
	{
		if (obj.direction == NO || obj.direction == SO)
			texture_offset_x = ray.x;
		else
			texture_offset_x = ray.y;
		texture_offset_x %= TILE_SIZE;
		colored_pixel_draw(cub, &obj, ray.start_x, texture_offset_x);
		obj.start_y++;
	}
}
