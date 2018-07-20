/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:46:56 by xperrin           #+#    #+#             */
/*   Updated: 2018/07/22 19:32:59 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEMIN_H
# define _LEMIN_H

# include "libft.h"

# define START_S "##start"
# define END_S "##end"

# define ERROR_S "ERROR\n"

typedef struct	s_info
{
	size_t		ants;
	int			error;
	t_list		*start;
	t_list		*end;
}				t_info;

typedef struct	s_room
{
	char		*name;
	int			coord_x;
	int			coord_y;
	t_list		*links;
}				t_room;

typedef struct	s_link
{
	t_list		*link;
}				t_link;

typedef enum	e_posflag
{
	nil,
	start,
	end
}				t_posflag;

int				print_error(void);
int				parse_rooms(t_list *input, t_info *info, t_list **rooms);

#endif
