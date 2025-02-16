/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owatanab <owatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:20:40 by owatanab          #+#    #+#             */
/*   Updated: 2023/07/13 17:42:45 by owatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if ((size_t)-1 / count < size || ((size_t)-1 / count == size && count
			* size != (size_t)-1))
		return (0);
	p = malloc(count * size);
	if (p)
		ft_bzero(p, count * size);
	return (p);
}

// int	main(void)
// {
// 	char *p;
// 	int i;
// 	i = 0;
// 	p = calloc(429496730, 10);
// 	while (*p++ == 0)
// 		i++;
// 	printf("%d", i);
// 	// q = ft_calloc(429496730, 10);
// }