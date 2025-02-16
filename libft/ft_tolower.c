/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owatanab <owatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:03:54 by owatanab          #+#    #+#             */
/*   Updated: 2023/07/13 17:47:13 by owatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 'a' - 'A');
	return (c);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char s = 'A';
// 	char t = '2';
// 	printf("%c%c", tolower(s), ft_tolower(s));
// 	printf("%c%c", tolower(t), ft_tolower(t));
// }