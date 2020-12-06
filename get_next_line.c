/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:29:15 by vfurr             #+#    #+#             */
/*   Updated: 2020/12/06 20:41:58 by vfurr            ###   ########.fr       */
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
	while (
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
	if (buf == NULL)
	{
		buf = malloc(char *(BUFFER_SIZE + 1));
		buf[BUFFER_SIZE] = '\0';
	}
	if (buf)
	//	printf("%s", "D");
		ft_proc_for_buf(&buf, &line);
else
	{
	//	printf("%s", "S");
		
		read(fd, buf, 10);
		ft_proc_for_buf(&buf, &line);
	}
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
