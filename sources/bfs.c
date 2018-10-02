/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:03:43 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 17:03:43 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "error_message.h"
#include <stdlib.h>

static t_queue	*queue_create_elem(t_room *room)
{
	t_queue	*queue;

	if (!(queue = (t_queue *)ft_memalloc(sizeof(t_queue))))
		terminate(ERR_QUEUE_INIT);
	queue->room = room;
	queue->next = NULL;
	return (queue);
}

static t_queue	*queue_get_head(t_queue **queue)
{
	t_queue		*elem;

	elem = NULL;
	if (queue && *queue)
	{
		elem = (*queue);
		(*queue) = (*queue)->next;
	}
	return (elem);
}

static void		queue_add_elem(t_queue **queue, t_queue *elem)
{
	t_queue	*current;

	if (queue && *queue)
	{
		current = (*queue);
		while (current->next)
			current = current->next;
		current->next = elem;
	}
	else if (queue)
		(*queue) = elem;
}

static void		queue_add_linked_elems(t_lem_in *lem_in,
					t_queue **queue, t_room *room)
{
	t_link	*current;

	current = lem_in->links;
	while (current)
	{
		if (current->start == room)
		{
			if (current->end->bfs_level == -1)
			{
				current->end->bfs_level = room->bfs_level + 1;
				queue_add_elem(queue, queue_create_elem(current->end));
			}
		}
		else if (current->end == room)
		{
			if (current->start->bfs_level == -1)
			{
				current->start->bfs_level = room->bfs_level + 1;
				queue_add_elem(queue, queue_create_elem(current->start));
			}
		}
		current = current->next;
	}
}

void			bfs(t_lem_in *lem_in)
{
	t_queue		*queue;
	t_queue		*current;

	queue = NULL;
	lem_in->start->bfs_level = 0;
	queue_add_elem(&queue, queue_create_elem(lem_in->start));
	while (queue != NULL)
	{
		current = queue_get_head(&queue);
		if (current->room != lem_in->end)
		{
			queue_add_linked_elems(lem_in, &queue, current->room);
			lem_in->bfs_level = current->room->bfs_level;
		}
		else
			lem_in->end->bfs_level = FT_INT_MAX;
		free(current);
	}
}
