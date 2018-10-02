/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_send.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 17:10:56 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/02 17:23:01 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "printf.h"

/*
** path order: end -> to -> start
*/

static int		move_ant_start_to_end(int prev, t_room *r, t_room *p)
{
	r->ant++;
	ft_printf((prev) ? " L%d-%s" : "L%d-%s", p->ant, r->name);
	p->ant++;
	return (S_TO_END_INLINE_HACK);
}

static int		move_new_ant(int prev, t_room *r, t_room *p, t_info *info)
{
	r->ant = p->ant;
	p->ant++;
	info->ants--;
	ft_printf((prev) ? " L%d-%s" : "L%d-%s", r->ant, r->name);
	return (1);
}

static int		move_ants(int prev, t_room *r, t_room *p, t_info *info)
{
	if (p->flag == start && r->flag == end)
		return (move_ant_start_to_end(prev, r, p));
	else if (r->flag == end && p->ant)
	{
		ft_printf((prev) ? " L%d-%s" : "L%d-%s", p->ant, r->name);
		p->ant = 0;
		r->ant++;
	}
	else if (p->flag == start && info->ants && !r->ant)
		return (move_new_ant(prev, r, p, info));
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

int				send_ants(t_list *path, t_info *info)
{
	t_list	*l;
	int		ants_nbr;
	int		prev;
	int		r;

	ants_nbr = info->ants;
	info->ants--;
	while (((t_room*)info->end->content)->ant != ants_nbr)
	{
		l = path;
		prev = (r == S_TO_END_INLINE_HACK) ? 1 : 0;
		while (l->next)
		{
			if (l && l->next)
				if ((r = move_ants(prev, l->content, l->next->content, info)))
					prev = 1;
			l = l->next;
		}
		if (r != S_TO_END_INLINE_HACK)
			ft_putchar('\n');
	}
	if (r == S_TO_END_INLINE_HACK)
		ft_putchar('\n');
	return (1);
}
