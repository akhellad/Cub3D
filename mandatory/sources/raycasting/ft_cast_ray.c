/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:35:18 by akhellad          #+#    #+#             */
/*   Updated: 2023/12/14 21:35:22 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_hit_north_south(t_game *game)
{
	game->ray->side_dist.x += game->ray->delta_dist.x;
	game->ray->map.x += game->ray->step_pos.x;
	if (game->ray->map.x > game->ray->pos.x)
		game->ray->side = SOUTH;
	else
		game->ray->side = NORTH;
	game->ray->boolean = 1;
}

static void	ft_hit_east_west(t_game *game)
{
	game->ray->side_dist.y += game->ray->delta_dist.y;
	game->ray->map.y += game->ray->step_pos.y;
	if (game->ray->map.y > game->ray->pos.y)
		game->ray->side = EAST;
	else
		game->ray->side = WEST;
	game->ray->boolean = 0;
}

void	ft_cast_ray(t_game *game)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (game->ray->side_dist.x < game->ray->side_dist.y)
			ft_hit_north_south(game);
		else
			ft_hit_east_west(game);
		if (game->map[game->ray->map.x][game->ray->map.y] == '1')
			hit = 1;
	}
}
