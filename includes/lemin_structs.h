/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 22:19:26 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/12 16:09:36 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEMIN_STRUCTS_H
# define _LEMIN_STRUCTS_H

# include "libft.h"

typedef enum	e_posflag
{
	nil,
	start,
	end
}				t_posflag;

typedef struct	s_info
{
	int			error;
	int			quiet;
	int			debug;
	size_t		ants;
	t_list		*start;
	t_list		*end;
}				t_info;

/*
** distance: dijkstra algo distance (INF if unvisited)
*/

typedef struct	s_room
{
	char		*name;
	int			x;
	int			y;
	int			distance;
	t_posflag	flag;
	t_list		*links;

}				t_room;

#endif
