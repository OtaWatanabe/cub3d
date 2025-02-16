/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owatanab <owatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:34:45 by owatanab          #+#    #+#             */
/*   Updated: 2023/07/25 16:37:19 by owatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (needle[j] == 0)
		return ((char *)haystack);
	while (i + j < len && haystack[i])
	{
		if (needle[j] == haystack[i + j])
			j++;
		else
		{
			j = 0;
			i++;
		}
		if (needle[j] == 0)
			return ((char *)haystack + i);
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char s[] = "aoijijijekjb";
// 	printf("%s\n", ft_strnstr(s, "", 0));
// 	printf("%s", strnstr(s, "", 0));
// }