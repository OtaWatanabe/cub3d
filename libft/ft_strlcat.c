/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owatanab <owatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:40:14 by owatanab          #+#    #+#             */
/*   Updated: 2023/07/27 13:56:18 by owatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (dest == 0 && size == 0)
		return (ft_strlen(src));
	j = 0;
	i = 0;
	while (dest[i] && i < size)
		i++;
	if (i == size)
		return (size + ft_strlen((char *)src));
	while (src[j] != 0 && i + j + 1 < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
	return (i + ft_strlen((char *)src));
}

// #include <stdio.h>

// int	main(void)
// {
// 	char t[] = "almlc";
// 	printf("%zu", ft_strlcat(NULL, t, 10));
// 	printf("aaaa");
// }