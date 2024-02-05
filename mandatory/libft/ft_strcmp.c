/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:01:26 by hsilverb          #+#    #+#             */
/*   Updated: 2023/11/22 10:52:59 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*copy_s1;
	unsigned char	*copy_s2;

	copy_s1 = (unsigned char *)s1;
	copy_s2 = (unsigned char *)s2;
	while (*copy_s1 && *copy_s2 && *copy_s1 == *copy_s2)
	{
		copy_s1++;
		copy_s2++;
	}
	return (*copy_s1 - *copy_s2);
}
