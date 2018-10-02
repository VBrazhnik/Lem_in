/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:08:50 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 18:08:50 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "error_message.h"

static t_ant	*create_ant(t_lem_in *lem_in, int index)
{
	t_ant	*ant;

	if (!(ant = (t_ant *)ft_memalloc(sizeof(t_ant))))
		terminate(ERR_ANT_INIT);
	ant->index = index;
	ant->start = lem_in->start;
	ant->end = NULL;
	ant->next = NULL;
	return (ant);
}

static void		add_ant(t_lem_in *lem_in, t_ant *ant)
{
	t_ant	*current;

	current = lem_in->ants;
	if (current)
	{
		while (current->next)
			current = current->next;
		current->next = ant;
	}
	else
		lem_in->ants = ant;
}

void			init_ants(t_lem_in *lem_in)
{
	int		i;

	i = lem_in->ants_start;
	while (i > 0)
		add_ant(lem_in, create_ant(lem_in, i--));
}
