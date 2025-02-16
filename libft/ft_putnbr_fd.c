/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owatanab <owatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:46:20 by owatanab          #+#    #+#             */
/*   Updated: 2023/07/13 17:46:20 by owatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	i;
	char	c;

	i = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		i = -i;
	}
	if (i > 9)
		ft_putnbr_fd((int)(i / 10), fd);
	c = '0' + i % 10;
	write(fd, &c, 1);
}

// int main()
// {
//     ft_putnbr_fd(-2147483648, 1);
// }