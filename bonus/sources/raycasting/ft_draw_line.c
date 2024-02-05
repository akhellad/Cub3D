/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:56:59 by akhellad          #+#    #+#             */
/*   Updated: 2023/12/14 23:05:55 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3Dbonus.h"

static unsigned int	ft_get_color(t_img *data, int x, int y)
{
	int		color;
	char	*dst;

	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

static void	draw_ceiling(t_game *game, t_img *img, int x, int y)
{
	double	dist;
	int		color;

	dist = (HEIGHT / 2.0) / (HEIGHT / 2.0 - y);
	color = apply_fog(game->ceiling_color, dist);
	ft_mlx_pixel_put(img, x, y, color);
}

static void	draw_floor(t_game *game, t_img *img, int x, int y)
{
	double	dist;
	int		color;

	dist = (HEIGHT / 2.0) / (y - HEIGHT / 2.0);
	color = apply_fog(game->floor_color, dist);
	ft_mlx_pixel_put(img, x, y, color);
}

static void	draw_wall(t_game *game, t_img *img, int x, int y)
{
	int		color;

	game->ray->tex.y = (int)game->ray->tex_pos & (game->image_width - 1);
	game->ray->tex_pos += game->ray->step;
	color = ft_get_color(&game->texture[game->ray->side], \
			game->ray->tex.x, game->ray->tex.y);
	color = apply_fog(color, game->ray->perp_wall_dist);
	ft_mlx_pixel_put(img, x, y, color);
}

void	ft_draw_line(t_game *game, t_img *img, int x)
{
	int		y;

	y = 0;
	while (y <= HEIGHT)
	{
		if (y < game->ray->draw_start)
			draw_ceiling(game, img, x, y);
		else if (y > game->ray->draw_end)
			draw_floor(game, img, x, y);
		else
			draw_wall(game, img, x, y);
		y++;
	}
}
