/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:48:12 by ahmedkhella       #+#    #+#             */
/*   Updated: 2023/12/14 21:07:11 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_reset_ray(t_ray *ray)
{
	ray->pos.x = 0;
	ray->pos.y = 0;
	ray->dir.x = 0;
	ray->dir.y = 0;
	ray->plane.x = 0;
	ray->plane.y = 0;
	ray->raydir.x = 0;
	ray->raydir.y = 0;
	ray->side_dist.x = 0;
	ray->side_dist.y = 0;
	ray->delta_dist.x = 0;
	ray->delta_dist.y = 0;
	ray->map.x = 0;
	ray->map.y = 0;
	ray->step_pos.x = 0;
	ray->step_pos.y = 0;
	ray->tex_pos = 0;
	ray->step = 0;
	ray->perp_wall_dist = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
	ray->side = 0;
	ray->boolean = 0;
}

void	ft_init_mlx(t_game *game)
{
	int	i;

	i = 0;
	game->mlx = malloc(sizeof(t_mlx));
	if (game->mlx != NULL)
	{
		game->mlx->mlx = NULL;
		game->mlx->win = NULL;
	}
	else
		return ;
	i = 0;
	while (i < 4)
	{
		game->texture[i].img = NULL;
		i++;
	}
	game->file = NULL;
}

void	ft_init_struct(t_game *game)
{
	game->north = NULL;
	game->south = NULL;
	game->west = NULL;
	game->east = NULL;
	game->floor = NULL;
	game->ceiling = NULL;
	game->map = NULL;
	game->ray = NULL;
	game->expanded = 0;
	game->rot_left = 0;
	game->rot_right = 0;
	game->move_up = 0;
	game->move_down = 0;
	game->move_left = 0;
	game->move_right = 0;
	game->last_x = -1;
	ft_init_mlx(game);
}
