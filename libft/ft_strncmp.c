/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owatanab <owatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:52:03 by owatanab          #+#    #+#             */
/*   Updated: 2023/07/13 17:47:03 by owatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	i = 0;
	while ((t1[i] != 0 || t2[i] != 0) && i < n)
	{
		if (t1[i] != t2[i])
			return ((int)t1[i] - (int)t2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	printf("%d", strncmp("asd", NULL, 3));
// 	// printf("%d", ft_strncmp("asd", NULL, 3));
// }