/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:37:53 by akhellad          #+#    #+#             */
/*   Updated: 2023/10/31 10:41:48 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

int	my_abs(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

char	*get_info_value(t_cub3d *cub, const char *id)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (ft_strcmp(cub->info[i].id, id))
			return (cub->info[i].content);
		i++;
	}
	return (0);
}
