/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owatanab <owatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:36:17 by owatanab          #+#    #+#             */
/*   Updated: 2023/07/27 14:19:18 by owatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	if (i < start)
		len = 0;
	else if (len > i - (size_t)start)
		len = i - (size_t)start;
	p = malloc(len + 1);
	if (p)
	{
		p[len] = 0;
		while (len--)
			p[len] = s[start + len];
	}
	return (p);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *s = "libft-test-tokyo";
// 	printf("%s", ft_substr(s, 5, 100));
// }