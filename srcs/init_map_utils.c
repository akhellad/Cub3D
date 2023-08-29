/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:33:05 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/29 13:45:12 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

double	get_angle(char c)
{
	if (c == 'S')
		return (M_PI_2);
	if (c == 'W')
		return (M_PI);
	if (c == 'N')
		return (M_PI + M_PI_2);
	return (M_PI * 2);
}

void	set_plan(t_vector *plane, char c)
{
	if (c == 'N')
	{
		plane->y = 0;
		plane->x = 1;
	}
	if (c == 'S')
	{
		plane->y = 0;
		plane->x = -1;
	}
	if (c == 'W')
	{
		plane->y = -1;
		plane->x = 0;
	}
	if (c == 'E')
	{
		plane->y = 1;
		plane->x = 0;
	}
}

char	*dup3(int size, char ch)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (printf("%s", MALLOC_FAIL), NULL);
	str[size] = '\0';
	while (i != size)
	{
		str[i] = ch;
		i++;
	}
	return (str);
}

int	get_longest_line(char **map)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (map[i] != NULL)
	{
		if (result < (int)ft_strlen(map[i]))
			result = (int)ft_strlen(map[i]);
		i++;
	}
	return (result);
}