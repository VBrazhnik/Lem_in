/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:28:34 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 17:28:35 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "error_message.h"
#include <errno.h>

void	lem_in(t_bool verbose)
{
	t_line		*lines;
	t_lem_in	*lem_in;

	lines = NULL;
	lem_in = parse(&lines, false);
	bfs(lem_in);
	if (lem_in->end->bfs_level == -1)
		terminate(ERR_NO_PATH);
	delete_useless_links(lem_in);
	align_links(lem_in);
	count_io_links(lem_in);
	delete_dead_ends(lem_in);
	delete_input_forks(lem_in);
	delete_output_forks(lem_in);
	print_lines(lines);
	ft_putendl(NULL);
	form_paths(lem_in);
	if (verbose)
	{
		print_paths(lem_in);
		ft_putendl(NULL);
	}
	perform_turns(lem_in);
	lines_free(&lines);
	lem_in_free(&lem_in);
}

int		main(int argc, char **argv)
{
	t_bool	verbose;
	t_bool	help;

	errno = 0;
	verbose = false;
	help = false;
	while (argc >= 2
		&& (!ft_strcmp(argv[1], "-v") || !ft_strcmp(argv[1], "-h")))
	{
		if (!ft_strcmp(argv[1], "-v"))
			verbose = true;
		else if (!ft_strcmp(argv[1], "-h"))
			help = true;
		argv++;
		argc--;
	}
	if (argc == 1 && !help)
		lem_in(verbose);
	else if (help)
		ft_putendl(LEM_IN_HELP);
	else
		ft_putendl(LEM_IN_USAGE);
	return (0);
}
