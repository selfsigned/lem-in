/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 18:30:33 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/06 19:43:28 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/* static	t_room		*find_min_node(t_list **unvisited, t_room *src); */

void				dijkstra(t_list **rooms, t_room *start)
{
	t_list		*node;
	t_room		*c;

	node = start->links;
	while (node)
	{
		c = node->content;
		c->distance = start->distance + 1;
		ft_putendl(c->name); /* DEBUG */
		node = node->next;
	}
}
