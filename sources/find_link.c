/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:04:49 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 17:04:49 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link	*find_link(t_lem_in *lem_in, t_room *start, t_room *end)
{
	t_link	*current;

	current = lem_in->links;
	while (current)
	{
		if (start && current->start == start)
			return (current);
		if (end && current->end == end)
			return (current);
		current = current->next;
	}
	return (NULL);
}
