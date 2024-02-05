/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:56:29 by akhellad          #+#    #+#             */
/*   Updated: 2023/12/19 14:17:05 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3Dbonus.h"

static void	ft_set_angle_and_vectors(t_game *game, double angle)
{
	game->ray->angle = angle;
	game->ray->dir.y = cos(game->ray->angle);
	game->ray->dir.x = sin(game->ray->angle);
	game->ray->plane.y = -game->ray->dir.x * 0.8;
	game->ray->plane.x = game->ray->dir.y * 0.8;
}

static void	ft_init_direction(t_game *game, char c)
{
	if (c == 'N')
	{
		ft_set_angle_and_vectors(game, 3 * M_PI_2);
	}
	else if (c == 'S')
	{
		ft_set_angle_and_vectors(game, M_PI_2);
	}
	else if (c == 'E')
	{
		ft_set_angle_and_vectors(game, 0);
	}
	else if (c == 'W')
	{
		ft_set_angle_and_vectors(game, M_PI);
	}
}

void	ft_init_ray(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->ray = malloc(sizeof(t_ray));
	if (!game->ray)
		ft_error_msg(ERR_MALLOC, game);
	ft_reset_ray(game->ray);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (ft_isalpha(game->map[i][j]))
			{
				ft_init_direction(game, game->map[i][j]);
				game->ray->pos.x = i + 0.5;
				game->ray->pos.y = j + 0.5;
				return ;
			}
			j++;
		}
		i++;
	}
}
