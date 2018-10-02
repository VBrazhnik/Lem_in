/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:04:20 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 17:04:20 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

void	delete_link(t_lem_in *lem_in, t_link *link)
{
	t_link	*previous;
	t_link	*current;

	previous = NULL;
	current = lem_in->links;
	while (current && current != link)
	{
		previous = current;
		current = current->next;
	}
	if (!previous && current)
		lem_in->links = current->next;
	else if (current)
		previous->next = current->next;
	if (link->start->output_links > 0)
		link->start->output_links--;
	if (link->end->input_links > 0)
		link->end->input_links--;
	free(link);
}

t_link	*remove_link(t_lem_in *lem_in, t_link *link)
{
	t_link	*previous;
	t_link	*current;

	previous = NULL;
	current = lem_in->links;
	while (current && current != link)
	{
		previous = current;
		current = current->next;
	}
	if (!previous && current)
		lem_in->links = current->next;
	else if (current)
		previous->next = current->next;
	link->next = NULL;
	return (link);
}

void	delete_useless_links(t_lem_in *lem_in)
{
	t_link	*current;
	t_link	*delete;

	current = lem_in->links;
	while (current)
	{
		delete = current;
		current = current->next;
		if (delete->start->bfs_level == -1
			|| delete->end->bfs_level == -1
			|| delete->start->bfs_level == delete->end->bfs_level)
			delete_link(lem_in, delete);
	}
}

void	delete_dead_ends(t_lem_in *lem_in)
{
	t_bool	has_dead_end;
	t_link	*current;
	t_link	*delete;

	has_dead_end = true;
	while (has_dead_end)
	{
		has_dead_end = false;
		current = lem_in->links;
		while (current)
		{
			delete = current;
			current = current->next;
			if ((delete->start != lem_in->start
				&& delete->start->input_links == 0
				&& delete->start->output_links > 0)
				|| (delete->end != lem_in->end
				&& delete->end->input_links > 0
				&& delete->end->output_links == 0))
			{
				delete_link(lem_in, delete);
				has_dead_end = true;
			}
		}
	}
}
