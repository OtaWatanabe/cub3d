/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owatanab <owatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:41:46 by owatanab          #+#    #+#             */
/*   Updated: 2023/07/13 17:43:04 by owatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	uc;
	unsigned char	*p;

	p = b;
	uc = (unsigned char)c;
	while (len--)
		*p++ = uc;
	return (b);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	unsigned char p[20] = "asdasdad", q[20] = "asd";
// 	printf("%s, %s", memset(p, 'x', 2), memset(q, 'x', 18));
// 	printf("\n%s, %s", ft_memset(p, 'x', 2), ft_memset(q, 'x', 18));
// }