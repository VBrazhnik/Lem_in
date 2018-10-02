/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:07:15 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 17:07:15 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_lines(t_line *lines)
{
	t_line		*current;

	current = lines;
	while (current)
	{
		ft_putendl(current->content);
		current = current->next;
	}
}

void	print_paths(t_lem_in *lem_in)
{
	t_path	*current_path;
	t_link	*current_link;

	current_path = lem_in->paths;
	while (current_path)
	{
		current_link = current_path->head;
		ft_putchar('[');
		ft_putstr(current_link->start->name);
		ft_putchar(']');
		while (current_link)
		{
			ft_putstr(" -> ");
			ft_putchar('[');
			ft_putstr(current_link->end->name);
			ft_putchar(']');
			current_link = current_link->next;
		}
		ft_putendl(NULL);
		current_path = current_path->next;
	}
}

void	print_locations(t_lem_in *lem_in)
{
	t_location	*current;

	current = lem_in->locations;
	while (current)
	{
		if (current != lem_in->locations)
			ft_putchar(' ');
		ft_putchar('L');
		ft_putnbr(current->ant_number);
		ft_putchar('-');
		ft_putstr(current->room->name);
		current = current->next;
	}
	ft_putendl(NULL);
}
