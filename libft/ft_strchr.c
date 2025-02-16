/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owatanab <owatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:06:36 by owatanab          #+#    #+#             */
/*   Updated: 2023/07/13 17:46:32 by owatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*a;

	a = (char *)s;
	while (*a)
	{
		if (*a == (char)c)
			return (a);
		a++;
	}
	if ((char)c == 0)
		return (a);
	return (0);
}

// int	main(void)
// {
// 	char	t[10];

// 	strcpy(t, "asolcdv");
// 	printf("%s, %s", ft_strchr(t, 'c' - 256), ft_strchr(t, 'b'));
// 	printf("%s, %s", strchr(t, 'c' - 256), strchr(t, 'b'));
// }
