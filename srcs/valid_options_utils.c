/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_options_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 23:27:09 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/30 15:24:39 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	save_texture_to_infos(char *file, t_mlx_infos *infos, char option)
{
	if (option == 'N')
	{
		free(infos->no);
		infos->no = ft_strdup(file);
	}
	if (option == 'S')
	{
		free(infos->so);
		infos->so = ft_strdup(file);
	}
	if (option == 'W')
	{
		free(infos->we);
		infos->we = ft_strdup(file);
	}
	if (option == 'E')
	{
		free(infos->ea);
		infos->ea = ft_strdup(file);
	}
	free(file);
}

void	free_char_array(char **array)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	save_color_to_infos(char **rgb, t_mlx_infos *infos, char option)
{
	if (option == 'F')
	{
		infos->f_color[0] = ft_atoi(rgb[0]);
		infos->f_color[1] = ft_atoi(rgb[1]);
		infos->f_color[2] = ft_atoi(rgb[2]);
	}
	else if (option == 'C')
	{
		infos->c_color[0] = ft_atoi(rgb[0]);
		infos->c_color[1] = ft_atoi(rgb[1]);
		infos->c_color[2] = ft_atoi(rgb[2]);
	}
	free_char_array(rgb);
}

int	validate_no_so(char *line, t_mlx_infos *infos)
{
	char	*file;

	if (ft_strncmp(line, "NO", 2) == 0)
	{
		file = ft_strtrim(line, "NO \n");
		if (can_be_opened(file) == 1)
			save_texture_to_infos(file, infos, 'N');
		else
			return (free(file), 0);
	}
	if (ft_strncmp(line, "SO", 2) == 0)
	{
		file = ft_strtrim(line, "SO \n");
		if (can_be_opened(file) == 1)
			save_texture_to_infos(file, infos, 'S');
		else
			return (free(file), 0);
	}
	return (1);
}

int	validate_we_ea(char *line, t_mlx_infos *infos)
{
	char	*file;

	if (ft_strncmp(line, "WE", 2) == 0)
	{
		file = ft_strtrim(line, "WE \n");
		if (can_be_opened(file) == 1)
			save_texture_to_infos(file, infos, 'W');
		else
			return (free(file), 0);
	}
	if (ft_strncmp(line, "EA", 2) == 0)
	{
		file = ft_strtrim(line, "EA \n");
		if (can_be_opened(file) == 1)
			save_texture_to_infos(file, infos, 'E');
		else
			return (free(file), 0);
	}
	return (1);
}
