/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 22:19:37 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/30 17:06:56 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

int	initialisation(int ac, char **av, t_infos *infos)
{
	if (ac == 1)
	{
		printf("%s", NOA);
		exit(0);
	}
	infos->mlx = init_mlx("Cub3D");
	infos->mlx_infos = init_infos();
	if (arg_check(ac, av[1], infos->mlx_infos) == 0)
	{
		free_mlx_infos_on_error(infos->mlx_infos, infos);
		exit(0);
	}
	infos->minimap = init_map(infos->mlx_infos, infos->mlx->mlx);
	init_textures(infos);
		if (infos->minimap->tex == NULL)
		return (printf("%s", MALLOC_FAIL), 1);
	return (0);
}

t_mlx_infos	*init_infos(void)
{
	t_mlx_infos	*mlx_infos;

	mlx_infos = malloc(sizeof(t_mlx_infos));
	if (mlx_infos == NULL)
		return (printf("%s", MALLOC_FAIL), NULL);
	mlx_infos->map_copy = NULL;
	mlx_infos->raw_map = NULL;
	mlx_infos->player = NULL;
	mlx_infos->no = ft_strdup("X");
	mlx_infos->so = ft_strdup("X");
	mlx_infos->we = ft_strdup("X");
	mlx_infos->ea = ft_strdup("X");
	mlx_infos->f_color[0] = -1;
	mlx_infos->f_color[1] = -1;
	mlx_infos->f_color[2] = -1;
	mlx_infos->c_color[0] = -1;
	mlx_infos->c_color[1] = -1;
	mlx_infos->c_color[2] = -1;
	mlx_infos->reading_pos = 0;
	mlx_infos->map_length = 0;
	mlx_infos->error = 0;
	return (mlx_infos);
}

void init_textures(t_infos *infos)
{
    infos->mlx_infos->t_no = malloc(sizeof(t_mlx_texture));
    infos->mlx_infos->t_no->img_ptr = malloc(sizeof(t_img));
    infos->mlx_infos->t_so = malloc(sizeof(t_mlx_texture));
    infos->mlx_infos->t_so->img_ptr = malloc(sizeof(t_img));
    infos->mlx_infos->t_we = malloc(sizeof(t_mlx_texture));
    infos->mlx_infos->t_we->img_ptr = malloc(sizeof(t_img));
    infos->mlx_infos->t_ea = malloc(sizeof(t_mlx_texture));
    infos->mlx_infos->t_ea->img_ptr = malloc(sizeof(t_img));
    infos->mlx_infos->t_no->img_ptr->img = mlx_xpm_file_to_image(infos->mlx->mlx, infos->mlx_infos->no, \
								&(infos->mlx_infos->t_no->width), &(infos->mlx_infos->t_no->height));
    infos->mlx_infos->t_no->img_ptr->adrr = mlx_get_data_addr(infos->mlx_infos->t_no->img_ptr->img, \
	&(infos->mlx_infos->t_no->img_ptr->bpp), &(infos->mlx_infos->t_no->img_ptr->lengh), &(infos->mlx_infos->t_no->img_ptr->endian));
    infos->mlx_infos->t_so->img_ptr->img = mlx_xpm_file_to_image(infos->mlx->mlx, infos->mlx_infos->so, \
								&(infos->mlx_infos->t_so->width), &(infos->mlx_infos->t_so->height));
    infos->mlx_infos->t_so->img_ptr->adrr = mlx_get_data_addr(infos->mlx_infos->t_so->img_ptr->img, \
	&(infos->mlx_infos->t_so->img_ptr->bpp), &(infos->mlx_infos->t_so->img_ptr->lengh), &(infos->mlx_infos->t_so->img_ptr->endian));
    infos->mlx_infos->t_we->img_ptr->img = mlx_xpm_file_to_image(infos->mlx->mlx, infos->mlx_infos->we, \
								&(infos->mlx_infos->t_we->width), &(infos->mlx_infos->t_we->height));
    infos->mlx_infos->t_we->img_ptr->adrr = mlx_get_data_addr(infos->mlx_infos->t_we->img_ptr->img, \
	&(infos->mlx_infos->t_we->img_ptr->bpp), &(infos->mlx_infos->t_we->img_ptr->lengh), &(infos->mlx_infos->t_we->img_ptr->endian));
	infos->mlx_infos->t_ea->img_ptr->img = mlx_xpm_file_to_image(infos->mlx->mlx, infos->mlx_infos->ea, \
								&(infos->mlx_infos->t_ea->width), &(infos->mlx_infos->t_ea->height));
    infos->mlx_infos->t_ea->img_ptr->adrr = mlx_get_data_addr(infos->mlx_infos->t_ea->img_ptr->img, \
	&(infos->mlx_infos->t_ea->img_ptr->bpp), &(infos->mlx_infos->t_ea->img_ptr->lengh), &(infos->mlx_infos->t_ea->img_ptr->endian));
	infos->mlx_infos->t_no = resize_texture(infos->mlx_infos->t_no, 64, 64);
    infos->mlx_infos->t_so = resize_texture(infos->mlx_infos->t_so, 64, 64);
    infos->mlx_infos->t_we = resize_texture(infos->mlx_infos->t_we, 64, 64);
    infos->mlx_infos->t_ea = resize_texture(infos->mlx_infos->t_ea, 64, 64);

}
