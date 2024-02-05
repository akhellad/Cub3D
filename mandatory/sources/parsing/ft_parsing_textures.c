/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:13:37 by hsilverb          #+#    #+#             */
/*   Updated: 2023/12/11 17:13:38 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*ft_extract_path(char *str, char c1, char c2, t_game *game)
{
	int	i;
	int	fd;
	int	stop;

	i = 0;
	stop = 0;
	while (stop < 3 && \
		(str[i] == c1 || str[i] == c2 || str[i] == ' ' || str[i] == '\t'))
	{
		if (str[i] == c1 || str[i] == c2)
			stop++;
		i++;
	}
	fd = open(str + i, O_RDONLY);
	if (fd < 0)
	{
		printf("Error : Impossible to access %c%c path\n", c1, c2);
		ft_free_all(game);
		perror(NULL);
		exit (EXIT_FAILURE);
	}
	close(fd);
	return (str + i);
}

int	ft_get_textures(char **file, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (file[y])
	{
		while (file[y][x] == ' ')
			x++;
		if (game->file[y][x] == '1' || game->file[y][x] == '0')
			break ;
		if (ft_valid_tex_char(game->file[y][x]) == false)
			ft_error_msg("Invalid char found .cub file", game);
		if (!ft_strncmp(file[y] + x, "NO", 2) && ft_double(game->north, game))
			game->north = ft_extract_path(file[y], 'N', 'O', game);
		if (!ft_strncmp(file[y] + x, "SO", 2) && ft_double(game->south, game))
			game->south = ft_extract_path(file[y], 'S', 'O', game);
		if (!ft_strncmp(file[y] + x, "WE", 2) && ft_double(game->west, game))
			game->west = ft_extract_path(file[y], 'W', 'E', game);
		if (!ft_strncmp(file[y] + x, "EA", 2) && ft_double(game->east, game))
			game->east = ft_extract_path(file[y], 'E', 'A', game);
		y++;
		x = 0;
	}
	return (y);
}
