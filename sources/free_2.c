/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:05:14 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 17:05:14 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

void	turns_free(t_turn **current)
{
	t_turn	*delete;

	if (current)
		while ((*current))
		{
			delete = (*current);
			(*current) = (*current)->next;
			locations_free(&(delete->locations));
			free(delete);
		}
}

void	locations_free(t_location **current)
{
	t_location	*delete;

	if (current)
		while ((*current))
		{
			delete = (*current);
			(*current) = (*current)->next;
			free(delete);
		}
}

void	paths_free(t_path **current)
{
	t_path	*delete;

	if (current)
		while ((*current))
		{
			delete = (*current);
			(*current) = (*current)->next;
			links_free(&(delete->head));
			free(delete);
		}
}

void	links_free(t_link **current)
{
	t_link	*delete;

	if (current)
		while ((*current))
		{
			delete = (*current);
			(*current) = (*current)->next;
			free(delete);
		}
}

void	rooms_free(t_room **current)
{
	t_room	*delete;

	if (current)
		while ((*current))
		{
			delete = (*current);
			(*current) = (*current)->next;
			free(delete->name);
			free(delete);
		}
}
