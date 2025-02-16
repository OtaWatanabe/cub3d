/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owatanab <owatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:34:59 by owatanab          #+#    #+#             */
/*   Updated: 2023/07/27 14:54:31 by owatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(int n)
{
	int	c;

	c = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		c++;
		n *= -1;
	}
	while (n / 10)
	{
		c++;
		n /= 10;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*p;
	size_t	c;

	c = count_size(n);
	p = ft_calloc(c + 1, 1);
	if (p == 0)
		return (0);
	if (n == -2147483648)
		ft_memcpy(p, "-2147483648", 12);
	else
	{
		if (n < 0)
		{
			p[0] = '-';
			n *= -1;
		}
		while (n / 10)
		{
			p[--c] = '0' + n % 10;
			n /= 10;
		}
		p[c - 1] = '0' + n;
	}
	return (p);
}
