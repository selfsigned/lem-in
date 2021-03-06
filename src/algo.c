/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 18:30:33 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/12 17:05:13 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		algo_set_distance(t_list *elem)
{
	t_room		*room;

	room = elem->content;
	if (room)
	{
		room->distance = INF;
		room->ant = 0;
	}
}

static void		assign_dist(t_room *start)
{
	t_list		*node;
	t_room		*c;
	int			distance;

	node = start->links;
	distance = start->distance + 1;
	while (node)
	{
		c = node->content;
		if (c->distance > distance)
		{
			c->distance = distance;
			assign_dist(c);
		}
		node = node->next;
	}
}

int				dijkstra(t_list **rooms, t_info *info)
{
	t_room		*s;

	ft_lstiter(*rooms, &algo_set_distance);
	s = info->start->content;
	s->distance = 0;
	assign_dist(info->start->content);
	(info->debug) ? debug_disp_rooms(*rooms) : (void)42;
	if (!info->end || ((t_room*)info->end->content)->distance == INF)
		return (0);
	return (1);
}
