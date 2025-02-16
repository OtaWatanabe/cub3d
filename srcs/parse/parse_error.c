/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knamba <knamba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:35:22 by knamba            #+#    #+#             */
/*   Updated: 2025/02/16 13:35:30 by knamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parse_error(char *msg, t_vars *vars, int fd, char *line)
{
	if (fd != -1)
		close(fd);
	if (line)
		free(line);
	if (msg)
		printf("Error\n%s\n", msg);
	if (vars)
		free_vars(vars);
	exit(1);
}
