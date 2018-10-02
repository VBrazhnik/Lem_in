/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:05:47 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 17:05:47 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "error_message.h"
#include <stdlib.h>

static void		add_link(t_lem_in *lem_in, t_link *link)
{
	t_link	*current;

	current = lem_in->links;
	if (current)
	{
		while (current->next)
			current = current->next;
		current->next = link;
	}
	else
		lem_in->links = link;
}

static t_link	*init_link(t_room *start, t_room *end)
{
	t_link	*link;

	if (!(link = (t_link *)ft_memalloc(sizeof(t_link))))
		terminate(ERR_LINK_INIT);
	link->start = start;
	link->end = end;
	link->next = NULL;
	link->prev = NULL;
	return (link);
}

static t_link	*create_link(t_lem_in *lem_in, char *str)
{
	char	*dash;
	char	*start_name;
	char	*end_name;
	t_room	*start_room;
	t_room	*end_room;

	dash = str;
	while ((dash = ft_strchr(dash + 1, '-')))
	{
		if (!(start_name = ft_strsub(str, 0, dash - str)))
			terminate(ERR_LINK_INIT);
		if (!(end_name = ft_strsub(dash + 1, 0, ft_strlen(dash + 1))))
			terminate(ERR_LINK_INIT);
		start_room = find_room(lem_in, start_name);
		end_room = find_room(lem_in, end_name);
		free(start_name);
		free(end_name);
		if (start_room && end_room)
			return (init_link(start_room, end_room));
	}
	return (NULL);
}

void			parse_links(t_lem_in *lem_in,
					t_line **current,
					t_line **lines,
					t_bool vs)
{
	t_link	*link;

	while ((*current) || ((*current) = read_next_line(lines)))
	{
		if (!is_comment((*current)->content)
			&& !is_command((*current)->content))
		{
			if (vs && !ft_strlen((*current)->content))
				break ;
			if (!(link = create_link(lem_in, (*current)->content)))
				terminate(ERR_LINK_PARSING);
			add_link(lem_in, link);
			validate_link(lem_in, link);
		}
		(*current) = NULL;
	}
}
