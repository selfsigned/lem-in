/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 18:16:40 by xperrin           #+#    #+#             */
/*   Updated: 2018/07/22 22:51:19 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static	int	is_room(t_list *input)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char*)input->content;
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
	ft_printf("%d\n", room_count);
	return (1);
}
