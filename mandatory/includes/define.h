/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:06:29 by hsilverb          #+#    #+#             */
/*   Updated: 2023/12/15 12:16:01 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define WIDTH 1980
# define HEIGHT 1080
# define MOVE_SPEED 0.05
# define ROT_SPEED 0.03

# define ERR_ARG "Wrong number of arguments : ./cub3d maps/map_name.cub"
# define ERR_FILE "File not found : ./cub3d maps/map_name.cub"
# define NO_ERR "North texture : NO ./path_to_the_north_texture"
# define SO_ERR "South texture : SO ./path_to_the_south_texture"
# define EA_ERR "East texture : EA ./path_to_the_east_texture"
# define WE_ERR "West texture : WE ./path_to_the_west_texture"
# define F_ERR "Floor color, R,G,B colors in range [0,255] : F 220,100,0"
# define C_ERR "Ceiling color, R,G,B colors in range [0,255] : C 220,100,0"
# define COLORS_ERR "R,G,B colors in range [0,255] : C 220,100,0 / F 220,100,0"
# define ERR_MALLOC "Malloc was unsuccessful"

#endif
