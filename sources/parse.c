/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:05:25 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 17:05:26 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "error_message.h"

static t_lem_in	*init_lem_in(void)
{
	t_lem_in *lem_in;

	if (!(lem_in = (t_lem_in *)ft_memalloc(sizeof(t_lem_in))))
		terminate(ERR_LEM_IN_INIT);
	lem_in->ants_start = 0;
	lem_in->ants_end = 0;
	lem_in->ant_number = 0;
	lem_in->rooms = NULL;
	lem_in->start = NULL;
	lem_in->end = NULL;
	lem_in->links = NULL;
	lem_in->bfs_level = 0;
	lem_in->paths = NULL;
	lem_in->locations = NULL;
	lem_in->turns = NULL;
	lem_in->ants = NULL;
	return (lem_in);
}

t_lem_in		*parse(t_line **lines, t_bool vs)
{
	t_lem_in	*lem_in;
	t_line		*current;

	current = NULL;
	lem_in = init_lem_in();
	parse_ants(lem_in, &current, lines);
	parse_rooms(lem_in, &current, lines);
	if (!lem_in->start || !lem_in->end)
		terminate(ERR_START_END_ROOM);
	parse_links(lem_in, &current, lines, vs);
	if (!lem_in->links)
		terminate(ERR_NO_LINKS);
	if (vs)
	{
		current = NULL;
		parse_turns(lem_in, &current, lines);
		if (!lem_in->turns)
			terminate(ERR_NO_TURNS);
	}
	return (lem_in);
}
