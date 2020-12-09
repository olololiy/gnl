/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:29:15 by vfurr             #+#    #+#             */
/*   Updated: 2020/12/09 22:31:33 by vfurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	static char *buf;
	int i;
	int size;
	
	size	= 0;
	i 		= 0;
	if (!buf)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		buf = NULL;
	}
	while ((*line)[i] == '\0')
	{
		write (1, "tut\n", 1);
		if (buf && *buf != '\0')//излишнее условие
			ft_strjoinn(*line, &buf, &i);
		else
		{
			buf = buf - size;
			size =  read(fd, buf, BUFFER_SIZE);
			if (size == (-1))
				return (-1);
			buf[size + 1] = '\0';
		}
	}
	*line[i] = '\0';
	if (size < BUFFER_SIZE)
		return (0);
	else
		return (1);
}

int main()
{
	char *line;
	int fd;

	fd = open("text.txt", O_RDONLY);
	printf("%d", get_next_line(fd, &line));
	printf("%s\n", line);
}
