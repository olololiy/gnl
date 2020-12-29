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
	while (str && *str != '\0' && *str != '\n' )
	{
        str++;
		i++;
	}
	return (i);
}

char	*ft_strjoinn(char *line, char **s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*b;
	int i;

	i = 0;
    lens2 = ft_strlenn(*s2);
	lens1 = ft_strlenn(line);
	b = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));//после этого утечка line (str1)
	if (!b) {
       //free(line);
       return (0);
    }
	while (line && line[i] != '\0')
	{
         *b = line[i];
         i++;
         b++;
	}
	//if(!(*line))
	free(line);
      while (**s2 != '\0' && **s2 != '\n')
      {
          *b = **s2;
          (*s2)++;//вот так делай
          b++;
          i++;
      }
      *b = '\0';
      b = b - i;
      return (b);
  }


