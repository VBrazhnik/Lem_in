/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_locations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:10:25 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 18:10:25 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ants_set_end_locations(t_lem_in *lem_in, t_turn *turn)
{
	t_location	*current;
	t_ant		*ant;

	current = turn->locations;
	while (current)
	{
		ant = find_ant(lem_in, current->ant_number);
		ant->end = current->room;
		current = current->next;
	}
}

void	ants_update_locations(t_lem_in *lem_in)
{
	t_ant	*current;

	current = lem_in->ants;
	while (current)
	{
		if (current->end)
		{
			current->start = current->end;
			current->end = NULL;
		}
		current = current->next;
	}
}

void	ants_reset_locations(t_lem_in *lem_in)
{
	t_ant	*current;

	current = lem_in->ants;
	while (current)
	{
		current->start = lem_in->start;
		current = current->next;
	}
}
