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
	while (*str != '\n' && *str != '\0')
	{
        str++;
		i++;
	}
	return (i);
}

char	*ft_strjoinn(char **s1, char **s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*b;
	int i;

	i = 0;
	lens2 = ft_strlenn(*s2);
	lens1 = ft_strlenn(*s1);
	//s1 = s1 - lens1;
//	if (*s1 == '\0')
//	    lens1 = 1;

	b = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!b)
		return (0);
	while (**s1 != '\0')
	{
		*b = **s1;
		i++;
		b++;
        (*s1)++;
	}

	while (**s2 != '\0' && **s2 != '\n')
	{
        *b = **s2;
		(*s2)++;//вот так делай
        b++;
		i++;
	}
	//*b = *s2;
	*b = '\0';
    //(*s2)++;
	b = b - i;
	return (b);
}
