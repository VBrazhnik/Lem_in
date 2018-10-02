/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_io_links.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:03:59 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 17:04:00 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	count_io_links(t_lem_in *lem_in)
{
	t_link *current;

	current = lem_in->links;
	while (current)
	{
		current->start->output_links++;
		current->end->input_links++;
		current = current->next;
	}
}
