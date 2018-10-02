/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_shift.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:41:04 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 18:41:05 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"
#include "error_message.h"

void	calculate_shift(t_lem_in *lem_in, t_vs *vs)
{
	int		x_min;
	int		x_max;
	int		y_min;
	int		y_max;
	t_room	*current;

	x_min = FT_INT_MAX;
	y_min = FT_INT_MAX;
	x_max = FT_INT_MIN;
	y_max = FT_INT_MIN;
	current = lem_in->rooms;
	while (current)
	{
		x_min = (x_min > current->x) ? current->x : x_min;
		x_max = (x_max < current->x) ? current->x : x_max;
		y_min = (y_min > current->y) ? current->y : y_min;
		y_max = (y_max < current->y) ? current->y : y_max;
		current = current->next;
	}
	vs->x_shift = (WIDTH - (FT_ABS(x_max - x_min) + ROOM_WIDTH)) / 2 - x_min;
	vs->y_shift = (HEIGHT - (FT_ABS(y_max - y_min) + ROOM_HEIGHT)) / 2
		- y_min;
	if ((WIDTH - (FT_ABS(x_max - x_min) + ROOM_WIDTH)) < 0
		|| (HEIGHT - (FT_ABS(y_max - y_min) + ROOM_HEIGHT)) < 0)
		vs_terminate(vs, ERR_BIG_MAP);
}
