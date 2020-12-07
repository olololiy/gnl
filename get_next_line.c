/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:29:15 by vfurr             #+#    #+#             */
/*   Updated: 2020/12/07 23:00:10 by vfurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
//# include <string.h>
# include <unistd.h>


void ft_proc_for_buf(char **buf, **line, )
{
	char *fline = '\0';
	while 
	line = ft_strjoin(line, buf);
	
	if (buf == '\0')
	{
		buf = buf - BUFFER_SIZE;
		*buf = '\0';
	}

}

int get_next_line(int fd, char **line)
{
	static char *buf;
	int i;
	int size;
	
	size = 0;
	if (buf == NULL)
		buf = malloc(char *(BUFFER_SIZE + 1));
	while (line[i] = '\0')
		if (*buf || *b == '\n')
			ft_strjoin(line, &buf, i)
		else
		{
			buf = buf - size
			size =  read(fd, buf, 10);	
		}
		line[i] = '\0';
	return 0;

}

int main()
{
	char *line;
	int fd;

	fd = open("text.txt", O_RDONLY);
	printf("%d", get_next_line(fd, &line));
	printf("%s\n", line);
}
