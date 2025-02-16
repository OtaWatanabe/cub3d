/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owatanab <owatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:34:09 by owatanab          #+#    #+#             */
/*   Updated: 2023/07/27 14:18:14 by owatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_n(char const *str, char c, size_t *a, char const **s)
{
	int	f;
	int	i;

	f = 1;
	i = 0;
	*a = 0;
	*s = str;
	while (*str)
	{
		if (*str != c && f)
		{
			f = 0;
			i++;
		}
		else if (*str == c && f == 0)
			f = 1;
		str++;
	}
	return (i);
}

static int	check_free(char ***t, int i)
{
	if ((*t)[i - 1])
		return (0);
	while (i-- > 1)
		free((*t)[i - 1]);
	free(*t);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**t;
	size_t		n;
	size_t		i;
	char const	*s1;

	if (s == NULL)
		return (NULL);
	n = get_n(s, c, &i, &s1);
	t = malloc(sizeof(char *) * (n + 1));
	if (t == 0)
		return (0);
	while (i < n)
	{
		while (*s1 == c && *s1++)
			;
		s = s1;
		while (*s1 != c && *s1++)
			;
		t[i++] = ft_substr(s, 0, s1 - s);
		check_free(&t, i);
	}
	t[n] = 0;
	return (t);
}
