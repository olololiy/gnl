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
    static char *buf;

    //*line = NULL;
    if (!line || (read(fd, 0, 0)) < 0 || BUFFER_SIZE < 1)//что-то с fd
        return (-1);
    *line = malloc(sizeof(char) * 1);
    *line = "\0";//not
    while (1) {
        if (buf == '\0' || *buf == '\0')
        {
            fbuf[0] = '\0';
            size = read(fd, fbuf, BUFFER_SIZE);
            fbuf[size] = '\0';//убери. стек сразу с нулями идет(но это не точно)
            buf = fbuf;
        }
        if (fbuf[0] == '\0')
        {//тернар со след строкой
            //if (**line != '\0')
              //   free(*line);
            return (0);
        }
        if (size < 0 /*|| !line*/)//что-то с fd
            return (-1);
        if (size > 0)
            *line = ft_strjoinn(line, &buf);
        if (*line == NULL) //seg
            return (-1);
        if (*buf == '\n' || (size == 0 && fbuf[0] == '\0')) {
            buf++;
            if (size == 0 && *buf == '\0')
                return (0);
            return (1);

        }
    }
    //ret 0
}
		/*if (*buf == '\n' || (size == 0 && fbuf[0] == '\0'))
		{
		    buf++;
			if (fbuf[0] != '\0' && *buf != '\0' )
			{
			    if (*(buf+1) != '\0')
                    return (0);
				return (1);
			}
			return (0);// можно сделать тернарник с нижнем условием
		}*/




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