/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:39:26 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 18:39:27 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"
#include "error_message.h"

t_vs			*create_vs(void)
{
	t_vs	*vs;

	if (!(vs = (t_vs *)ft_memalloc(sizeof(t_vs))))
		vs_terminate(NULL, ERR_VS_INIT);
	vs->window = NULL;
	vs->renderer = NULL;
	vs->font = NULL;
	vs->bg = NULL;
	vs->bg_dims = NULL;
	vs->lem_in = NULL;
	vs->room_start_end = NULL;
	vs->room_middle = NULL;
	vs->ant = NULL;
	vs->press_space = NULL;
	vs->reload = NULL;
	vs->next = NULL;
	vs->welcome = true;
	vs->close = false;
	vs->ants_is_moving = false;
	vs->x_shift = 0;
	vs->y_shift = 0;
	return (vs);
}

SDL_Window		*create_window(t_vs *vs)
{
	SDL_Window	*window;

	window = SDL_CreateWindow("Lem-in",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WIDTH, HEIGHT, 0);
	if (!window)
		vs_terminate(vs, SDL_GetError());
	return (window);
}

SDL_Renderer	*create_renderer(t_vs *vs)
{
	SDL_Renderer	*renderer;

	renderer = SDL_CreateRenderer(vs->window, -1, SDL_WINDOW_SHOWN);
	if (!renderer)
		vs_terminate(vs, SDL_GetError());
	return (renderer);
}

SDL_Texture		*create_texture(t_vs *vs, char *path)
{
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	surface = IMG_Load(path);
	if (!surface)
		vs_terminate(vs, SDL_GetError());
	texture = SDL_CreateTextureFromSurface(vs->renderer, surface);
	SDL_FreeSurface(surface);
	if (!texture)
		vs_terminate(vs, SDL_GetError());
	return (texture);
}

SDL_Texture		*create_title(t_vs *vs, char *str, SDL_Color color)
{
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	surface = TTF_RenderText_Solid(vs->font, str, color);
	texture = SDL_CreateTextureFromSurface(vs->renderer, surface);
	SDL_FreeSurface(surface);
	return (texture);
}
