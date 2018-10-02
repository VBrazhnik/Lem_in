/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:38:55 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 18:38:55 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"
#include <stdlib.h>

void	vs_clear(t_vs **vs)
{
	if (vs && *vs)
	{
		DESTROY_TEXTURE((*vs)->next);
		DESTROY_TEXTURE((*vs)->reload);
		DESTROY_TEXTURE((*vs)->press_space);
		DESTROY_TEXTURE((*vs)->ant);
		DESTROY_TEXTURE((*vs)->room_middle);
		DESTROY_TEXTURE((*vs)->room_start_end);
		DESTROY_TEXTURE((*vs)->lem_in);
		free((*vs)->bg_dims);
		DESTROY_TEXTURE((*vs)->bg);
		TTF_CloseFont((*vs)->font);
		if ((*vs)->renderer)
			SDL_DestroyRenderer((*vs)->renderer);
		if ((*vs)->window)
			SDL_DestroyWindow((*vs)->window);
		TTF_Quit();
		IMG_Quit();
		SDL_Quit();
		free((*vs));
		(*vs) = NULL;
	}
}
