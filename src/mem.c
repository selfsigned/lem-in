/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 17:35:26 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/08 00:21:49 by xperrin          ###   ########.fr       */
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

	(void)len;
	r = room;
	if (r->links)
		ft_lstdel(&r->links, &del_void);
	free(r->name);
	free(r);
}
