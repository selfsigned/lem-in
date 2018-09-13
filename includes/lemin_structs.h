/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 22:19:26 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/13 19:01:43 by xperrin          ###   ########.fr       */
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

/*
** quiet:    repeat file or stfu?
** in_links: input after rooms parser
*/

typedef struct	s_info
{
	int			quiet;
	int			debug;
	int			ants;
	t_list		*start;
	t_list		*end;
	t_list		*in_links;
}				t_info;

/*
** x, y:	 literally useless, room cords
** distance: dijkstra algo distance (INF if unvisited)
** ant:      is an ant present and what's it's number?
** links:    adjacency list
*/

typedef struct	s_room
{
	char		*name;
	int			x;
	int			y;
	int			distance;
	int			ant;
	t_posflag	flag;
	t_list		*links;

}				t_room;

#endif
