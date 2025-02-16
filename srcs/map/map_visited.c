/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_visited.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knamba <knamba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:29:55 by knamba            #+#    #+#             */
/*   Updated: 2025/02/16 13:30:08 by knamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_visited(t_vars *vars)
{
	int	i;

	if (vars->cub.visited == NULL)
		return ;
	i = 0;
	while (vars->cub.visited[i] != NULL)
	{
		free(vars->cub.visited[i]);
		i++;
	}
	free(vars->cub.visited);
	vars->cub.visited = NULL;
}

void	reset_visited(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->cub.em_height)
	{
		j = 0;
		while (j < vars->cub.em_width)
		{
			vars->cub.visited[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	allocate_visited(t_vars *vars)
{
	int	i;

	i = 0;
	vars->cub.visited = ft_calloc(vars->cub.em_height + 1, sizeof(int *));
	if (vars->cub.visited == NULL)
		safe_exit_with_error(vars, "failed to allocate memory for visited");
	while (i < vars->cub.em_height)
	{
		vars->cub.visited[i] = malloc(vars->cub.em_width * sizeof(int));
		if (vars->cub.visited[i] == NULL)
		{
			while (--i >= 0)
			{
				free(vars->cub.visited[i]);
				vars->cub.visited[i] = NULL;
			}
			free(vars->cub.visited);
			vars->cub.visited = NULL;
			safe_exit_with_error(vars, "failed to allocate memory for visited");
		}
		i++;
	}
	vars->cub.visited[vars->cub.em_height] = NULL;
	reset_visited(vars);
}
