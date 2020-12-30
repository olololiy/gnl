/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:47:28 by vfurr             #+#    #+#             */
/*   Updated: 2020/12/30 23:30:59 by vfurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlenn(const char *str)
{
	int i;

	i = 0;
	while (str && *str != '\0' && *str != '\n')
	{
		str++;
		i++;
	}
	return (i);
}

char		*ft_strjoinn(char *line, char **buf, int i, int length2)
{
	int		length1;
	char	*new_line;

	length2 = ft_strlenn(*buf);
	length1 = ft_strlenn(line);
	if (!(new_line = (char *)malloc(sizeof(char) * (length1 + length2 + 1))))
	{
		free(line);
		return (0);
	}
	while (line && line[++i] != '\0')
	{
		*new_line = line[i];
		new_line++;
	}
	free(line);
	while (**buf != '\0' && **buf != '\n')
	{
		*new_line = **buf;
		(*buf)++;
		new_line++;
		i++;
	}
	*new_line = '\0';
	return (new_line - i);
}
