/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:35:19 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/30 14:41:27 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

void	free_infos(t_infos *infos)
{
	free_map(infos, infos->minimap);
	free_mlx_infos(infos, infos->mlx_infos);
	mlx_del(infos->mlx);
}

void mlx_delete_texture(t_mlx_infos *mlx_infos, t_infos *infos)
{
    if (mlx_infos->t_no->img_ptr->img)
	{
        mlx_destroy_image(infos->mlx->mlx, mlx_infos->t_no->img_ptr->img);
		free(mlx_infos->t_no->img_ptr);
	}
    if (mlx_infos->t_so->img_ptr->img)
	{
        mlx_destroy_image(infos->mlx->mlx, mlx_infos->t_so->img_ptr->img);
		free(mlx_infos->t_so->img_ptr);
	}
    if (mlx_infos->t_we->img_ptr->img)
	{
        mlx_destroy_image(infos->mlx->mlx, mlx_infos->t_we->img_ptr->img);
		free(mlx_infos->t_we->img_ptr);
	}
    if (mlx_infos->t_ea->img_ptr->img)
	{
        mlx_destroy_image(infos->mlx->mlx, mlx_infos->t_ea->img_ptr->img);
		free(mlx_infos->t_ea->img_ptr);
	}
    free(mlx_infos->t_no);
    free(mlx_infos->t_so);
    free(mlx_infos->t_we);
    free(mlx_infos->t_ea);
}

void	free_mlx_infos(t_infos *infos, t_mlx_infos *mlx_infos)
{
	free(mlx_infos->no);
	free(mlx_infos->so);
	free(mlx_infos->we);
	free(mlx_infos->ea);
	mlx_delete_texture(mlx_infos, infos);
	free_char_array(mlx_infos->raw_map);
	free_char_array(mlx_infos->map_copy);
	free(mlx_infos);
}

void	free_map(t_infos *infos, t_map *map)
{
	if (map->img_tmp)
		del_image(infos->mlx, map->img_tmp);
	free_char_array(map->matrix);
	free(map->tex);
	free(map);
}
