/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owatanab <owatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:47:43 by owatanab          #+#    #+#             */
/*   Updated: 2023/07/13 17:47:16 by owatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char s = 'a';
// 	char t = '2';
// 	printf("%c%c", toupper(s), ft_toupper(s));
// 	printf("%c%c", toupper(t), ft_toupper(t));
// }