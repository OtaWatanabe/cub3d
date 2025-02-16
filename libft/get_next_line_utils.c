/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owatanab <owatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:48:11 by otawatanabe       #+#    #+#             */
/*   Updated: 2023/11/08 16:24:51 by owatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*concat(char *s1, char *s2, ssize_t len2)
{
	char	*ret;
	ssize_t	len1;

	len1 = 0;
	while ((s1 && s1[len1]))
		len1++;
	ret = malloc(len1 + len2 + 1);
	if (ret == NULL)
	{
		free(s1);
		return (NULL);
	}
	ret[len1 + len2] = '\0';
	while (len2--)
		ret[len1 + len2] = s2[len2];
	while (++len2 < len1)
		ret[len2] = s1[len2];
	free(s1);
	return (ret);
}

int	check_new_line(char **s, char **line, ssize_t max)
{
	ssize_t	size;
	ssize_t	i;

	size = 0;
	if (max != -1)
		(*s)[max] = '\0';
	while ((*s)[size] && (!size || (*s)[size - 1] != '\n'))
		size++;
	*line = concat(*line, *s, size);
	if (*line == NULL || (!(*s)[size] && (*s)[size - 1] == '\n'))
	{
		free(*s);
		*s = NULL;
		return (0);
	}
	if ((*s)[size - 1] != '\n')
		return (1);
	i = 0;
	while ((*s)[size + i++])
		(*s)[i - 1] = (*s)[size + i - 1];
	(*s)[i - 1] = '\0';
	return (0);
}

char	*buf_read(int fd, char **rest, char *line)
{
	ssize_t	num_read;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
	{
		free(line);
		return (NULL);
	}
	num_read = read(fd, buf, BUFFER_SIZE);
	while (num_read > 0 && check_new_line(&buf, &line, num_read))
		num_read = read(fd, buf, BUFFER_SIZE);
	if (num_read <= 0 || line == NULL)
	{
		free(buf);
		if (num_read == 0)
			return (line);
		free(line);
		return (NULL);
	}
	*rest = buf;
	return (line);
}
