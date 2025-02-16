/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owatanab <owatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:10:27 by owatanab          #+#    #+#             */
/*   Updated: 2023/07/25 16:11:34 by owatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*t;

	if (dst == NULL && src == NULL)
		return (NULL);
	s = dst;
	t = (char *)src;
	if (s < t)
	{
		while (len--)
			*s++ = *t++;
	}
	else
	{
		s = s + len - 1;
		t = t + len - 1;
		while (len--)
			*s-- = *t--;
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char *s = NULL;
// 	char *t = NULL;
// 	printf("%s", ft_memmove(s, t, 2));
// }