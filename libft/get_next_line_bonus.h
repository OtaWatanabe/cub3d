/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owatanab <owatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:51:45 by owatanab          #+#    #+#             */
/*   Updated: 2025/02/15 21:43:19 by owatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# define OPEN_MAX 300

char	*get_next_line(int fd);

#endif