/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 18:31:04 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/06 19:41:12 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdlib.h>

#include "printf.h"

static	void	algo_set_distance(t_list *elem)
{
	t_room	*room;

	room = elem->content;
	if (room)
		room->distance = INF;
}

int				algo_init(t_list **rooms, t_info info)
{
	t_room	*s;

	ft_lstiter(*rooms, &algo_set_distance);
	s = info.start->content;
	s->distance = 0;
	dijkstra(rooms, s);
	return (1);
}
