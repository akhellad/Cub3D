/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:15:00 by hsilverb          #+#    #+#             */
/*   Updated: 2024/01/04 13:10:28 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3Dbonus.h"

int	is_closed(t_game *game)
{
	char	**dup;
	int		y;
	int		x;

	y = -1;
	dup = dup_map(game);
	while (dup[++y])
	{
		x = -1;
		while (dup[y][++x])
		{
			if (dup[y][x] == 'x')
			{
				if ((dup[y][x + 1] && !in_set(dup[y][x + 1], "x1"))
					|| (dup[y + 1] && !in_set(dup[y + 1][x], "x1")))
					return (0);
				if ((x != 0 && !in_set(dup[y][x - 1], "x1"))
					|| (y != 0 && !in_set(dup[y - 1][x], "x1")))
					return (0);
			}
		}
	}
	tab_free(dup);
	return (1);
}

int	check_token(t_game *game)
{
	int	count;
	int	x;
	int	y;

	count = -1;
	y = -1;
	while (++y < game->map_height)
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (in_set(game->map[y][x], "NWES"))
			{
				game->p = game->map[y][x];
				count++;
			}
			else if (!in_set(game->map[y][x], " NWES01\t"))
				ft_error_msg("Invalid token\n", game);
		}
	}
	return (count);
}

void	check_map(t_game *game)
{
	if (!is_closed(game))
		ft_error_msg("Invalid map\n", game);
	if (check_token(game))
		ft_error_msg("Invalid map\n", game);
}

void	ft_parse_map(t_game *game)
{
	check_map(game);
}
