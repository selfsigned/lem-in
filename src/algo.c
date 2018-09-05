/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 18:30:33 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/05 18:41:09 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	dijkstra(t_list **rooms, t_list **unvisited, t_room *start)
{
	t_list	*links;
	t_list	*target;
	t_room	*l;
	t_room	*t;

	start->ai.distance = 0;
	links = *unvisited;
	while (links)
	{
		l = start->links->content;

		target = algo_get_queue(unvisited, l->name);
		if (target)
		{
			t = target->content;
			t->ai.distance = 1;
			t->ai.previous = start;
			algo_del_visited(&links, l->name);
		}
		links = links->next;
	}
}
