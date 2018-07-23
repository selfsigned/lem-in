/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 18:16:40 by xperrin           #+#    #+#             */
/*   Updated: 2018/07/23 09:02:39 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static	int		is_room(char *s)
{
	size_t	i;

	i = 0;
	if (s[i] == 'L' || s[i] == '#')
		return (0);
	while (s[i] && ft_isalnum(s[i]))
		i++;
	if (!i || s[i] != ' ')
		return (0);
	while (ft_isalnum(s[i]))
		i++;
	if (!s[i] || s[i] != ' ' || !s[i + 1] || !ft_isalnum(s[i + 1]))
		return (0);
	return (1);
}

static	t_room	create_room(char *input, t_posflag flag)
{
	t_room	room;
	char	**s;
	size_t	i;

	room.flag = flag;
	room.name = NULL;
	if (!(s = ft_strsplit(input, ' ')))
		return (room);
	i = 0;
	while (s[i])
		i++;
	if (i != 3)
	{
		if (i)
			ft_strdeltab(s, i);
		return (room);
	}
	room.name = ft_strdup(s[0]);
	room.x = ft_atoi(s[1]);
	room.y = ft_atoi(s[2]);
	ft_strdeltab(s, 3);
	return (room);
}

int				parse_rooms(t_list *input, t_info *info, t_list **rooms)
{
	size_t		room_count;
	t_posflag	flag;
	t_room		testroom;

	room_count = 0;
	flag = nil;
	while (input)
	{
		if (is_room(input->content))
		{
			testroom = create_room(input->content, flag);
			ft_printf("name:%s x:%d y:%d flag:%d\n", testroom.name, testroom.x,
					testroom.y, flag);
			flag = nil;
			room_count++;
		}
		if (ft_strnstr(input->content, START_S, ft_strlen(START_S)))
			flag = start;
		else if (ft_strnstr(input->content, END_S, ft_strlen(END_S)))
			flag = end;
		input = input->next;
	}
	ft_printf("%d\n", room_count);
	return (1);
}
