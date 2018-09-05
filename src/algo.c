/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 18:30:33 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/05 23:31:46 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Fall back to checking links
*/
static	t_room		*find_min_node(t_list **unvisited, t_room *src)
{
	t_list	*list;
	t_list	*node;
	t_room	*r;

	list = *unvisited;
	while (list)
	{
		r = list->content;
		node = r->links;
		while (node)
		{
			r = node->content;
			if (r && !r->is_visited && r->name == src->name)
			{
				ft_putendl("BAZINGA");
				r->is_visited = 1;
				r->previous = node;
				return (list->content);
			}
			node = node->next;
		}
		list = list->next;
	}
	return (NULL);
}

void			dijkstra(t_list **rooms, t_list **unvisited, t_room *start)
{
	t_list	*links;
	t_list	*target;
	t_room	*l;
	t_room	*t;

	start->distance = 0;
	links = *unvisited;
	while (links)
	{
		l = find_min_node(unvisited, start);
		/* l = start->links->content; */

		target = algo_get_queue(unvisited, l->name);
		if (target)
		{
			t = target->content;
			t->is_visited = 1;
			t->distance = 1;
			t->previous = start;
			algo_del_visited(&links, l->name);
		}
		break;
		/* links = links->next; */
	}
}
