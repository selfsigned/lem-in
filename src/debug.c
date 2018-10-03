/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:47:54 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/03 14:48:26 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "printf.h"

void	debug_disp_rooms(t_list *rooms)
{
	t_room	*tmp;
	t_room	*tmp_link;
	t_list	*node;

	while (rooms)
	{
		tmp = rooms->content;
		ft_dprintf(2, "name:%.5s distance:%d  flag:%d links:",
			tmp->name, tmp->distance, tmp->flag);
		node = tmp->links;
		while (node)
		{
			tmp_link = node->content;
			ft_dprintf(2, "(n:%s f:%d a:%p) ",
				tmp_link->name, tmp_link->flag, tmp_link);
			node = node->next;
		}
		ft_dprintf(2, "addr:%p\n", rooms->content);
		rooms = rooms->next;
	}
}

void	debug_path(t_list *elem)
{
	if (!elem->next)
	{
		ft_printf("%s\n", ((t_room*)elem->content)->name);
	}
	else
	{
		ft_printf("%s<-", ((t_room*)elem->content)->name);
	}
}
