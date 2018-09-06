/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 16:13:55 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/06 17:59:52 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static	int		is_link(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '-')
		i++;
	if (!i || !s[i] || s[i] != '-'
		|| !s[i + 1] || !ft_isalnum(s[i + 1]))
		return (0);
	return (1);
}

static	int		create_link(t_room *src, t_room *dst)
{
	t_list	*tmp_list;

	if (!src->links)
	{
		if (!(src->links = ft_lstnew(dst, sizeof(t_room))))
			return (0);
	}
	else
	{
		if (!(tmp_list = ft_lstnew(dst, sizeof(t_room))))
			return (0);
		ft_lstappend(&src->links, tmp_list);
	}
	return (1);
}

static	int		append_link(t_list **rooms, char **input)
{
	t_room	*src;
	t_room	*dst;

	src = get_room(*rooms, input[0]);
	dst = get_room(*rooms, input[1]);
	if (!src || !dst)
		return (0);
	if (!get_room(src->links, input[1]))
	{
		if (!create_link(src, dst))
			return (0);
	}
	if (!get_room(dst->links, input[0]))
	{
		if (!create_link(dst, src))
			return (0);
	}
	return (1);
}

int				parse_links(t_list *input, t_list **rooms)
{
	char	**link_rooms;
	int		i;

	while (input)
	{
		i = 0;
		if (is_link(input->content))
		{
			link_rooms = ft_strsplit(input->content, '-');
			while (link_rooms[i])
				++i;
			if (i != 2)
				ft_putendl("TODO error!");
			append_link(rooms, link_rooms);
			ft_strdeltab(link_rooms, i);
		}
		input = input->next;
	}
	return (1);
}
