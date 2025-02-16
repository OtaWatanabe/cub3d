/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owatanab <owatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:34:52 by owatanab          #+#    #+#             */
/*   Updated: 2023/07/27 14:18:58 by owatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*f;
	char		*q;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (*set)
	{
		while (ft_strchr(set, *s1) && *s1)
			s1++;
		if (*s1 == '\0')
			return ((char *)ft_calloc(1, 1));
		f = (char *)s1 + ft_strlen(s1) - 1;
		while (ft_strchr(set, *f))
			f--;
	}
	else
		f = s1 + ft_strlen(s1) - 1;
	q = malloc(f - s1 + 2);
	if (q)
		ft_strlcpy(q, s1, f - s1 + 2);
	return (q);
}

// int	main(void)
// {
// 	// char s[] = "aaissssoooopp";
// 	printf("%s\n", ft_strtrim("hello world", "abcdefghijklmnopqrstuvwxy z"));
// }