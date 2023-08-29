/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:24:16 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/29 22:00:48 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

char	*ft_strdup2(char *str, int start, int end)
{
	char	*result;
	int		i;

	result = malloc(sizeof(char) * (end - start + 1));
	if (result == NULL)
		return (printf("%s",MALLOC_FAIL), NULL);
	i = -1;
	while (start + ++i != end)
		result[i] = str[i + start];
	result[i] = '\0';
	return (result);
}

char	*init_line(char *old_line, int l)
{
	char	*res;
	char	*line;
	int		i;
	int		k;

	i = 0;
	while (old_line[i] != '\0' && old_line[i] != '\n')
		i++;
	line = ft_strdup2(old_line, 0, i);
	k = ft_strlen(line);
	old_line = ft_strdup(line);
	free(line);
	res = dup3((MINIMAP_SIZE / R) / 2, 'V');
	res = ft_strjoin(res, old_line);
	res = ft_strjoin(res, dup3(l - (MINIMAP_SIZE / R) / 2 - k, 'V'));
	i = -1;
	while (res[++i] != '\0')
		if (res[i] == ' ')
			res[i] = 'V';
	return (res);
}

char	**init_matrix(char **m, int height)
{
	char	**matrix;
	int		len;
	int		i;

	matrix = malloc(sizeof(char *) * (height + MINIMAP_SIZE / R + 1));
	if (matrix == NULL)
		return (printf("%s", MALLOC_FAIL), NULL);
	matrix[height + MINIMAP_SIZE / R] = NULL;
	len = get_longest_line(m) + (MINIMAP_SIZE / R) - 1;
	i = -1;
	while (++i < (MINIMAP_SIZE / R) / 2)
		matrix[i] = dup3(len, 'V');
	while (m[i - (MINIMAP_SIZE / R) / 2] != NULL)
	{
		matrix[i] = init_line(m[i - (MINIMAP_SIZE / R) / 2], len);
		i++;
	}
	while (i != height + MINIMAP_SIZE / R)
		matrix[i++] = dup3(len, 'V');
	return (matrix);
}

void	set_player_position(t_map *minimap)
{
	int		y;
	int		x;

	y = 0;
	minimap->player.speed = 0.07;
	while (minimap->matrix[y] != NULL)
	{
		x = 0;
		while (minimap->matrix[y][x] != '\n' && minimap->matrix[y][x] != '\0')
		{
			if (ft_strchr("NESW", minimap->matrix[y][x]) != NULL)
			{
				minimap->player.pos.y = y;
				minimap->player.pos.x = x;
				minimap->player.dir.x = cos(get_angle(minimap->matrix[y][x]));
				minimap->player.dir.y = sin(get_angle(minimap->matrix[y][x]));
				set_plan(&minimap->player.plane, minimap->matrix[y][x]);
				minimap->matrix[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}

t_img* my_mlx_new_image(void* mlx, uint32_t width, uint32_t height)
{
	t_img *img;

	img = malloc(sizeof(t_img));
	if (img == NULL)
		return (printf("%s", MALLOC_FAIL), NULL);
	img->img = mlx_new_image(mlx, width, height);
	return (img);
}

t_map	*init_map(t_mlx_infos *mlx_infos, void *mlx)
{
	t_map	*minimap;

	minimap = malloc(sizeof(t_map));
	if (minimap == NULL)
		return (printf("%s", MALLOC_FAIL), NULL);
	minimap->matrix = init_matrix(mlx_infos->raw_map, mlx_infos->map_length);
	set_player_position(minimap);
	minimap->img_tmp = malloc(sizeof(t_img));
	if (minimap->img_tmp == NULL)
		return (printf("%s", MALLOC_FAIL), NULL);
	minimap->img_tmp->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	minimap->img_tmp->adrr = mlx_get_data_addr(minimap->img_tmp->img, &minimap->img_tmp->bpp, &minimap->img_tmp->lengh, &minimap->img_tmp->endian);
	minimap->tex = malloc(sizeof(t_tex));
	return (minimap);
}
