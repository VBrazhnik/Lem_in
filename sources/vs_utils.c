/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:39:03 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 18:39:03 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void	vs_terminate(t_vs *vs, const char *s)
{
	if (vs)
		vs_clear(&vs);
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}
