/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 18:16:40 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/03 14:48:58 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				is_room(char *s)
{
	size_t	i;

	i = 0;
	if (s[i] == 'L' || s[i] == '#')
		return (0);
	while (s[i] && s[i] != ' ')
		i++;
	if (!i || s[i] != ' ')
		return (0);
	while (ft_isdigit(s[i]))
		i++;
	if (!s[i] || s[i] != ' ' || !s[i + 1] || !ft_isdigit(s[i + 1]))
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
	room.links = NULL;
	ft_strdeltab(s, 3);
	return (room);
}

static int		append_room(char *s, t_list **rooms,
					t_info *info, t_posflag flag)
{
	static	int	head = 0;
	t_room		r;
	t_list		*link;

	r = create_room(s, flag);
	if (!r.name)
		return (0);
	if (head)
		if (get_room(*rooms, r.name))
		{
			ft_strdel(&r.name);
			return (0);
		}
	if (!(link = ft_lstnew(&r, sizeof(t_room))))
		return (0);
	if (head)
		ft_lstappend(rooms, link);
	else
		*rooms = link;
	if (flag == start)
		info->start = link;
	else if (flag == end)
		info->end = link;
	head++;
	return (1);
}

int				parse_rooms(t_posflag flag,
					t_list *input, t_info *info, t_list **rooms)
{
	size_t		room_count;

	room_count = 0;
	while (input)
	{
		if (is_room(input->content))
		{
			if (!append_room(input->content, rooms, info, flag))
				return (0);
			flag = nil;
			room_count++;
		}
		else if (ft_strnstr(input->content, START_S, ft_strlen(START_S)))
			flag = start;
		else if (ft_strnstr(input->content, END_S, ft_strlen(END_S)))
			flag = end;
		else if (!(input->content && ((char*)input->content)[0] == '#'))
		{
			info->in_links = input;
			return ((room_count < 2) ? 0 : 1);
		}
		input = input->next;
	}
	return (0);
}
