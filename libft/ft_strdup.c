/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owatanab <owatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:27:33 by owatanab          #+#    #+#             */
/*   Updated: 2023/07/27 13:57:15 by owatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	i;

	i = ft_strlen(s1);
	p = malloc(i + 1);
	if (p)
	{
		while (i--)
			p[i] = s1[i];
		p[ft_strlen(s1)] = 0;
	}
	return (p);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s", ft_strdup("hello"));
// }