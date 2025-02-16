/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owatanab <owatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:51:00 by owatanab          #+#    #+#             */
/*   Updated: 2023/11/08 16:35:49 by owatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*concat(char *s1, char *s2, ssize_t l2);
int		check_new_line(char **s, char **line, ssize_t max);
char	*buf_read(int fd, char **rest, char *line);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest[OPEN_MAX + 3];

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX + 2)
		return (NULL);
	line = NULL;
	if ((rest[fd] && check_new_line(&rest[fd], &line, -1) == 0))
		return (line);
	free(rest[fd]);
	rest[fd] = NULL;
	return (buf_read(fd, &rest[fd], line));
}
