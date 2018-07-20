/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 18:16:40 by xperrin           #+#    #+#             */
/*   Updated: 2018/07/22 21:57:10 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static	int	is_room(t_list *input)
{
	return (1);
}

int			parse_rooms(t_list *input, t_info *info, t_list **rooms)
{
	size_t		room_count;
	t_posflag	flag;

	room_count = 0;
	flag = nil;
	while (input)
	{
		if (is_room(input))
			room_count++;
		if (ft_strnstr(input->content, START_S, ft_strlen(START_S)))
			flag = start;
		else if (ft_strnstr(input->content, END_S, ft_strlen(END_S)))
			flag = end;
		else
			ft_putendl(input->content);
		input = input->next;
	}
	return (1);
}
