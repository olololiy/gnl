/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:54:12 by vfurr             #+#    #+#             */
/*   Updated: 2020/12/09 20:31:55 by vfurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
//# include <string.h>
# include <unistd.h>

size_t	ft_strlenn(const char *str);
char	*ft_strjoinn(char *line, char **s2);
int 	get_next_line(int fd, char **line);

#endif
