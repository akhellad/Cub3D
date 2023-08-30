/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 23:25:33 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/30 15:24:29 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

int	valid_options(char *line, t_mlx_infos *infos)
{
	if (check_options(line) == 1)
		return (1);
	if (check_double(line, infos) == 1)
		return (1);
	if (ft_strncmp(line, "NO .", 4) == 0
		|| ft_strncmp(line, "SO .", 4) == 0
		|| ft_strncmp(line, "WE .", 4) == 0
		|| ft_strncmp(line, "EA .", 4) == 0)
		if (validate_texture(line, infos) == 0)
			return (0);
	if ((ft_strncmp(line, "F ", 2) == 0 && ft_isdigit(line[2]) == 1)
		|| (ft_strncmp(line, "C ", 2) == 0 && ft_isdigit(line[2]) == 1))
		if (validate_color(line, infos) == 0)
			return (0);
	if (ft_strcmp(infos->no, "X") == 0
		&& ft_strcmp(infos->so, "X") == 0
		&& ft_strcmp(infos->we, "X") == 0
		&& ft_strcmp(infos->ea, "X") == 0
		&& infos->f_color[0] != -1 && infos->c_color[0] != -1)
		return (1);
	else
		return (0);
}

int	check_options(char *line)
{
	int	flag;

	flag = 0;
	if (line[0] != '\n' && line[3] != ' '
		&& line[4] != '.' && line[5] != '/'
		&& ft_strncmp(line, "NO", 2) != 0
		&& ft_strncmp(line, "SO", 2) != 0
		&& ft_strncmp(line, "WE", 2) != 0
		&& ft_strncmp(line, "EA", 2) != 0
		&& ft_strncmp(line, "F", 1) != 0
		&& ft_strncmp(line, "C", 1) != 0)
		flag++;
	if (flag != 0)
		return (printf("%s", WRONG_ATTRIBUTES), 1);
	return (0);
}

int	check_double(char *line, t_mlx_infos *infos)
{
	if ((ft_strncmp(line, "NO .", 4) == 0 && ft_strcmp(infos->no, "X") == 0)
		|| (ft_strncmp(line, "SO ", 4) == 0
			&& ft_strcmp(infos->so, "X") == 0)
		|| (ft_strncmp(line, "WE .", 4) == 0
			&& ft_strcmp(infos->we, "X") == 0)
		|| (ft_strncmp(line, "EA .", 4) == 0
			&& ft_strcmp(infos->ea, "X") == 0)
		|| ((ft_strncmp(line, "F ", 2) == 0) && infos->f_color[0] != -1)
		|| ((ft_strncmp(line, "C ", 2) == 0) && infos->c_color[0] != -1))
		return (printf("%s", DUPLICATE), 1);
	return (0);
}

int	validate_texture(char *line, t_mlx_infos *infos)
{
	if (validate_no_so(line, infos) == 0
		|| validate_we_ea(line, infos) == 0)
		return (0);
	return (1);
}

int	can_be_opened(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("%s", TEX_FILE_WRONG);
		return (0);
	}
	close(fd);
	return (1);
}
