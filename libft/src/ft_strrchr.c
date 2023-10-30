/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 07:46:45 by akhellad          #+#    #+#             */
/*   Updated: 2023/10/30 11:22:49 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i --;
	}
	return (0);
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
