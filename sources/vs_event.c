/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:40:19 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 18:40:19 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"

void	check_event(t_vs *vs, t_lem_in *lem_in, t_turn **turn)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			vs->close = true;
		if (vs->welcome && event.key.keysym.scancode == SDL_SCANCODE_SPACE)
		{
			vs->welcome = false;
			vs->bg_dims->y = HEIGHT - WIDTH;
		}
		if (!vs->welcome && !vs->ants_is_moving && lem_in && turn && *turn
			&& event.key.keysym.scancode == SDL_SCANCODE_N)
		{
			ants_set_end_locations(lem_in, *turn);
			vs->ants_is_moving = true;
			(*turn) = (*turn)->next;
		}
		if (!vs->welcome && !vs->ants_is_moving && lem_in && turn
			&& event.key.keysym.scancode == SDL_SCANCODE_R)
		{
			ants_reset_locations(lem_in);
			(*turn) = lem_in->turns;
		}
	}
}
