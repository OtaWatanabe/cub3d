/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knamba <knamba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:17:36 by knamba            #+#    #+#             */
/*   Updated: 2025/02/16 13:18:57 by knamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	safe_exit_with_error(t_vars *vars, char *msg)
{
	if (vars)
		free_vars(vars);
	if (msg)
		printf("Error\n%s\n", msg);
	exit(1);
}
