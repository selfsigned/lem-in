/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:46:56 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/02 18:44:41 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEMIN_H
# define _LEMIN_H

# include "libft.h"

# define START_S "##start"
# define END_S "##end"

# define ERROR_S "ERROR\n"

typedef enum	e_posflag
{
	nil,
	start,
	end
}				t_posflag;

typedef struct	s_info
{
	size_t		ants;
	int			error;
	t_list		*start;
	t_list		*end;
}				t_info;

typedef struct	s_algo
{
	int			distance;
	int			is_visited;
}				t_algo;

typedef struct	s_room
{
	char		*name;
	int			x;
	int			y;
	t_posflag	flag;
	t_algo		ai;
	t_list		*links;
}				t_room;

typedef struct	s_link
{
	t_list		*link;
}				t_link;

/*
** main.c
*/
int				print_error(void);
/*
** input.c
*/
size_t			parse_ant_number(void);
int				read_input(t_list **list);
/*
** parse_*.c
*/
int				parse_rooms(t_list *input, t_info *info, t_list **rooms);
int				parse_links(t_list *input, t_list **rooms);
/*
** algo_utils.c
*/
int				algo_init(t_list **rooms);
/*
** mem.c
*/
void			del_lst_string(void	*str, size_t len);
void			del_void(void *nothing, size_t len);
void			del_room(void *room, size_t len);
/*
** helpers.c
*/
t_room			*get_room(t_list *rooms, char *name);

#endif
