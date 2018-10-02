/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_rect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:40:52 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 18:40:53 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"
#include "error_message.h"

SDL_Rect	*create_rect(int x, int y, int w, int h)
{
	SDL_Rect	*rect;

	if (!(rect = (SDL_Rect *)ft_memalloc(sizeof(SDL_Rect))))
		vs_terminate(NULL, ERR_RECT_INIT);
	rect->x = x;
	rect->y = y;
	rect->w = w;
	rect->h = h;
	return (rect);
}
