/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owatanab <owatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:32:36 by owatanab          #+#    #+#             */
/*   Updated: 2023/07/13 17:47:08 by owatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = 0;
	while (*s)
	{
		if (*s == (char)c)
			p = (char *)s;
		s++;
	}
	if ((char)c == 0)
		return ((char *)s);
	return (p);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char s[] = "qopovu";
// 	printf("%s\n", ft_strrchr(s, 0));
// 	printf("%s", strrchr(s, 0));
// }