/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_input_forks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:04:13 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 17:04:13 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_bool	path_has_output_fork(t_lem_in *lem_in, t_link *link)
{
	if (link->start == lem_in->start)
		return (false);
	if (link->start->output_links > 1)
		return (true);
	return (path_has_output_fork(lem_in,
		find_link(lem_in, NULL, link->start)));
}

static void		delete_other_input_links(t_lem_in *lem_in, t_link *link)
{
	t_room	*end;
	t_link	*current;
	t_link	*delete;

	end = link->end;
	current = lem_in->links;
	while (current)
	{
		delete = current;
		current = current->next;
		if (delete->end == end && delete != link)
			delete_link(lem_in, delete);
	}
}

static void		delete_input_fork(t_lem_in *lem_in, t_room *room)
{
	t_link	*current;
	t_link	*delete;

	current = lem_in->links;
	while (current && room->input_links > 1)
	{
		delete = current;
		current = current->next;
		if (delete->end == room)
		{
			if (!path_has_output_fork(lem_in, delete))
				delete_other_input_links(lem_in, delete);
			else
				delete_link(lem_in, delete);
			delete_dead_ends(lem_in);
		}
	}
}

void			delete_input_forks(t_lem_in *lem_in)
{
	int		bfs_level;
	t_room	*current;

	bfs_level = 1;
	while (bfs_level <= lem_in->bfs_level)
	{
		current = lem_in->rooms;
		while (current)
		{
			if (current->bfs_level == bfs_level
				&& current->input_links > 1)
				delete_input_fork(lem_in, current);
			current = current->next;
		}
		bfs_level++;
	}
}
