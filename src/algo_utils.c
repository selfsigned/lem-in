/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 18:31:04 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/05 01:13:50 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		algo_init_struct(t_list **rooms, t_list **unvisited)
{
	t_list	*node;
	t_room	*r;

	node = *rooms;
	*unvisited = ft_lstnew(node->content, sizeof(t_room));
	if (!unvisited)
		return (0);
	while (node)
	{
		r = node->content;
		r->ai.distance = INF;
		r->ai.is_visited = 0;
		if (node != *rooms)
			ft_lstappend(unvisited, ft_lstnew(node->content, sizeof(t_room)));
		node = node->next;
	}
	return (1);
}

int				algo_init(t_list **rooms, t_info info)
{
	t_list *unvisited;

	if (!algo_init_struct(rooms, &unvisited))
		return (0);
	dijkstra(rooms, &unvisited, info.end->content);

	/* memory stuff */
	/* ft_lstdel(&unvisited, del_void); */
	return (1);
}
