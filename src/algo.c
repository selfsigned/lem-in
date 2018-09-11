/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 18:30:33 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/11 17:45:08 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static	void	algo_set_distance(t_list *elem)
{
	t_room	*room;

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

static int		find_path(t_list **dst, t_info info)
{
	t_room *room;
	t_list *links;
	t_list *tmp;
	t_room *r;
	int		mindist;

	room = info.end->content;
	while (room->flag != start)
	{
		ft_putendl(room->name);
		mindist = INF;
		links = room->links;
		while (links)
		{
			r = links->content;
			if (r != room && r->distance < mindist)
			{
				tmp = links;
				mindist = r->distance;
			}
			links = links->next;
		}
		if (tmp)
			room = tmp->content;
		else
			return (0);
	}
	return (1);
}

int				dijkstra(t_list **rooms, t_info *info)
{
	t_room	*s;

	t_list	*path;

	ft_lstiter(*rooms, &algo_set_distance);
	s = info->start->content;
	s->distance = 0;
	assign_dist(info->start->content);
	if (!info->end || ((t_room*)info->end->content)->distance == INF)
		return (0);
	find_path(&path, *info);
	return (1);
}
