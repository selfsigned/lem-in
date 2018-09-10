/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:46:56 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/07 22:52:25 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEMIN_H
# define _LEMIN_H

# include "libft.h"

# include "lemin_structs.h"

# define DEBUG_A "--debug"
# define HELP_A "--help"

# define HELP_USAGE "Usage: ./lem-in [OPTION] < [FILE]"
# define HELP_OPT "\n\nOptions:"
# define HELP_DEBUG "\n\t--debug -d\t display debug information"
# define HELP_HELP "\n\t--help -h\t display this help and exit"
# define HELP_BAN "\n\nCopyright (c) 2018 Xavier Perrin (GPL3)"

# define ERROR_S "ERROR"
# define ERROR_ALGO "Error: No path found"
# define ERROR_ANTS "Error: Invalid ant number"
# define ERROR_INPUT "Error: Invalid input"
# define ERROR_ROOMS "Error: Can't parse rooms"
# define ERROR_LINKS "Error: Can't parse links"
/*
** Parsing
*/
# define START_S "##start"
# define END_S "##end"
/*
** Algorithm
*/
# define INF INT_MAX

/*
** input.c
*/
size_t	parse_ant_number(void);
int		read_input(t_list **list);
/*
** parse_*.c
*/
int		parse_rooms(t_list *input, t_info *info, t_list **rooms);
int		parse_links(t_list *input, t_list **rooms);
/*
** algo.c
*/
int		dijkstra(t_list **rooms, t_info *info);
/*
** mem.c
*/
void	del_lst_string(void	*str, size_t len);
void	del_void(void *nothing, size_t len);
void	del_room(void *room, size_t len);
/*
** helpers.c
*/
t_room	*get_room(t_list *rooms, char *name);
void	debug_disp_rooms(t_list *rooms);
int		print_error(char *msg, t_info info);

#endif
