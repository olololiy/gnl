/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:54:12 by vfurr             #+#    #+#             */
/*   Updated: 2020/12/30 22:01:07 by vfurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlenn(const char *str);
char	*ft_strjoinn(char *line, char **buf, int i, int length2);
int		get_next_line(int fd, char **line);
int		check_ok(int fd, char **line);

#endif
