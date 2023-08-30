/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 00:42:34 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/30 14:39:12 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	get_map_length(int fd, char *map_file, t_mlx_infos *infos)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL && line_cotains_only_spaces(line) == 1)
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line != NULL)
	{
		infos->map_length++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		printf("%s", CANNOT_OPEN);
		exit(0);
	}
}

int	line_cotains_only_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] == ' ' || line[i] == '\t' || line[i] == '\v'
			|| line[i] == '\r' || line[i] == '\f')
			i++;
		else
			return (0);
	}
	return (1);
}

void	get_player_pos(char **map, int *py, int *px)
{
	int		y;
	int		x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\n' && map[y][x] != '\0')
		{
			if (ft_strchr("NESW", map[y][x]) != NULL)
			{
				*py = y;
				*px = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	dfs(char **map, int y, int x, t_mlx_infos *infos)
{
	(void)map;
	if (infos->error == true)
		return ;
	if (y < 0 || x < 0 || y >= HEIGHT || x >= WIDTH - 1)
		return ;
	if (infos->map_copy[y][x] == ' ' || infos->map_copy[y][x] == '\n')
		return (set_map_error(infos));
	if (infos->map_copy[y][x] == '1')
		return ;
	if (infos->map_copy[y][x] != '0' && infos->map_copy[y][x] != 'N'
		&& infos->map_copy[y][x] != 'S' && infos->map_copy[y][x] != 'E'
		&& infos->map_copy[y][x] != 'W' && infos->map_copy[y][x] != 'D'
		&& infos->map_copy[y][x] != 'K')
		return ;
	infos->map_copy[y][x] = 'X';
	dfs(infos->map_copy, y + 1, x + 1, infos);
	dfs(infos->map_copy, y + 1, x, infos);
	dfs(infos->map_copy, y + 1, x - 1, infos);
	dfs(infos->map_copy, y, x + 1, infos);
	dfs(infos->map_copy, y, x - 1, infos);
	dfs(infos->map_copy, y - 1, x + 1, infos);
	dfs(infos->map_copy, y - 1, x, infos);
	dfs(infos->map_copy, y - 1, x - 1, infos);
}

char	**copy_2d_char_array(char **array)
{
	int		i;
	char	**result;

	i = 0;
	if (array == NULL)
		return (NULL);
	while (array[i] != NULL)
		i++;
	result = malloc(sizeof(char *) * (i + 1));
	if (result == NULL)
		return (printf("%s", MALLOC_FAIL), NULL);
	i = -1;
	while (array[++i] != NULL)
		result[i] = copy_map_line(array[i]);
	result[i] = NULL;
	return (result);
}