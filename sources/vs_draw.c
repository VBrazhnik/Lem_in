/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:39:53 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 18:39:54 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"

void	draw_links(t_lem_in *lem_in, t_vs *vs)
{
	t_link		*current;

	current = lem_in->links;
	while (current)
	{
		thickLineColor(vs->renderer,
			current->start->x + ROOM_WIDTH / 2 + vs->x_shift,
			current->start->y + ROOM_HEIGHT / 2 + vs->y_shift,
			current->end->x + ROOM_WIDTH / 2 + vs->x_shift,
			current->end->y + ROOM_HEIGHT / 2 + vs->y_shift,
			5,
			0xFFBCBCBC);
		current = current->next;
	}
}

void	draw_rooms(t_lem_in *lem_in, t_vs *vs)
{
	t_room		*current;
	SDL_Rect	dims;

	current = lem_in->rooms;
	dims.w = ROOM_WIDTH;
	dims.h = ROOM_HEIGHT;
	while (current)
	{
		dims.x = current->x + vs->x_shift;
		dims.y = current->y + vs->y_shift;
		if (current->type == MIDDLE)
			SDL_RenderCopy(vs->renderer, vs->room_middle, NULL, &dims);
		else if (current->type == START || current->type == END)
			SDL_RenderCopy(vs->renderer, vs->room_start_end, NULL, &dims);
		current = current->next;
	}
}

void	draw_ants(t_lem_in *lem_in, t_vs *vs, float percent)
{
	t_ant		*current;
	SDL_Rect	dims;

	current = lem_in->ants;
	dims.w = ROOM_WIDTH;
	dims.h = ROOM_HEIGHT;
	while (current)
	{
		if (!current->end)
		{
			dims.x = current->start->x + vs->x_shift;
			dims.y = current->start->y + vs->y_shift;
		}
		else if (vs->ants_is_moving)
		{
			dims.x = current->start->x + vs->x_shift +
				(current->end->x - current->start->x) * percent;
			dims.y = current->start->y + vs->y_shift +
				(current->end->y - current->start->y) * percent;
		}
		SDL_RenderCopy(vs->renderer, vs->ant, NULL, &dims);
		current = current->next;
	}
}

void	draw_titles(t_vs *vs, t_turn *turn)
{
	SDL_Rect	reload_dims;
	SDL_Rect	next_dims;

	SDL_QueryTexture(vs->reload, NULL, NULL, &reload_dims.w, &reload_dims.h);
	reload_dims.x = 40;
	reload_dims.y = 21;
	SDL_QueryTexture(vs->next, NULL, NULL, &next_dims.w, &next_dims.h);
	next_dims.x = 40;
	next_dims.y = 81;
	if (vs->ants_is_moving)
		SDL_SetTextureAlphaMod(vs->reload, 150);
	else
		SDL_SetTextureAlphaMod(vs->reload, 255);
	SDL_RenderCopy(vs->renderer, vs->reload, NULL, &reload_dims);
	if (vs->ants_is_moving || !turn)
		SDL_SetTextureAlphaMod(vs->next, 150);
	else
		SDL_SetTextureAlphaMod(vs->next, 255);
	SDL_RenderCopy(vs->renderer, vs->next, NULL, &next_dims);
}
