/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fog.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:50:26 by akhellad          #+#    #+#             */
/*   Updated: 2023/12/19 14:12:25 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3Dbonus.h"

static double	compute_fog_intensity(double distance, double fog_density)
{
	double	fog_intensity;

	fog_intensity = distance * fog_density;
	if (fog_intensity > 1.0)
		fog_intensity = 1.0;
	return (fog_intensity);
}

static int	mix_colors(int color1, int color2, double factor)
{
	int	r;
	int	g;
	int	b;

	r = (int)((1 - factor) * ((color1 >> 16) & 0xFF) \
		+ factor * ((color2 >> 16) & 0xFF));
	g = (int)((1 - factor) * ((color1 >> 8) & 0xFF) \
		+ factor * ((color2 >> 8) & 0xFF));
	b = (int)((1 - factor) * (color1 & 0xFF) + factor * (color2 & 0xFF));
	return (r << 16 | g << 8 | b);
}

int	apply_fog(int original_color, double distance)
{
	double	fog_intensity;
	int		fog_color;
	double	fog_density;

	fog_color = 0x000000;
	fog_density = 0.3;
	fog_intensity = compute_fog_intensity(distance, fog_density);
	return (mix_colors(original_color, fog_color, fog_intensity));
}
