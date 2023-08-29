/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 00:36:12 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/29 16:56:49 by akhellad         ###   ########.fr       */
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

int	line_has_invalid_chars(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] == ' ' || line[i] == '0' || line[i] == '1'
			|| line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
			|| line[i] == 'E' || line[i] == '\t')
		{
			if (map_has_multiple_players_or_none(line[i], 'N') == 1)
				return (1);
			i++;
		}
		else if (line[i] == '\0')
			return (0);
		else
			return (printf("%s", INVALID_CHAR), 1);
	}
	return (0);
}

int	map_has_multiple_players_or_none(char c, char option)
{
	static int	n = 0;
	static int	s = 0;
	static int	w = 0;
	static int	e = 0;

	if (c == 'N')
		n++;
	else if (c == 'S')
		s++;
	else if (c == 'W')
		w++;
	else if (c == 'E')
		e++;
	if (n > 1 || s > 1 || w > 1 || e > 1)
		return (printf("%s", PLAYER_DUPLICATE), 1);
	if (option == 'Y')
	{
		if ((n + s + w + e) == 0)
			return (printf("%s", MISSING_PLAYER), 1);
		else if ((n + s + w + e) > 1)
			return (printf("%s", TOO_MANY_PLAYERS), 1);
	}
	return (0);
}

int	check_maps(t_mlx_infos *infos, int i)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	infos->raw_map[i] = NULL;
	if (map_has_multiple_players_or_none(' ', 'Y') == 1)
		return (0);
	infos->map_copy = copy_2d_char_array(infos->raw_map);
	get_player_pos(infos->map_copy, &y, &x);
	dfs(infos->map_copy, y, x, infos);
	free_char_array(infos->map_copy);
	if (infos->error == 1)
	{
		free_char_array(infos->raw_map);
		return (0);
	}
	infos->map_copy = NULL;
	if (infos->error == 1)
		return (0);
	return (1);
}

char	*copy_map_line(char *content)
{
	int		i;
	int		content_len;
	char	*line;

	i = -1;
	content_len = ft_strlen(content) + 1;
	line = malloc(sizeof(char) * content_len);
	if (line == NULL)
		return (printf("%s", MALLOC_FAIL), NULL);
	while (content[++i] != '\0')
		line[i] = content[i];
	line[i] = '\0';
	return (line);
}

int	handle_map(t_mlx_infos *infos, int fd)
{
	int			i;
	static int	k = 0;
	char		*line;

	line = get_next_line(fd);
	while (k++ != infos->reading_pos)
		line = get_line(fd, line);
	infos->raw_map = malloc(sizeof(char *) * (infos->map_length + 1));
	if (infos->raw_map == NULL)
		return (printf("%s", MALLOC_FAIL), 1);
	i = 0;
	line = get_line(fd, line);
	while (line != NULL)
	{
		if (line_has_invalid_chars(line) == 1)
			return (0);
		infos->raw_map[i++] = copy_map_line(line);
		line = get_line(fd, line);
	}
	if (check_maps(infos, i) == 0)
		return (0);
	return (close(fd), 1);
}