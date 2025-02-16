/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owatanab <owatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:55:02 by owatanab          #+#    #+#             */
/*   Updated: 2023/07/13 17:42:56 by owatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*t;
	size_t			i;

	i = 0;
	t = (unsigned char *)s;
	while (i++ < n)
	{
		if ((unsigned char)c == *t)
			return (t);
		t++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char s[20];
// 	strcpy(s, "gsfgsg");
// 	printf("%s\n", s + 9);
// 	printf("%s\n", ft_memchr(s, 'g', 20));
// 	printf("%s", memchr(s, 'g', 20));
// }