/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:45:58 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/30 17:06:18 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void set_pixel_color(t_mlx_texture *texture, int x, int y, int color) {
	int pixel_index = (y * texture->width + x) * (texture->img_ptr->bpp / 8);
	texture->img_ptr->adrr[pixel_index] = (color >> 16) & 0xFF;  // Composante rouge (R)
	texture->img_ptr->adrr[pixel_index + 1] = (color >> 8) & 0xFF; // Composante verte (G)
	texture->img_ptr->adrr[pixel_index + 2] = color & 0xFF;        // Composante bleue (B)
	texture->img_ptr->adrr[pixel_index + 3] = (color >> 24) & 0xFF; // Composante alpha (A)
}


int interpolate_colors(t_mlx_texture *original_texture, float x_original, float y_original) {
	int x_floor = (int)x_original;
	int y_floor = (int)y_original;
	int x_ceil = x_floor + 1;
	int y_ceil = y_floor + 1;

	float x_fraction = x_original - x_floor;
	float y_fraction = y_original - y_floor;

	int c00 = get_pixel_color_util(x_floor, y_floor, original_texture);
	int c01 = get_pixel_color_util(x_floor, y_ceil, original_texture);
	int c10 = get_pixel_color_util(x_ceil, y_floor, original_texture);
	int c11 = get_pixel_color_util(x_ceil, y_ceil, original_texture);

	int interpolated_color = (int)((1 - x_fraction) * ((1 - y_fraction) * c00 + y_fraction * c01) + x_fraction * ((1 - y_fraction) * c10 + y_fraction * c11));

	return interpolated_color;
}


t_mlx_texture *resize_texture(t_mlx_texture *original_texture, int target_width, int target_height) 
{
    t_mlx_texture *resized_texture = malloc(sizeof(t_mlx_texture));
    resized_texture->width = target_width;
    resized_texture->height = target_height;
	resized_texture->img_ptr = original_texture->img_ptr;

    // Allez pixel par pixel dans la nouvelle texture et effectuez l'interpolation
    for (int x = 0; x < target_width; x++) {
        for (int y = 0; y < target_height; y++) {
            // Calculez les coordonnées correspondantes dans la texture d'origine
            float x_original = x * (original_texture->width - 1) / (target_width - 1);
            float y_original = y * (original_texture->height - 1) / (target_height - 1);

            // Effectuez l'interpolation pour obtenir la couleur du pixel redimensionné
            // (utilisez une méthode d'interpolation appropriée)
            int interpolated_color = interpolate_colors(original_texture, x_original, y_original);

            // Remplissez la couleur dans la nouvelle texture
            set_pixel_color(resized_texture, x, y, interpolated_color);
        }
    }

    return resized_texture;
}



void print_textures(t_map *map, int x, t_mlx_infos *mlx_infos) {
	t_mlx_texture *tex;
	int i;

	tex = set_variables(map, mlx_infos, x);

	while (map->tex->d_start < map->tex->d_end) {
		map->tex->tex.y = (int)map->tex->t_pos & (tex->height - 1);
		map->tex->tex.x = (int)((map->ray.x_hit_point) * (double)tex->width);
		map->tex->t_pos += map->tex->step;

		map->tex->color = get_pixel_color(tex, map->tex->tex.x / (double)tex->width, map->tex->tex.y / (double)tex->height);

		map->buffer[x][map->tex->d_start] = map->tex->color;
		map->tex->d_start++;
	}

	i = map->tex->d_start;
	while (i < HEIGHT)
		map->buffer[x][i++] = rgb(mlx_infos->f_color[0], mlx_infos->f_color[1], mlx_infos->f_color[2], 255);
}





void	draw_buff(t_img *img_tmp, int32_t buffer[WIDTH][HEIGHT], t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
			my_mlx_pixel_put(img_tmp, i, j, buffer[i][j]);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, img_tmp->img, 0, 0);
}

t_mlx_texture	*get_texture(t_map *map, t_mlx_infos *mlx_infost_mlx_infos)
{
	if (map->side == 0 && map->ray.dir.x > 0)
		return (mlx_infost_mlx_infos->t_ea);
	if (map->side == 0 && map->ray.dir.x < 0)
		return (mlx_infost_mlx_infos->t_we);
	if (map->side == 1 && map->ray.dir.y > 0)
		return (mlx_infost_mlx_infos->t_no);
	if (map->side == 1 && map->ray.dir.y < 0)
		return (mlx_infost_mlx_infos->t_so);
	return (NULL);
}

void	set_tex_struct(t_map *map)
{
	map->tex->line_height = (int)(HEIGHT / map->ray.wall_dist);
	map->tex->d_start = -map->tex->line_height / 2 + HEIGHT / 2;
	if (map->tex->d_start < 0)
		map->tex->d_start = 0;
	map->tex->d_end = map->tex->line_height / 2 + HEIGHT / 2;
	if (map->tex->d_end >= HEIGHT)
		map->tex->d_end = HEIGHT - 1;
	map->tex->step = 1.0 * 64 / map->tex->line_height;
	map->tex->t_pos = (map->tex->d_start - HEIGHT / 2
			+ map->tex->line_height / 2) * map->tex->step;
}

t_mlx_texture	*set_variables(t_map *map, t_mlx_infos *m_d, int x)
{
	int	i;

	set_tex_struct(map);
	if (map->side == 0)
		map->ray.x_hit_point = map->player.pos.y
			+ map->ray.wall_dist * map->ray.dir.y;
	else
		map->ray.x_hit_point = map->player.pos.x
			+ map->ray.wall_dist * map->ray.dir.x;
	map->ray.x_hit_point -= (int)map->ray.x_hit_point;
	map->tex->tex.x = (int)((map->ray.x_hit_point) * (double)64);
	if ((map->side == 0 && map->ray.dir.x > 0)
		|| (map->side == 1 && map->ray.dir.y < 0))
		map->tex->tex.x = 64 - map->tex->tex.x - 1;
	i = 0;
	while (i < map->tex->d_start)
		map->buffer[x][i++] = rgb(m_d->c_color[0],
				m_d->c_color[1], m_d->c_color[2], 255);
	return (get_texture(map, m_d));
}
