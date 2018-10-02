/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 16:03:02 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 16:03:03 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGE_H

# define ERROR_MESSAGE_H

/*
** Lem-in message
*/

# define LEM_IN_USAGE			"Usage: ./lem-in < MAP_FILE"
# define LEM_IN_HELP			"-v\tverbose\n-h\thelp"

/*
** Read map
*/

# define ERR_READING			"ERROR: Reading error"
# define ERR_LINE_INIT			"ERROR: Can\'t initialize line"

/*
** Parse
*/

# define ERR_LEM_IN_INIT		"ERROR: Can\'t initialize Lem-in"

# define ERR_ANTS_NUM_PARSING	"ERROR: Number of ants is incorrent"

# define ERR_ROOM_INIT			"ERROR: Can\'t initialize room"
# define ERR_ROOM_PARSING		"ERROR: Can\'t parse room"
# define ERR_ROOM_NAME_DUP		"ERROR: Input has room name duplicate"
# define ERR_ROOM_COORDS_DUP	"ERROR: Input has room coordinates duplicate"
# define ERR_START_END_ROOM		"ERROR: Input has no start or end room"

# define ERR_LINK_INIT			"ERROR: Can\'t initialize link"
# define ERR_LINK_PARSING		"ERROR: Can\'t parse link"
# define ERR_LINK_DUP			"ERROR: Input has link duplicate"
# define ERR_NO_LINKS			"ERROR: Input has no links"

# define ERR_LOC_INIT			"ERROR: Can\'t initialize location"
# define ERR_LOC_PARSING		"ERROR: Location parsing error"

# define ERR_TURN_INIT			"ERROR: Can\'t initialize turn"
# define ERR_NO_TURNS			"ERROR: Input has no turns"

/*
** Lem-in
*/

# define ERR_QUEUE_INIT			"ERROR: Can\'t initialize queue"

# define ERR_PATH_INIT			"ERROR: Can\'t initialize path"
# define ERR_NO_PATH			"ERROR: Input has no path from start to end"

/*
** Visualizer message
*/

# define VS_USAGE				"Usage: ./lem-in < MAP_FILE | ./vs"

/*
** Visualizer
*/

# define ERR_BIG_MAP			"ERROR: Too big map"

# define ERR_ANT_INIT			"ERROR: Can\'t initialize ant"

# define ERR_VS_INIT			"ERROR: Can\'t initialize visualizer"

# define ERR_RECT_INIT			"ERROR: Can\'t initialize rect"

#endif
