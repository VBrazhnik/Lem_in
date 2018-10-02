/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:07:26 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 17:07:27 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "get_next_line.h"
#include "error_message.h"

static t_line	*create_line(char *content)
{
	t_line *line;

	while (!(line = (t_line *)ft_memalloc(sizeof(t_line))))
		terminate(ERR_LINE_INIT);
	line->content = content;
	line->next = NULL;
	return (line);
}

static void		add_line(t_line **lines, t_line *line)
{
	t_line *current;

	if (lines && *lines)
	{
		current = *lines;
		while (current->next)
			current = current->next;
		current->next = line;
	}
	else if (lines)
		*lines = line;
}

t_line			*read_next_line(t_line **lines)
{
	t_line	*line;
	char	*content;
	ssize_t	size;

	line = NULL;
	if ((size = get_next_line(0, &content)) > 0)
		add_line(lines, (line = create_line(content)));
	if (size == -1)
		terminate(ERR_READING);
	return (line);
}
