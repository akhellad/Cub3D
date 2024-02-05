/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:15:57 by hsilverb          #+#    #+#             */
/*   Updated: 2023/11/09 20:46:32 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while ((haystack[i] && needle[i]) && (len != 0))
	{
		while (haystack[i] == needle[i] && len != 0)
		{
			i++;
			len--;
			if (needle[i] == '\0')
				return ((char *)haystack);
			if (haystack[i] != needle[i])
				len += i;
		}
		haystack++;
		i = 0;
		len--;
	}
	return (NULL);
}
