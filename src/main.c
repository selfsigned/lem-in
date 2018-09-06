/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:49:38 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/06 22:05:18 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "printf.h"
#include <stdlib.h>

static	void	disp_rooms(t_list *rooms)
{
	t_room	*tmp;
	t_room	*tmp_link;
	t_list	*node;

	while (rooms)
	{
		tmp = rooms->content;
		ft_printf("name:%.5s x:%.02d y:%.02d distance:%d  flag:%d links:",
			tmp->name, tmp->x, tmp->y, tmp->distance, tmp->flag);
		node = tmp->links;
		while (node)
		{
			tmp_link = node->content;
			ft_printf("(n:%s f:%d a:%p) ",
				tmp_link->name, tmp_link->flag, tmp_link);
			node = node->next;
		}
		ft_printf("addr:%p\n", rooms->content);
		rooms = rooms->next;
	}
}

int				print_error(void)
{
	ft_putstr(ERROR_S);
	return (1);
}

int				main(void)
{
	t_info	info;
	t_list	*input;
	t_list	*rooms;
	t_list	*rooms_t;

	/* Parsing */
	if (!(info.ants = parse_ant_number()))
		return (print_error());
	if (!read_input(&input))
		return (print_error());
	if (!parse_rooms(input, &info, &rooms))
	{
		ft_lstdel(&input, del_lst_string);
		return (print_error());
	}
	rooms_t = rooms;
	rooms = rooms->next;
	free(rooms_t);
	if (!parse_links(input, &rooms))
	{
		ft_lstdel(&input, del_lst_string);
		return (print_error());
	}

	/* Algorithm */
	algo_init(&rooms, info);

	/* Parser Debug Printing */
	disp_rooms(rooms);
	ft_printf("start:%p end:%p\n", info.start->content, info.end->content);

	/* Memory */
	ft_lstdel(&rooms, del_room);
	ft_lstdel(&input, del_lst_string);
	return (0);
}
