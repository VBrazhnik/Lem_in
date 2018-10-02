/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 16:03:22 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 16:03:24 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VS_H

# define VS_H

# include "lem_in.h"
# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL2_gfxPrimitives.h>

# define WIDTH				1920
# define HEIGHT				1080
# define ROOM_WIDTH			100
# define ROOM_HEIGHT		100

# define DESTROY_TEXTURE(X)	if (X) SDL_DestroyTexture(X);

typedef struct		s_vs
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	TTF_Font		*font;
	SDL_Texture		*bg;
	SDL_Rect		*bg_dims;
	SDL_Texture		*lem_in;
	SDL_Texture		*room_start_end;
	SDL_Texture		*room_middle;
	SDL_Texture		*ant;
	SDL_Texture		*press_space;
	SDL_Texture		*reload;
	SDL_Texture		*next;
	t_bool			welcome;
	t_bool			close;
	t_bool			ants_is_moving;
	int				x_shift;
	int				y_shift;
}					t_vs;

/*
** Color
*/

SDL_Color			create_color(int red, int green, int blue, int alpha);

/*
** Rect
*/

SDL_Rect			*create_rect(int x, int y, int w, int h);

/*
** Create
*/

t_vs				*create_vs(void);

SDL_Window			*create_window(t_vs *vs);

SDL_Renderer		*create_renderer(t_vs *vs);

SDL_Texture			*create_texture(t_vs *vs, char *path);

SDL_Texture			*create_title(t_vs *vs, char *str, SDL_Color color);

/*
** Init
*/

void				init_vs(t_vs *vs);

/*
** Shift
*/

void				calculate_shift(t_lem_in *lem_in, t_vs *vs);

/*
** Event
*/

void				check_event(t_vs *vs, t_lem_in *lem_in, t_turn **turn);

/*
** Draw
*/

void				draw_links(t_lem_in *lem_in, t_vs *vs);

void				draw_rooms(t_lem_in *lem_in, t_vs *vs);

void				draw_ants(t_lem_in *lem_in, t_vs *vs, float percent);

void				draw_titles(t_vs *vs, t_turn *turn);

void				draw_welcome(t_vs *vs);

void				draw_main(t_lem_in *lem_in, t_vs *vs, t_turn *turn);

/*
** Clear
*/

void				vs_clear(t_vs **vs);

/*
** Utils
*/

void				vs_terminate(t_vs *vs, const char *s);

#endif
