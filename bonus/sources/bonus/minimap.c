/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:44:30 by akhellad          #+#    #+#             */
/*   Updated: 2024/01/04 13:08:41 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3Dbonus.h"

static void	put_player_pixel(t_game *game, int x, int y)
{
	int	color;

	if (x >= 0 && x < MINIMAP_WIDTH)
	{
		if (y >= 0 && y < MINIMAP_HEIGHT)
		{
			color = 0x0000FF;
			ft_mlx_pixel_put(&game->minimap, x, y, color);
		}
	}
}

void	draw_player_on_minimap(t_game *game)
{
	int	player_minimap_x;
	int	player_minimap_y;
	int	half_size;
	int	y;
	int	x;

	player_minimap_x = (int)(game->ray->pos.y * \
		((float)MINIMAP_WIDTH / (game->map_width + 1)));
	player_minimap_y = (int)(game->ray->pos.x * \
		((float)MINIMAP_HEIGHT / (game->map_height + 1)));
	half_size = PLAYER_SIZE / 2;
	y = -half_size;
	while (y <= half_size)
	{
		x = -half_size;
		while (x <= half_size)
		{
			put_player_pixel(game, player_minimap_x + x, player_minimap_y + y);
			x++;
		}
		y++;
	}
}

static void	put_map_pixel(t_game *game, int x, int y)
{
	int	color;
	int	map_x;
	int	map_y;

	map_x = (int)(x * ((float)(game->map_width + 1) \
		/ MINIMAP_WIDTH));
	map_y = (int)(y * ((float)(game->map_height + 1) \
		/ MINIMAP_HEIGHT));
	if (map_x >= 0 && map_x < (game->map_width + 1))
	{
		if (map_y >= 0 && map_y < (game->map_height + 1))
		{
			if (game->map[map_y][map_x] == '1')
				color = 0x000000;
			else
				color = 0x808B96;
			ft_mlx_pixel_put(&game->minimap, x, y, color);
		}
	}
}

void	draw_minimap(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < MINIMAP_HEIGHT)
	{
		x = 0;
		while (x < MINIMAP_WIDTH)
		{
			put_map_pixel(game, x, y);
			x++;
		}
		y++;
	}
}
