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
#define BUFFER_SIZE 5

int get_next_line(int fd, char **line) {
	static char fbuf[BUFFER_SIZE + 1];
	int size;
	char *buf = fbuf;
	size = 0;
	**line = '\0';

	while (1) {
		if (*fbuf == '\0') {
			buf = buf - size;
			size = read(fd, buf, BUFFER_SIZE);
			buf[size + 1] = '\0';//убери. стек сразу с нулями идет(но это не точно)

		}

		if (!*line || size < 0)//что-то с fd
			return (-1);
		*line = ft_strjoinn(line, &buf);
		if (**line == (-1))
			return (-1);
		if (*buf == '\n') {
			buf++;
			return (1);// можно сделать тернарник с нижнем условием
		}
		if (size == 0)
			return (0);

	}
}


	/*size = 0;
    **line = '\0';
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
        return (-1);
	while (*buf == '\0' || *buf++ == '\n'||  *line[ft_strlenn(*line)] == '\0')//пока баф существует
	{
        if(*buf == '\0')
		{
			buf = buf - size;			    //возможно эту строчку можно запихнуть в следующую
			if(!(size =  read(fd, buf, BUFFER_SIZE)))
			{
                free(buf);
                return (-1);
            }
			buf[size + 1] = '\0';
		}
		if (*buf != NULL && *buf == '\0')
            *line =	ft_strjoinn(line, &buf);
        if (*buf == '\n')
            break;
	}
    *line[ft_strlenn(*line)] = '\0';
	if (size < BUFFER_SIZE)
		return (0);
	return (1);*/


/*int main()
{
	char *line1;
	int fd;
	*line1 = 'a';

	fd = open("/home/a/workplace/gnl/text.txt", O_RDONLY);
//	printf("%d", get_next_line(fd, &line));
//	printf("%s\n", line);
//    printf("%d", get_next_line(fd, &line));
//    printf("%s\n", line);
//    printf("%d", get_next_line(fd, &line));

    while(get_next_line(fd, &line1) >-1)
    {
        printf("%s\n", line1);
    }
}
*/