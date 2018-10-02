/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:08:32 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 17:08:32 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "error_message.h"

void		validate_room(t_lem_in *lem_in, t_room *room)
{
	t_room	*i;

	i = lem_in->rooms;
	while (i)
	{
		if (room != i && !ft_strcmp(room->name, i->name))
			terminate(ERR_ROOM_NAME_DUP);
		if (room != i && room->x == i->x && room->y == i->y)
			terminate(ERR_ROOM_COORDS_DUP);
		i = i->next;
	}
}

void		validate_link(t_lem_in *lem_in, t_link *link)
{
	t_link	*i;

	i = lem_in->links;
	while (i)
	{
		if (link != i &&
			((!ft_strcmp(link->start->name, i->start->name)
			&& !ft_strcmp(link->end->name, i->end->name)) ||
			(!ft_strcmp(link->start->name, i->end->name)
			&& !ft_strcmp(link->end->name, i->start->name))))
			terminate(ERR_LINK_DUP);
		i = i->next;
	}
}
