/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:29:15 by vfurr             #+#    #+#             */
/*   Updated: 2020/12/10 22:41:38 by vfurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 32

int get_next_line(int fd, char **line)
{
	static char *buf;
	int i;
	int size;
	
	size	= 0;
	i 		= 0;
	if (!buf)
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (*buf == '\0' || (*line)[i] == '\0')
	{
        if(*buf == '\0')
		{
			buf = buf - size;				//возможно эту строчку можно запихнуть в следующую
			size =  read(fd, buf, BUFFER_SIZE);
			if (size == (-1))				
				return (-1);
			buf[size + 1] = '\0';
		}
		if (buf != NULL && *buf != '\0')	//излишнее условие//нет
            line =	ft_strjoinn(*line, &buf, &i);
	}
	*line[i] = '\0';
	if (size < BUFFER_SIZE)
		return (0);
	return (1);
}

int main()
{
	char *line;
	int fd;

	fd = open("/Users/vfurr/workplace/gnl/text.txt", O_RDONLY);
	printf("%d", get_next_line(fd, &line));
	printf("%s\n", line);
}
