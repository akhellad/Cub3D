/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:15:07 by hsilverb          #+#    #+#             */
/*   Updated: 2023/12/19 14:36:28 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3Dbonus.h"

bool	ft_valid_tex_char(char c)
{
	if (c == 'N' || c == 'W' || c == 'E' || c == 'S' || c == 'F' || \
		c == 'C' || c == 'X' || c == '\0')
	{
		return (true);
	}
	return (false);
}

char	**dup_map(t_game *game)
{
	char	**dup;
	int		i;

	dup = ft_calloc(sizeof(char *), game->map_height + 5);
	dup[0] = dup_line(NULL, game->map_width + 4);
	i = 0;
	while (i++ <= game->map_height)
		dup[i] = dup_line(game->map[i - 1], game->map_width + 4);
	dup[game->map_height + 2] = dup_line(NULL, game->map_width + 4);
	return (dup);
}

bool	ft_double(char *str, t_game *game)
{
	if (!str)
		return (true);
	ft_error_msg("Same texture or color found twice in .cub file !", game);
	return (false);
}

void	ft_check_textures(t_game *game)
{
	if (!game->north)
		ft_error_msg(NO_ERR, game);
	if (!game->south)
		ft_error_msg(SO_ERR, game);
	if (!game->west)
		ft_error_msg(WE_ERR, game);
	if (!game->east)
		ft_error_msg(EA_ERR, game);
	if (!game->ceiling)
		ft_error_msg(C_ERR, game);
	if (!game->floor)
		ft_error_msg(F_ERR, game);
}
