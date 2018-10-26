/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 20:16:46 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/10/02 20:16:47 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "error_message.h"
#include <stdlib.h>

t_bool			is_command(char *str)
{
	if (str)
	{
		if (ft_strlen(str) >= 2
			&& !ft_strncmp(str, "##", 2))
			return (true);
	}
	return (false);
}

t_bool			is_comment(char *str)
{
	if (str)
	{
		if (ft_strlen(str)
			&& !is_command(str)
			&& !ft_strncmp(str, "#", 1))
			return (true);
	}
	return (false);
}

static t_bool	is_room_name(char *str)
{
	if (str && ft_strlen(str))
	{
		if (str[0] != 'L' && str[0] != '#')
			return (true);
	}
	return (false);
}

t_bool			is_room(char *str)
{
	t_bool	result;
	char	**strsplit;

	result = false;
	if (!(strsplit = ft_strsplit(str, ' ')))
		terminate(ERR_ROOM_PARSING);
	if (ft_strsplit_len(strsplit) == 3)
	{
		if (is_room_name(strsplit[0])
			&& ft_isint(strsplit[1], true)
			&& ft_isint(strsplit[2], true))
			result = true;
	}
	ft_strsplit_free(&strsplit);
	return (result);
}

t_bool			is_location(t_lem_in *lem_in, char *str)
{
	t_bool	result;
	char	*dash;
	char	*ant_number;
	char	*room_name;

	result = false;
	if (ft_strlen(str) < 1 && str[0] != 'L')
		terminate(ERR_LOC_PARSING);
	if (!(dash = ft_strchr(str, '-')))
		terminate(ERR_LOC_PARSING);
	if (!(ant_number = ft_strsub(str, 1, dash - str - 1)))
		terminate(ERR_LOC_PARSING);
	if (!(room_name = ft_strsub(dash + 1, 0, ft_strlen(dash + 1))))
		terminate(ERR_LOC_PARSING);
	if (find_room(lem_in, room_name)
		&& ft_isint(ant_number, true)
		&& ft_atoi(ant_number) >= 1
		&& ft_atoi(ant_number) <= lem_in->ants_start)
		result = true;
	free(ant_number);
	free(room_name);
	return (result);
}
