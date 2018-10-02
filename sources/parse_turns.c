/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_turns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:06:37 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 17:06:39 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "error_message.h"

static t_turn	*create_turn(void)
{
	t_turn	*turn;

	if (!(turn = (t_turn *)ft_memalloc(sizeof(t_turn))))
		terminate(ERR_TURN_INIT);
	turn->locations = NULL;
	turn->next = NULL;
	return (turn);
}

static void		add_turn(t_lem_in *lem_in, t_turn *turn)
{
	t_turn	*current;

	current = lem_in->turns;
	if (current)
	{
		while (current->next)
			current = current->next;
		current->next = turn;
	}
	else
		lem_in->turns = turn;
}

void			parse_turns(t_lem_in *lem_in, t_line **current, t_line **lines)
{
	t_turn	*turn;

	while (*current || ((*current) = read_next_line(lines)))
	{
		turn = create_turn();
		turn->locations = parse_locations(lem_in, (*current)->content);
		add_turn(lem_in, turn);
		(*current) = NULL;
	}
}
