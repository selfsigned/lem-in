/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:49:38 by xperrin           #+#    #+#             */
/*   Updated: 2018/07/23 18:47:37 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdlib.h>

static	size_t	parse_ant_number(void)
{
	char	*tmp;
	int		r;

	if (get_next_line(0, &tmp) >= 0)
	{
		r = ft_atoi(tmp);
		free(tmp);
		if (r > 0)
			return ((size_t)r);
	}
	return (0);
}

static int		read_input(t_list **list)
{
	char	*line;
	t_list	*next_list;
	t_list	*tmp_list;

	if (get_next_line(0, &line) <= 0)
	{
		/* free(line); */
		return (0);
	}
	*list = ft_lstnew(line,  sizeof(char) * (ft_strlen(line) + 1));
	tmp_list = *list;
	free(line);
	while (get_next_line(0, &line) > 0)
	{
		next_list = ft_lstnew(line, sizeof(char) * (ft_strlen(line) + 1));
		tmp_list->next = next_list;
		tmp_list = tmp_list->next;
		free(line);
	}
	return (1);
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

	t_room	*tmp;

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
	for (int i = 0; rooms ; i++)
	{
		if (i != 0)
		{
			tmp = rooms->content;
			ft_printf("name:%s x:%d y:%d flag:%d next:%p\n", 
				tmp->name,	tmp->x, tmp->y, tmp->flag, rooms->next);
		}
		rooms = rooms->next;
	}
	ft_lstdel(&rooms_t, del_room);
	ft_lstdel(&input, del_lst_string); /* TODO proper functions */
	return (0);
}
