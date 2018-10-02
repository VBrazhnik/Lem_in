/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 16:03:13 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/09/30 16:03:14 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H

# define LEM_IN_H

# include "libft.h"

/*
** Types and structures
*/

typedef struct			s_line
{
	char				*content;
	struct s_line		*next;
}						t_line;

typedef enum
{
	START,
	MIDDLE,
	END
}	t_type;

typedef struct			s_room
{
	char				*name;
	int					x;
	int					y;
	t_type				type;
	int					bfs_level;
	int					input_links;
	int					output_links;
	int					ant_number;
	struct s_room		*next;
}						t_room;

typedef struct			s_link
{
	t_room				*start;
	t_room				*end;
	struct s_link		*next;
	struct s_link		*prev;
}						t_link;

typedef struct			s_path
{
	t_link				*head;
	int					length;
	struct s_path		*next;
}						t_path;

typedef struct			s_location
{
	int					ant_number;
	t_room				*room;
	struct s_location	*next;
}						t_location;

typedef struct			s_turn
{
	t_location			*locations;
	struct s_turn		*next;
}						t_turn;

typedef struct			s_ant
{
	int					index;
	t_room				*start;
	t_room				*end;
	struct s_ant		*next;
}						t_ant;

typedef struct			s_lem_in
{
	int					ants_start;
	int					ants_end;
	int					ant_number;
	t_room				*rooms;
	t_room				*start;
	t_room				*end;
	t_link				*links;
	int					bfs_level;
	t_path				*paths;
	t_location			*locations;
	t_turn				*turns;
	t_ant				*ants;
}						t_lem_in;

typedef struct			s_queue
{
	t_room				*room;
	struct s_queue		*next;
}						t_queue;

/*
** Functions
*/

/*
** Read map
*/

t_line					*read_next_line(t_line **lines);

/*
** Parse
*/

t_lem_in				*parse(t_line **lines, t_bool vs);

void					parse_ants(t_lem_in *lem_in,
							t_line **current,
							t_line **lines);

void					parse_rooms(t_lem_in *lem_in,
							t_line **current,
							t_line **lines);

void					parse_links(t_lem_in *lem_in,
							t_line **current,
							t_line **lines,
							t_bool vs);

t_location				*parse_locations(t_lem_in *lem_in, char *str);

void					parse_turns(t_lem_in *lem_in,
							t_line **current,
							t_line **lines);

/*
** Validate
*/

void					validate_room(t_lem_in *lem_in, t_room *room);

void					validate_link(t_lem_in *lem_in, t_link *link);

/*
** Is
*/

t_bool					is_command(char *str);

t_bool					is_comment(char *str);

t_bool					is_room(char *str);

t_bool					is_location(t_lem_in *lem_in, char *str);

/*
** BFS
*/

void					bfs(t_lem_in *lem_in);

/*
** Align links
*/

void					align_links(t_lem_in *lem_in);

/*
** Count I/O links
*/

void					count_io_links(t_lem_in *lem_in);

/*
** Find room
*/

t_room					*find_room(t_lem_in *lem_in, char *name);

/*
** Find link
*/

t_link					*find_link(t_lem_in	*lem_in,
							t_room *start,
							t_room *end);

/*
** Find ant
*/

t_ant					*find_ant(t_lem_in *lem_in, int index);

/*
** Delete links
*/

void					delete_useless_links(t_lem_in *lem_in);

void					delete_dead_ends(t_lem_in *lem_in);

void					delete_link(t_lem_in *lem_in, t_link *link);

t_link					*remove_link(t_lem_in *lem_in, t_link *link);

/*
** Input forks
*/

void					delete_input_forks(t_lem_in *lem_in);

/*
** Output forks
*/

void					delete_output_forks(t_lem_in *lem_in);

/*
** Paths
*/

void					form_paths(t_lem_in *lem_in);

/*
** Perform turns
*/

t_location				*turn_create_location(int ant_number, t_room *room);

void					turn_add_location(t_lem_in *lem_in,
							t_location *location);

void					perform_turns(t_lem_in *lem_in);

/*
** Perform turns utils
*/

int						calculate_diff(t_lem_in *lem_in, t_path *path);

/*
** Ants
*/

void					init_ants(t_lem_in *lem_in);

/*
** Ants locations
*/

void					ants_set_end_locations(t_lem_in *lem_in, t_turn *turn);

void					ants_update_locations(t_lem_in *lem_in);

void					ants_reset_locations(t_lem_in *lem_in);

/*
** Free
*/

void					lines_free(t_line **lines);

void					lem_in_free(t_lem_in **lem_in);

void					ants_free(t_ant **current);

void					turns_free(t_turn **current);

void					locations_free(t_location **current);

void					paths_free(t_path **current);

void					links_free(t_link **current);

void					rooms_free(t_room **current);

/*
** Utils
*/

void					terminate(char *s);

/*
** Print
*/

void					print_lines(t_line *lines);

void					print_paths(t_lem_in *lem_in);

void					print_locations(t_lem_in *lem_in);

#endif
