/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owatanab <owatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:14:09 by owatanab          #+#    #+#             */
/*   Updated: 2023/07/13 17:42:50 by owatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c < 128)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	printf("%d", isascii(0));
// 	printf("%d", isascii(128));
// 	printf("%d", isascii(127));
// 	printf("%d", ft_isascii(0));
// 	printf("%d", ft_isascii(128));
// 	printf("%d", ft_isascii(127));
// }