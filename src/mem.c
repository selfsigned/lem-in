/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 17:35:26 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/02 17:55:30 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdlib.h>
#include <unistd.h>

void	del_lst_string(void *str, size_t len)
{
	(void)len;
	free(str);
}

void	del_void(void *nothing, size_t len)
{
	(void)nothing;
	(void)len;
}

void	del_room(void *room, size_t len)
{
	t_room	*r;
	t_list	*tmp;

	r = room;
	(void)len;
	while (r->links)
	{
		tmp = r->links;
		r->links = r->links->next;
		free(tmp->content);
		free(tmp);
	}
	free(r->name);
	free(r);
}
