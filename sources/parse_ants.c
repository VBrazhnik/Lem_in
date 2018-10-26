/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:05:38 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 17:05:39 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "error_message.h"

void	parse_ants(t_lem_in *lem_in, t_line **current, t_line **lines)
{
	if (*current || ((*current) = read_next_line(lines)))
	{
		if (ft_isint((*current)->content, true))
		{
			lem_in->ants_start = ft_atoi((*current)->content);
			(*current) = NULL;
			if (lem_in->ants_start <= 0)
				terminate(ERR_ANTS_NUM_PARSING);
		}
		else
			terminate(ERR_ANTS_NUM_PARSING);
	}
}
