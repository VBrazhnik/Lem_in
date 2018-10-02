/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:05:08 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 17:05:08 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

void	lines_free(t_line **lines)
{
	t_line	*delete;
	t_line	*current;

	current = (*lines);
	while (current)
	{
		delete = current;
		current = current->next;
		free(delete->content);
		free(delete);
	}
	(*lines) = NULL;
}

void	lem_in_free(t_lem_in **lem_in)
{
	if (lem_in && *lem_in)
	{
		ants_free(&((*lem_in)->ants));
		turns_free(&((*lem_in)->turns));
		locations_free(&((*lem_in)->locations));
		paths_free(&((*lem_in)->paths));
		links_free(&((*lem_in)->links));
		rooms_free(&((*lem_in)->rooms));
		free((*lem_in));
		(*lem_in) = NULL;
	}
}

void	ants_free(t_ant **current)
{
	t_ant	*delete;

	if (current)
		while ((*current))
		{
			delete = (*current);
			(*current) = (*current)->next;
			free(delete);
		}
}
