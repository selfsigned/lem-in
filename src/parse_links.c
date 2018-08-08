/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 16:13:55 by xperrin           #+#    #+#             */
/*   Updated: 2018/08/08 19:59:27 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

#include "printf.h" /* DEBUG */

static	int		is_link(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && ft_isalnum(s[i]))
		i++;
	if (!i || !s[i] || s[i] != '-'
		|| !s[i + 1] || !ft_isalnum(s[i + 1]))
		return (0);
	return (1);

}

static	int		append_link(t_list **rooms, char **input)
{
	t_room	*src;
	t_room	*dst;
	t_list	*tmp_list;

	src = get_room(*rooms, input[0]);
	dst = get_room(*rooms, input[1]);
	if (!src || !dst)
		return (0);
	ft_printf("%s %s\n", src->name, dst->name);
	if (!src->links)
	{
		if (!(src->links = ft_lstnew(dst, sizeof(t_room))))
			return (0);
		/* t_room *content = src->links->content; */
		/* ft_printf("%p name: %s flag: %d\n", src->links->content, content->name, content->flag); */
	}
	else
	{
		if (!(tmp_list = ft_lstnew(dst, sizeof(t_room))))
			return (0);
		/* src->links->next = tmp_list; */
		ft_lstappend(&src->links, tmp_list);
		t_room *content = src->links->content;
		ft_printf("%p name: %s flag: %d next:%p\n", src->links->content, content->name, content->flag, src->links->next);
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
			{
				/* TODO handle error case gracefully */
				ft_putendl("error!");
			}
			append_link(rooms, link_rooms);
			ft_strdeltab(link_rooms, i);
		}
		input = input->next;
	}
	return (1);
}
