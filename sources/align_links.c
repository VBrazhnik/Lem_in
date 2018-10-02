/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:03:32 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 17:03:35 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	swap_rooms(t_room **start, t_room **end)
{
	t_room	*tmp;

	tmp = *start;
	*start = *end;
	*end = tmp;
}

void		align_links(t_lem_in *lem_in)
{
	t_link	*current;

	current = lem_in->links;
	while (current)
	{
		if (current->start->bfs_level > current->end->bfs_level)
			swap_rooms(&current->start, &current->end);
		current = current->next;
	}
}
