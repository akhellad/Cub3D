/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 22:34:30 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/29 13:26:19 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

int	valid_args(char	*map_file, t_mlx_infos *infos)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (printf("%s", CANNOT_OPEN), 0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		infos->reading_pos++;
		if (valid_options(line, infos) == 1)
		{
			free(line);
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	if(!line)
		return (printf("%s", MISSING_ATTRIBUTES), 0);
	get_map_length(fd, map_file, infos);
	if (!handle_map(infos, fd) || infos->error == 1)
		return (printf("%s", INVALID_MAP), 0);
	return (close(fd), 1);
}

int	arg_check(int ac, char *av, t_mlx_infos *infos)
{
	int	i;

	i = ft_strlen(av);
	if (ac != 2)
		return (printf("%s", TMA), 0);
	else if(av && i > 3  && av[i - 1] == 'b' && av[i - 2] == 'u'
		&& av[i - 3] == 'c' && av[i - 4] == '.')
	{
		if (!valid_args(av, infos))
			return (0);
	}
	else
		return(printf("%s", WRONG_EXTENSION), 0);
	return (1);
}
