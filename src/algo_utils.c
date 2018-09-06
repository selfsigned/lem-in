/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 18:31:04 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/06 15:11:15 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdlib.h>

#include "printf.h"

t_list			*algo_get_queue(t_list **unvisited, char *name)
{
	t_list	*node;
	t_room	*r;

	node = *unvisited;
	while (node)
	{
		r = node->content;
		if (name == r->name)
			return (node);
		node = node->next;
	}
	return (NULL);
}

int				algo_del_visited(t_list **unvisited, char *name)
{
	t_list	*target;
	t_list	*node;
	t_list	*prev;

	node = *unvisited;
	prev = NULL;
	target = algo_get_queue(unvisited, name);
	while (node != target && node->next != NULL)
	{
		prev = node;
		node = node->next;
	}
	if (node->content == target->content)
	{
		if (prev)
			prev->next = node->next;
		else
			*unvisited = node->next;
		ft_printf("Free'd room %s in unvisited set\n", name); /* DEBUG */
		free(node);
		return (1);
	}
	return (0);
}

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
		r->distance = INF;
		r->is_visited = 0;
		r->previous = NULL;
		if (node != *rooms)
			ft_lstappend(unvisited, ft_lstnew(node->content, sizeof(t_room)));
		node = node->next;
	}
	return (1);
}

int				algo_init(t_list **rooms, t_info info)
{
	t_list *unvisited;

	/* if (!algo_init_struct(rooms, &unvisited)) */
	/* 	return (0); */
	/* dijkstra(rooms, &unvisited, info.start->content); */

	/* memory stuff */
	/* ft_lstdel(&unvisited, del_void); */
	return (1);
}
