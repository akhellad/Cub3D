/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:15:09 by hsilverb          #+#    #+#             */
/*   Updated: 2023/12/14 23:05:55 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3Dbonus.h"

static void	ft_check_extension(char *str, t_game *game)
{
	int	i;

	i = ft_strlen(str);
	if (!(str[i - 1] == 'b' && str[i - 2] == 'u'
			&& str[i - 3] == 'c' && str[i - 4] == '.' ))
	{
		ft_error_msg("Invalid map extension !\n", game);
	}
}

static int	ft_count_lines(char *file, t_game *game)
{
	char	*line;
	int		fd;
	int		nb_lines;

	nb_lines = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error_msg("Invalid .cub file\n", game);
	line = get_next_line(fd);
	while (line)
	{
		nb_lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!nb_lines)
		ft_error_msg(".cub file is empty", game);
	return (nb_lines);
}

static void	ft_get_file(char *file, int nb_lines, t_game *game)
{
	int		fd;
	char	*line;

	game->map_height = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_perror_exit();
	game->file = malloc(sizeof(char *) * (nb_lines + 1));
	if (!game->file)
		ft_error_msg("ERR_MALLOC", game);
	line = get_next_line(fd);
	while (line)
	{
		game->file[game->map_height++] = line;
		line = get_next_line(fd);
	}
	game->file[game->map_height] = NULL;
	close(fd);
}

void	copy_map(t_game *game, int i)
{
	int	j;
	int	start_map;

	start_map = i;
	j = -1;
	game->map_width = 0;
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		return ;
	while (game->file[i])
	{
		if (ft_strlen(game->file[i]) > (size_t)game->map_width)
			game->map_width = ft_strlen(game->file[i]) - 1;
		if (is_empty(game->file[i]))
		{
			game->map_height = i - start_map - 1;
			ft_error_msg("Invalid map\n", game);
		}
		game->map[++j] = ft_substr(game->file[i], 0,
				ft_strchr_index(game->file[i], "\n"));
		i++;
	}
	if (ft_strchr_index(game->file[i - 1], "\n") != -1)
		ft_error_msg("Invalid map\n", game);
}

void	ft_parsing(t_game *game, char *file)
{
	int	nb_lines;
	int	start_map1;
	int	start_map2;

	nb_lines = ft_count_lines(file, game);
	ft_check_extension(file, game);
	ft_get_file(file, nb_lines, game);
	start_map1 = ft_get_textures(game->file, game);
	start_map2 = ft_get_colors(game);
	ft_check_textures(game);
	if (start_map1 > start_map2)
	{
		game->map_height -= start_map1 + 1;
		copy_map(game, start_map1);
	}
	else
	{
		game->map_height -= start_map2 + 1;
		copy_map(game, start_map2);
	}
	check_map(game);
}
