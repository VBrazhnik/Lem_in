/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:38:30 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 18:38:31 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"
#include "error_message.h"
#include <errno.h>

int		main(int argc, char **argv)
{
	t_line		*lines;
	t_lem_in	*lem_in;
	t_vs		*vs;

	(void)argv;
	if (argc == 1)
	{
		errno = 0;
		lines = NULL;
		lem_in = parse(&lines, true);
		init_ants(lem_in);
		vs = create_vs();
		calculate_shift(lem_in, vs);
		init_vs(vs);
		draw_welcome(vs);
		draw_main(lem_in, vs, lem_in->turns);
		lines_free(&lines);
		lem_in_free(&lem_in);
		vs_clear(&vs);
	}
	else
		ft_putendl(VS_USAGE);
	return (0);
}
