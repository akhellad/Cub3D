/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 23:31:19 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/29 00:27:58 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

char	**split_rgb(char *line, char *trim_with)
{
	char	*trimmed_line;
	char	**rgb;

	trimmed_line = ft_strtrim(line, trim_with);
	rgb = ft_split(trimmed_line, ',');
	free(trimmed_line);
	return (rgb);
}

int	has_duplicate_rgb(char *line)
{
	static int	f;
	static int	c;

	f = 0;
	c = 0;
	if (line[0] == 'F')
		f++;
	else if (line[0] == 'C')
		c++;
	else if (f != 1 || c != 1)
		return (printf("%s", RGB_DUPLICATE), 1);
	return (0);
}

int	valid_rgb(char **rgb)
{
	if ((ft_atoi(rgb[0]) > 255 || ft_atoi(rgb[0]) < 0)
		|| (ft_atoi(rgb[1]) > 255 || ft_atoi(rgb[1]) < 0)
		|| (ft_atoi(rgb[2]) > 255 || ft_atoi(rgb[2]) < 0))
		return (printf("%s", RGB_IS), 0);
	else
		return (1);
}

int	rgb_contains_letters(char *line)
{
	int	i;

	i = 2;
	while (i < (int)ft_strlen(line) - 1)
	{
		if (line[i] == ',' || ft_isdigit(line[i]) == 1)
			i++;
		else
		{
			printf("RGB contains letters\n");
			return (1);
		}
	}
	return (0);
}

int	validate_color(char *line, t_mlx_infos *infos)
{
	char	**rgb;

	if (commacounter(line) == 0 || rgb_contains_letters(line) == 1
		|| has_duplicate_rgb(line) == 1)
		return (0);
	if (line[0] == 'F')
	{
		rgb = split_rgb(line, "F \n");
		if (valid_rgb(rgb) == 1)
			save_color_to_infos(rgb, infos, 'F');
		else
			return (free_char_array(rgb), 0);
	}
	if (line[0] == 'C')
	{
		rgb = split_rgb(line, "C \n");
		if (valid_rgb(rgb) == 1)
			save_color_to_infos(rgb, infos, 'C');
		else
			return (free_char_array(rgb), 0);
	}
	return (1);
}