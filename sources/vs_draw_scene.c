/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_draw_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:40:09 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 18:40:09 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"

void	draw_welcome(t_vs *vs)
{
	SDL_Rect	lem_in_dims;
	SDL_Rect	msg_dims;

	lem_in_dims.w = 1200;
	lem_in_dims.h = 1200;
	SDL_QueryTexture(vs->press_space, NULL, NULL, &msg_dims.w, &msg_dims.h);
	msg_dims.x = WIDTH / 2 - msg_dims.w / 2;
	msg_dims.y = HEIGHT - 80;
	while (!vs->close && vs->welcome)
	{
		SDL_RenderClear(vs->renderer);
		SDL_RenderCopy(vs->renderer, vs->bg, NULL, vs->bg_dims);
		if (lem_in_dims.h < 1500)
		{
			lem_in_dims.x = WIDTH / 2 - lem_in_dims.w++ / 2;
			lem_in_dims.y = HEIGHT / 2 - lem_in_dims.h++ / 2;
		}
		else if (vs->bg_dims->y > HEIGHT - WIDTH)
			vs->bg_dims->y--;
		SDL_RenderCopy(vs->renderer, vs->press_space, NULL, &msg_dims);
		SDL_RenderCopy(vs->renderer, vs->lem_in, NULL, &lem_in_dims);
		SDL_RenderPresent(vs->renderer);
		SDL_Delay(1000 / 60);
		check_event(vs, NULL, NULL);
	}
}

void	draw_main(t_lem_in *lem_in, t_vs *vs, t_turn *turn)
{
	double		percentage;

	percentage = 0.1;
	while (!vs->close)
	{
		SDL_RenderClear(vs->renderer);
		SDL_RenderCopy(vs->renderer, vs->bg, NULL, vs->bg_dims);
		draw_links(lem_in, vs);
		draw_rooms(lem_in, vs);
		draw_ants(lem_in, vs, percentage);
		draw_titles(vs, turn);
		SDL_RenderPresent(vs->renderer);
		SDL_Delay(1000 / 60);
		if (vs->ants_is_moving && percentage < 1)
			percentage += 0.01;
		else if (vs->ants_is_moving)
		{
			vs->ants_is_moving = false;
			percentage = 0.01;
			ants_update_locations(lem_in);
		}
		check_event(vs, lem_in, &turn);
	}
}
