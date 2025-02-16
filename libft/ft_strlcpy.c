/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:20:40 by owatanab          #+#    #+#             */
/*   Updated: 2023/07/24 19:38:13 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i + 1 < size && src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = 0;
	while (src[i] != 0)
		i++;
	return (i);
}
