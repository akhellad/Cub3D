/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:14:56 by hsilverb          #+#    #+#             */
/*   Updated: 2023/12/14 23:05:55 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3Dbonus.h"

static bool	ft_check_colors(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (false);
	while (str[i] == ',' || ft_isdigit(str[i]) == 1)
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if ((str[i] == '\0' || str[i] == '\n') && count == 2)
		return (true);
	else
		return (false);
}

static bool	ft_check_values(char *str)
{
	int		i;
	int		nb_tmp;
	char	**tmp;
	bool	ret;

	i = 0;
	nb_tmp = 0;
	tmp = ft_split(str, ',');
	if (!str)
		return (false);
	ret = true;
	while (tmp[i])
	{
		nb_tmp = ft_atoi(tmp[i]);
		if (nb_tmp < 0 || nb_tmp > 255)
			ret = false;
		i++;
	}
	if (i != 3)
		ret = false;
	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
	return (ret);
}

static char	*ft_extract_colors(char *str, char c, t_game *game)
{
	int		i;
	char	*color;
	int		stop;

	i = 0;
	color = NULL;
	stop = 0;
	while (stop < 2 && (str[i] == c || str[i] == ' ' || str[i] == '\t'))
	{
		if (str[i] == c)
			stop++;
		i++;
	}
	if (ft_check_colors(str + i) == false)
		ft_error_msg(COLORS_ERR, game);
	if (ft_check_values(str + i) == false)
		ft_error_msg(COLORS_ERR, game);
	color = str + i;
	return (color);
}

static int	ft_convert_to_hexa(char *str, t_game *game)
{
	int		i;
	int		nb_tmp;
	char	**tmp;
	int		result;
	int		shift;

	i = 0;
	nb_tmp = 0;
	result = 0;
	shift = 16;
	tmp = ft_split(str, ',');
	if (!str)
		ft_error_msg(ERR_MALLOC, game);
	while (tmp[i])
	{
		nb_tmp = ft_atoi(tmp[i]);
		result += nb_tmp << shift;
		shift -= 8;
		i++;
	}
	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
	return (result);
}

int	ft_get_colors(t_game *game)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (game->file[i])
	{
		while (game->file[i][y] == ' ')
			y++;
		if (game->file[i][y] == '1' || game->file[i][y] == '0')
			break ;
		if (ft_valid_tex_char(game->file[i][y]) == false)
			ft_error_msg("Invalid char found .cub file", game);
		else if (game->file[i][y] == 'F' && ft_double(game->floor, game))
			game->floor = ft_extract_colors(game->file[i], 'F', game);
		else if (game->file[i][y] == 'C' && ft_double(game->ceiling, game))
			game->ceiling = ft_extract_colors(game->file[i], 'C', game);
		i++;
		y = 0;
	}
	if (game->floor == NULL || game->ceiling == NULL)
		ft_error_msg(COLORS_ERR, game);
	game->floor_color = ft_convert_to_hexa(game->floor, game);
	game->ceiling_color = ft_convert_to_hexa(game->ceiling, game);
	return (i);
}
