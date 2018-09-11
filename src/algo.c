/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 18:30:33 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/11 18:16:24 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		algo_set_distance(t_list *elem)
{
	t_room		*room;

	room = elem->content;
	if (room)
		room->distance = INF;
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

static t_list	*path_next(t_list *links, t_room *room)
{
	int			min_dist;
	t_list		*tmp;
	t_room		*r;

	min_dist = INF;
	while (links)
	{
		r = links->content;
		if (r != room && r->distance < min_dist)
		{
			tmp = links;
			min_dist = r->distance;
		}
		links = links->next;
	}
	return (tmp);
}

static int		path_find(t_list **dst, t_info info)
{
	t_room		*room;
	t_list		*tmp;

	room = info.end->content;
	while (room->flag != start)
	{
		ft_putendl(room->name); /* debug */
		tmp = path_next(room->links, room);
		if (tmp)
			room = tmp->content;
		else
			return (0);
	}
	return (1);
}

int				dijkstra(t_list **rooms, t_info *info)
{
	t_room		*s;
	t_list		*path;

	ft_lstiter(*rooms, &algo_set_distance);
	s = info->start->content;
	s->distance = 0;
	assign_dist(info->start->content);
	if (!info->end || ((t_room*)info->end->content)->distance == INF)
		return (0);
	if (!path_find(&path, *info))
		return (0);
	return (1);
}
