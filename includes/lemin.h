/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:46:56 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/06 18:25:33 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEMIN_H
# define _LEMIN_H

# include "libft.h"

# include "lemin_structs.h"

# define START_S "##start"
# define END_S "##end"

# define ERROR_S "ERROR\n"

# define INF INT_MAX

/*
** main.c
*/
int		print_error(void);
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
void	dijkstra(t_list **rooms, t_room *start);
/*
** algo_utils.c
*/
int		algo_init(t_list **rooms, t_info info);
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

#endif
