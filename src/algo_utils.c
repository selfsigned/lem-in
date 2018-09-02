/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 18:31:04 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/02 18:49:44 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		algo_init_struct(t_list **rooms)
{
	t_list	*node;
	t_room	*r;

	node = *rooms;
	while (node)
	{
		r = node->content;
		r->ai.distance = -1;
		r->ai.is_visited = 0;
		node = node->next;
	}
	return (1);
}

int				algo_init(t_list **rooms)
{
	algo_init_struct(rooms);
	return (1);
}
