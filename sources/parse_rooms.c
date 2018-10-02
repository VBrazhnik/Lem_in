/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:06:18 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 17:06:19 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "error_message.h"

static t_type	get_type(char *str)
{
	if (!ft_strcmp(str, "##start"))
		return (START);
	else if (!ft_strcmp(str, "##end"))
		return (END);
	else
		return (MIDDLE);
}

static t_room	*create_room(char *str, t_type type)
{
	char		**strsplit;
	t_room		*room;

	if (!(strsplit = ft_strsplit(str, ' ')))
		terminate(ERR_ROOM_INIT);
	if (!(room = (t_room *)ft_memalloc(sizeof(t_room))))
		terminate(ERR_ROOM_INIT);
	if (!(room->name = ft_strdup(strsplit[0])))
		terminate(ERR_ROOM_INIT);
	room->x = ft_atoi(strsplit[1]);
	room->y = ft_atoi(strsplit[2]);
	room->type = type;
	room->bfs_level = -1;
	room->input_links = 0;
	room->output_links = 0;
	room->ant_number = -1;
	room->next = NULL;
	ft_strsplit_free(&strsplit);
	return (room);
}

static void		add_room(t_lem_in *lem_in, t_room *room)
{
	t_room *current;

	if ((current = lem_in->rooms))
	{
		while (current->next)
			current = current->next;
		current->next = room;
	}
	else
		lem_in->rooms = room;
	if (room->type == START)
		lem_in->start = room;
	else if (room->type == END)
		lem_in->end = room;
}

void			parse_rooms(t_lem_in *lem_in, t_line **current, t_line **lines)
{
	t_type	type;
	t_room	*room;

	type = MIDDLE;
	while ((*current || ((*current) = read_next_line(lines)))
		&& (is_command((*current)->content)
		|| is_comment((*current)->content)
		|| is_room((*current)->content)))
	{
		if (is_command((*current)->content))
			type = get_type((*current)->content);
		else if (is_room((*current)->content))
		{
			add_room(lem_in, (room = create_room((*current)->content, type)));
			validate_room(lem_in, room);
			type = MIDDLE;
		}
		else
			type = MIDDLE;
		if ((type == START && lem_in->start)
			|| (type == END && lem_in->end))
			terminate(ERR_ROOM_PARSING);
		(*current) = NULL;
	}
}
