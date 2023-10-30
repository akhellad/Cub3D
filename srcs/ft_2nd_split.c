/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2nd_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:51:51 by akhellad          #+#    #+#             */
/*   Updated: 2023/10/30 12:57:00 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

static int	ft_word(char *str, char *set)
{
	int	i;
	int	word;
	int	count;

	word = 1;
	i = 0;
	count = 0;
	while(str[i])
	{
		if(in_set(str[i], set))
			word = 1;
		else
		{
			if(word == 1)
				count++;
			word = 0;
		}
		i++;
	}
	return (count);
}

static char	**ft_free(char **ptr, int i)
{
	while (i >= 0)
		free(ptr[i--]);
	free(ptr);
	return (NULL);
}

static char	*ft_worddup(char *str, char *set, int *index)
{
	char	*ptr;
	int		count;
	int		pos;

	count = 0;
	while (in_set(str[*index], set) && str[*index])
		(*index)++;
	pos = *index;
	while (!in_set(str[*index], set) && str[*index])
	{
		count++;
		(*index)++;
	}
	ptr = malloc(count + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, str + pos, count + 1);
	return (ptr);
}

char    **ft_2nd_split(char const	*s, char *set, int *len)
{
	char	**ptr;
	int		count;
	int		i;
	int		index;

	index = 0;
	i = 0;
	if(!s)
		return (NULL);
	count = ft_word((char *)s, set);
	ptr = malloc(sizeof(char *) * (count + 1));
	if (!ptr)
		return (NULL);
	while (i < count)
	{
		ptr[i] = ft_worddup((char *)s, set, &index);
		if(!ptr[i])
			return (ft_free(ptr, i));
		i++;
	}
	ptr[i] = 0;
	if (len)
		*len = i;
	return (ptr);
}