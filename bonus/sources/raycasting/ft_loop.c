/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:54:30 by akhellad          #+#    #+#             */
/*   Updated: 2024/01/04 13:08:52 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3Dbonus.h"

static void	ft_init_values(t_game *game, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIDTH - 1;
	game->ray->raydir.x = game->ray->dir.x + game->ray->plane.x * camera_x;
	game->ray->raydir.y = game->ray->dir.y + game->ray->plane.y * camera_x;
	game->ray->map.x = (int)game->ray->pos.x;
	game->ray->map.y = (int)game->ray->pos.y;
	game->ray->delta_dist.x = 1 / game->ray->raydir.x;
	game->ray->delta_dist.y = 1 / game->ray->raydir.y;
	if (game->ray->delta_dist.x < 0)
		game->ray->delta_dist.x *= -1;
	if (game->ray->delta_dist.y < 0)
		game->ray->delta_dist.y *= -1;
}

static void	ft_calculate_side_dist(t_game *game)
{
	if (game->ray->raydir.x < 0)
	{
		game->ray->step_pos.x = -1;
		game->ray->side_dist.x = (game->ray->pos.x - game->ray->map.x) \
			* game->ray->delta_dist.x;
	}
	else
	{
		game->ray->step_pos.x = 1;
		game->ray->side_dist.x = (game->ray->map.x + 1.0 - game->ray->pos.x) \
			* game->ray->delta_dist.x;
	}
	if (game->ray->raydir.y < 0)
	{
		game->ray->step_pos.y = -1;
		game->ray->side_dist.y = (game->ray->pos.y - game->ray->map.y) \
			* game->ray->delta_dist.y;
	}
	else
	{
		game->ray->step_pos.y = 1;
		game->ray->side_dist.y = (game->ray->map.y + 1.0 - game->ray->pos.y) \
			* game->ray->delta_dist.y;
	}
}

void	display_minimap(t_game *game)
{
	draw_minimap(game);
	draw_player_on_minimap(game);
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, \
		game->minimap.img, 0, 0);
}

int	ft_loop(t_game *game)
{
	int		x;

	ft_move(game);
	x = 0;
	while (x++ < WIDTH)
	{
		ft_init_values(game, x);
		ft_calculate_side_dist(game);
		ft_cast_ray(game);
		ft_calculate_positions(game);
		ft_draw_line(game, &game->mlx->img, x);
	}
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, \
		game->mlx->img.img, 0, 0);
	display_minimap(game);
	return (0);
}
