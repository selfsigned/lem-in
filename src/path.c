/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 18:32:32 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/13 18:47:30 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "printf.h"

static t_list	*path_next(t_list *links, t_room *room)
{
	int			min_dist;
	t_list		*tmp;
	t_room		*r;

	min_dist = INF;
	while (links)
	{
		r = links->content;
		if (r != room && r->distance < min_dist)
		{
			tmp = links;
			min_dist = r->distance;
		}
		links = links->next;
	}
	return (tmp);
}

static int		path_create(t_list **dst, t_info info)
{
	t_room		*room;
	t_list		*tmp;

	room = info.end->content;
	if (!(*dst = ft_lstnewl((void**)&room)))
		return (0);
	while (room->flag != start)
	{
		tmp = path_next(room->links, room);
		if (tmp)
		{
			room = tmp->content;
			if (!(tmp = ft_lstnewl((void**)&room)))
				return (0);
			ft_lstappend(dst, tmp);
		}
		else
			return (0);
	}
	return (1);
}

/*
** path order: end -> to -> start
*/

static int		move_ants(int prev, t_room *r, t_room *p, t_info *info)
{
	if (r->flag == end && p->ant)
	{
		ft_printf((prev) ? " L%d-%s" : "L%d-%s", p->ant, r->name);
		p->ant = 0;
		r->ant++;
	}
	else if (p->flag == start && info->ants && !r->ant)
	{
		r->ant = p->ant;
		p->ant++;
		info->ants--;
		ft_printf((prev) ? " L%d-%s" : "L%d-%s", r->ant, r->name);
	}
	else if (!r->ant && p->ant)
	{
		r->ant = p->ant;
		p->ant = 0;
		ft_printf((prev) ? " L%d-%s" : "L%d-%s", r->ant, r->name);
	}
	else
		return (0);
	return (1);
}

static int		send_ants(t_list *path, t_info *info)
{
	t_list	*l;
	int		ants_nbr;
	int		prev;

	ants_nbr = info->ants;
	info->ants--;
	while (((t_room*)info->end->content)->ant != ants_nbr)
	{
		l = path;
		prev = 0;
		while (l->next)
		{
			if (l && l->next)
				if (move_ants(prev, l->content, l->next->content, info))
					prev = 1;
			l = l->next;
		}
		ft_putchar('\n');
	}
	return (1);
}

int				print_n_path(t_list **input, t_info *info)
{
	t_list		*path;

	if (!path_create(&path, *info))
		return (0);
	if (info->debug)
	{
		ft_putstr("Path found: ");
		ft_lstiter(path, debug_path);
	}
	if (!info->quiet)
	{
		ft_printf("%d\n", info->ants);
		ft_lstiter(*input, print_elem);
	}
	((t_room*)info->start->content)->ant = 1;
	send_ants(path, info);
	ft_lstdel(&path, del_void);
	return (1);
}
