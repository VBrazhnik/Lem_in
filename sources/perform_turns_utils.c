/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_turns_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 19:52:15 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/10/01 19:52:17 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		calculate_diff(t_lem_in *lem_in, t_path *path)
{
	int		diff;
	t_path	*current;

	diff = 0;
	current = lem_in->paths;
	while (current != path)
	{
		diff += path->length - current->length;
		current = current->next;
	}
	return (diff);
}
