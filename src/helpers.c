/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 03:48:44 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/07 22:23:19 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "printf.h"

t_room		*get_room(t_list *rooms, char *name)
{
	t_room	*content;

	while (rooms)
	{
		content = rooms->content;
		if (content)
		{
			if (!ft_strcmp(content->name, name))
				return (content);
		}
		rooms = rooms->next;
	}
	return (NULL);
}

void		debug_disp_rooms(t_list *rooms)
{
	t_room	*tmp;
	t_room	*tmp_link;
	t_list	*node;

	while (rooms)
	{
		tmp = rooms->content;
		ft_dprintf(2, "name:%.5s x:%.02d y:%.02d distance:%d  flag:%d links:",
			tmp->name, tmp->x, tmp->y, tmp->distance, tmp->flag);
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

int				print_error(char *msg, t_info info)
{
	if (info.debug)
		ft_putendl(msg);
	else
		ft_putendl(ERROR_S);
	return (1);
}

