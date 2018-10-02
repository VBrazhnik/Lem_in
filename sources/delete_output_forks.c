/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_output_forks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:04:34 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 17:04:34 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_bool	path_len(t_lem_in *lem_in, t_link *link, int len)
{
	if (link->end == lem_in->end)
		return (len + 1);
	if (link->end->input_links > 1)
		return (len + 1);
	return (path_len(lem_in, find_link(lem_in, link->end, NULL), len + 1));
}

static void		delete_other_output_links(t_lem_in *lem_in, t_link *link)
{
	t_room	*start;
	t_link	*current;
	t_link	*delete;

	start = link->start;
	current = lem_in->links;
	while (current)
	{
		delete = current;
		current = current->next;
		if (delete->start == start && delete != link)
			delete_link(lem_in, delete);
	}
}

static void		delete_output_fork(t_lem_in *lem_in, t_room *room)
{
	t_link	*current;
	t_link	*link_to_min_path;
	int		min_path_len;
	int		cur_path_len;

	min_path_len = FT_INT_MAX;
	link_to_min_path = NULL;
	current = lem_in->links;
	while (current && room->output_links > 1)
	{
		if (current->start == room)
		{
			if (min_path_len > (cur_path_len = path_len(lem_in, current, 0)))
			{
				min_path_len = cur_path_len;
				link_to_min_path = current;
			}
		}
		current = current->next;
	}
	delete_other_output_links(lem_in, link_to_min_path);
	delete_dead_ends(lem_in);
}

void			delete_output_forks(t_lem_in *lem_in)
{
	int		bfs_level;
	t_room	*current;

	bfs_level = lem_in->bfs_level;
	while (bfs_level > 0)
	{
		current = lem_in->rooms;
		while (current)
		{
			if (current->bfs_level == bfs_level
				&& current->output_links > 1)
				delete_output_fork(lem_in, current);
			current = current->next;
		}
		bfs_level--;
	}
}
