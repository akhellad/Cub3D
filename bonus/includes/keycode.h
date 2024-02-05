/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:32:41 by henrik            #+#    #+#             */
/*   Updated: 2023/12/14 21:00:11 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODE_H
# define KEYCODE_H

# ifdef __APPLE__
#  define LEFT 123
#  define RIGHT 124
#  define W 13
#  define S 1
#  define A 0
#  define D 2
#  define ESC 53

# else
#  define LEFT 65361
#  define RIGHT 65363
#  define W 119
#  define S 115
#  define A 97
#  define D 100
#  define ESC 65307
# endif

#endif
