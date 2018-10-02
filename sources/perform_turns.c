/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_turns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:07:02 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 17:07:02 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		move_ants_along_path(t_lem_in *lem_in, t_path *path)
{
	t_link	*current;

	current = path->head;
	while (current->next)
		current = current->next;
	while (current)
	{
		if (current->start->ant_number != -1 && current->end == lem_in->end)
		{
			turn_add_location(lem_in,
				turn_create_location(current->start->ant_number, current->end));
			current->start->ant_number = -1;
			lem_in->ants_end++;
		}
		else if (current->start->ant_number != -1)
		{
			turn_add_location(lem_in,
				turn_create_location(current->start->ant_number, current->end));
			current->end->ant_number = current->start->ant_number;
			current->start->ant_number = -1;
		}
		current = current->prev;
	}
}

static void		move_ants_along_paths(t_lem_in *lem_in)
{
	t_path	*current;

	current = lem_in->paths;
	while (current)
	{
		move_ants_along_path(lem_in, current);
		current = current->next;
	}
}

static void		move_ant_from_start(t_lem_in *lem_in, t_path *path)
{
	if (path->head->end == lem_in->end)
	{
		lem_in->ants_start--;
		lem_in->ants_end++;
		turn_add_location(lem_in,
			turn_create_location(++(lem_in->ant_number), path->head->end));
	}
	else
	{
		lem_in->ants_start--;
		path->head->end->ant_number = ++(lem_in->ant_number);
		turn_add_location(lem_in,
			turn_create_location(path->head->end->ant_number, path->head->end));
	}
}

static void		move_ants_from_start(t_lem_in *lem_in)
{
	t_path	*current;

	current = lem_in->paths;
	while (current && lem_in->ants_start)
	{
		if (lem_in->ants_start > calculate_diff(lem_in, current))
			move_ant_from_start(lem_in, current);
		current = current->next;
	}
}

void			perform_turns(t_lem_in *lem_in)
{
	while (lem_in->ants_start || lem_in->ant_number != lem_in->ants_end)
	{
		move_ants_along_paths(lem_in);
		move_ants_from_start(lem_in);
		print_locations(lem_in);
		locations_free(&(lem_in->locations));
		lem_in->locations = NULL;
	}
}
