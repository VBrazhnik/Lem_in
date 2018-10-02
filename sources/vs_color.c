/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:39:11 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 18:39:11 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"

SDL_Color	create_color(int red, int green, int blue, int alpha)
{
	SDL_Color	color;

	color.r = (Uint8)red;
	color.g = (Uint8)green;
	color.b = (Uint8)blue;
	color.a = (Uint8)alpha;
	return (color);
}
