/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:06:52 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 17:06:52 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "error_message.h"

static t_path	*create_path(void)
{
	t_path	*path;

	if (!(path = (t_path *)ft_memalloc(sizeof(t_path))))
		terminate(ERR_PATH_INIT);
	path->head = NULL;
	path->length = 0;
	path->next = NULL;
	return (path);
}

static void		path_add_link(t_path *path, t_link *link)
{
	t_link	*previous;
	t_link	*current;

	previous = NULL;
	current = path->head;
	if (current)
	{
		while (current)
		{
			previous = current;
			current = current->next;
		}
		link->prev = previous;
		previous->next = link;
	}
	else
		path->head = link;
	path->length++;
}

static void		add_path(t_lem_in *lem_in, t_path *path)
{
	t_path	*previous;
	t_path	*current;

	previous = NULL;
	current = lem_in->paths;
	if (current)
	{
		while (current && path->length > current->length)
		{
			previous = current;
			current = current->next;
		}
		if (!previous)
			lem_in->paths = path;
		else
			previous->next = path;
		path->next = current;
	}
	else
		lem_in->paths = path;
}

void			form_paths(t_lem_in *lem_in)
{
	t_path	*path;
	t_link	*link;

	while (lem_in->links)
	{
		path = create_path();
		link = find_link(lem_in, lem_in->start, NULL);
		path_add_link(path, remove_link(lem_in, link));
		while (link->end != lem_in->end)
		{
			link = find_link(lem_in, link->end, NULL);
			path_add_link(path, remove_link(lem_in, link));
		}
		add_path(lem_in, path);
	}
}
