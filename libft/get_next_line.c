/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:17:50 by otawatanabe       #+#    #+#             */
/*   Updated: 2023/11/06 06:39:28 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*concat(char *s1, char *s2, ssize_t l2);
int		check_new_line(char **s, char **line, ssize_t max);
char	*buf_read(int fd, char **rest, char *line);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if ((rest && check_new_line(&rest, &line, -1) == 0))
		return (line);
	free(rest);
	rest = NULL;
	return (buf_read(fd, &rest, line));
}
