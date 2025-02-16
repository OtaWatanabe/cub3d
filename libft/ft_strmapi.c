/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owatanab <owatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:46:59 by owatanab          #+#    #+#             */
/*   Updated: 2023/07/27 14:18:49 by owatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	p = ft_calloc(ft_strlen(s) + 1, 1);
	if (p == 0)
		return (0);
	while (s[i])
	{
		p[i] = f(i, (char)s[i]);
		i++;
	}
	return (p);
}
