/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 18:32:32 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/11 18:37:48 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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

int				path_create(t_list **dst, t_info info)
{
	t_room		*room;
	t_list		*tmp;

	room = info.end->content;
	while (room->flag != start)
	{
		ft_putendl(room->name);
		tmp = path_next(room->links, room);
		if (tmp)
			room = tmp->content;
		else
			return (0);
	}
	return (1);
}
