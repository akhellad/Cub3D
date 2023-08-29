/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 00:42:34 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/29 13:26:19 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

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

void	set_map_error(t_mlx_infos *infos)
{
	printf("%s", DFS_ERROR);
	infos->error = 1;
}

void	dfs(char **map, int y, int x, t_mlx_infos *infos)
{
	(void)map;
	if (infos->error == true)
		return ;
	if (y < 0 || x < 0)
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