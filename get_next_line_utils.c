/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:47:28 by vfurr             #+#    #+#             */
/*   Updated: 2020/12/06 17:52:56 by vfurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_strjoinn(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*b;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	b = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!b)
		return (0);
	while (s1[i] != '\0')
	{
		b[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' || s2[j] != '\n')
		b[i++] = s2[j++];
	b[i] = '\0';
	return (b);
}
