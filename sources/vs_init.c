/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:40:33 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 18:40:34 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"

void	init_vs(t_vs *vs)
{
	SDL_Color	martini;
	SDL_Color	silver;

	martini = create_color(173, 163, 161, 255);
	silver = create_color(188, 188, 188, 255);
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
		vs_terminate(vs, SDL_GetError());
	vs->window = create_window(vs);
	vs->renderer = create_renderer(vs);
	if (TTF_Init() != 0)
		vs_terminate(vs, SDL_GetError());
	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
		vs_terminate(vs, SDL_GetError());
	if (!(vs->font = TTF_OpenFont("resources/Minercraftory.ttf", 40)))
		vs_terminate(vs, SDL_GetError());
	vs->bg = create_texture(vs, "resources/background.png");
	vs->bg_dims = create_rect(0, 0, WIDTH, WIDTH);
	vs->lem_in = create_texture(vs, "resources/lem-in.png");
	vs->room_start_end = create_texture(vs, "resources/room_start_end.png");
	vs->room_middle = create_texture(vs, "resources/room_middle.png");
	vs->ant = create_texture(vs, "resources/ant-man.png");
	vs->press_space = create_title(vs, "PRESS SPACE", martini);
	vs->reload = create_title(vs, "[R]eload", silver);
	vs->next = create_title(vs, "[N]ext", silver);
}
