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
//#define BUFFER_SIZE 1


int check_ok(int fd, char **line)
{
    if (!line)
        return (-1);
    else
    {
        *line = malloc(sizeof(char));
        (*line)[0] = '\0';
    }
    if (!line || (read(fd, 0, 0)) < 0 || BUFFER_SIZE < 1)//что-то с fd
        return (-1);
    else
        return (0);
}

int get_next_line(int fd, char **line)
{
    static char fbuf[BUFFER_SIZE + 1];
    static int size;
    static char *buf;

    if (check_ok(fd, line) == -1)
        return (-1);
    while (buf == NULL || *buf != '\n')
    {
        if (buf == NULL || *buf == '\0')
        {
            fbuf[0] = '\0';//возможно можно убрать совсем
            size = read(fd, fbuf, BUFFER_SIZE);
            fbuf[size] = '\0';
            buf = fbuf;
        }
        if (size == 0)            //тернар со след строкой или
            return (0);
        if (size < 0)
            return (-1);
        *line = ft_strjoinn(*line, &buf);
        if (*line == NULL) //seg
            return (-1);
    }
            buf++;
            return (1);
}

