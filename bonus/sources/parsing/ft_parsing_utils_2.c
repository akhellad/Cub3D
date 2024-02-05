/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:15:05 by hsilverb          #+#    #+#             */
/*   Updated: 2024/01/04 13:10:35 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3Dbonus.h"

int	is_empty(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (!ft_is_white_spaces(s[i]))
			return (0);
	return (1);
}

int	ft_strchr_index(const char *s, char *c)
{
	int		i;
	int		j;
	char	*str;

	str = (char *) s;
	i = 0;
	while (str[i])
	{
		j = -1;
		while (c[++j])
			if (s[i] == c[j])
				return (i);
		i++;
	}
	return (-1);
}

int	in_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*dup_line(char *src, int len)
{
	char	*dst;
	int		i ;
	int		j ;

	i = -1;
	dst = ft_calloc(sizeof(char), len);
	while (++i < len - 1)
		dst[i] = 'x';
	i = 0;
	j = -1;
	while (src && src[++j])
	{
		i++;
		if (in_set(src[j], ""))
			dst[i] = src[j];
	}
	return (dst);
}
