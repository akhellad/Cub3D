/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 23:23:58 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/30 15:29:05 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

t_img	*del_image(t_mlx *mlx, t_img *img)
{
	if (img != NULL)
	{
		if (img->img != NULL)
			mlx_destroy_image(mlx->mlx, img->img);
		ft_memdel((void **)&img);
	}
	return (NULL);
}

t_img	*new_image(void *mlx)
{
	t_img		*img;

	img = ft_memalloc(sizeof(t_img));
	if (img == NULL)
		return (NULL);
	img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (img->img == NULL)
		return (del_image(mlx, img));
	img->adrr = mlx_get_data_addr(img->img, &img->bpp, &img->lengh,
			&img->endian);
	img->bpp /= 8;
	return (img);
}

t_mlx	*mlx_del(t_mlx *mlx)
{
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->img != NULL)
		del_image(mlx, mlx->img);
	ft_memdel((void **)&mlx);
	return (NULL);
}

t_mlx	*init_mlx(char *title)
{
	t_mlx	*mlx;

	mlx = ft_memalloc(sizeof(t_mlx));
	if (mlx == NULL)
		return (NULL);
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIDTH, \
					HEIGHT, title);
	if (mlx->mlx == NULL || mlx->window == NULL)
		return (mlx_del(mlx));
	return (mlx);
}

void	free_mlx_infos_on_error(t_mlx_infos *mlx_infos, t_infos *infos)
{
	free(mlx_infos->no);
	free(mlx_infos->so);
	free(mlx_infos->we);
	free(mlx_infos->ea);
	free(mlx_infos);
	mlx_del(infos->mlx);
}
