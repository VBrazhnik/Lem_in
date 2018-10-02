/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_locations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:06:07 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 17:06:07 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "error_message.h"
#include <stdlib.h>

static t_location	*create_location(t_lem_in *lem_in, char *str)
{
	t_location	*location;
	char		*dash;
	char		*ant_number;
	char		*room_name;

	if (!(location = (t_location *)ft_memalloc(sizeof(t_location))))
		terminate(ERR_LOC_INIT);
	dash = ft_strchr(str, '-');
	if (!(ant_number = ft_strsub(str, 1, dash - str - 1)))
		terminate(ERR_LOC_INIT);
	if (!(room_name = ft_strsub(dash + 1, 0, ft_strlen(dash + 1))))
		terminate(ERR_LOC_INIT);
	location->ant_number = ft_atoi(ant_number);
	location->room = find_room(lem_in, room_name);
	location->next = NULL;
	free(ant_number);
	free(room_name);
	return (location);
}

static void			add_location(t_location **locations, t_location *location)
{
	t_location	*current;

	current = (*locations);
	if (current)
	{
		while (current->next)
			current = current->next;
		current->next = location;
	}
	else
		(*locations) = location;
}

t_location			*parse_locations(t_lem_in *lem_in, char *str)
{
	t_location	*locations;
	size_t		i;
	char		**strsplit;

	i = 0;
	locations = NULL;
	if (!(strsplit = ft_strsplit(str, ' ')))
		terminate(ERR_LOC_PARSING);
	while (strsplit[i])
	{
		if (!is_location(lem_in, strsplit[i]))
			terminate(ERR_LOC_PARSING);
		add_location(&locations, create_location(lem_in, strsplit[i]));
		i++;
	}
	ft_strsplit_free(&strsplit);
	return (locations);
}
