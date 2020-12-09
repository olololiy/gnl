/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:47:28 by vfurr             #+#    #+#             */
/*   Updated: 2020/12/09 22:32:49 by vfurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlenn(const char *str)
{
	int i;

	i = 0;
	while (*str != '\0' || *str != '\n')
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strjoinn(char const *s1, char **s2, int *i)
{
	size_t	lens1;
	size_t	lens2;
	char	*b;

	i = 0;
	lens1 = ft_strlenn(s1);
	lens2 = ft_strlenn(*s2);
	b = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!b)
		return (0);
	while (s1[*i] != '\0')
	{
		b[*i] = s1[*i];
		i++;
	}
	while (*s2 != '\0' || **s2 != '\n')
	{
		b[*i] = **s2;
		(*s2)++;
		(*i)++;
	}
		b[*i] = **s2;
	return (b);
}
