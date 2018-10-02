/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 16:13:55 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/02 18:25:11 by xperrin          ###   ########.fr       */
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
		if (!(tmp_list = ft_lstnewl((void**)&dst)))
			return (0);
		src->links = tmp_list;
	}
	else
	{
		if (!(tmp_list = ft_lstnewl((void**)&dst)))
			return (0);
		ft_lstappend(&src->links, tmp_list);
	}
	return (1);
}

/*
** -1 is also used as a fatal error code here
*/

static	int		append_link(t_list **rooms, char *r1, char *r2)
{
	t_room	*src;
	t_room	*dst;

	src = get_room(*rooms, r1);
	dst = get_room(*rooms, r2);
	if (!src || !dst || src == dst)
		return (0);
	if (!get_room(src->links, r2))
	{
		if (!create_link(src, dst))
			return (-1);
	}
	if (!get_room(dst->links, r1))
	{
		if (!create_link(dst, src))
			return (-1);
	}
	return (1);
}

/*
** -1 is also used as a non-fatal error code here
*/

static	int		handle_link(t_list *input, t_list **rooms)
{
	char	*s;
	int		i;
	int		r;

	i = 0;
	s = input->content;
	while (s[i])
	{
		if (s[i] == '-')
		{
			s[i] = '\0';
			if (s[i + 1] && (r = append_link(rooms, s, s + i + 1)))
			{
				if (r == -1)
					return (0);
				s[i] = '-';
				return (1);
			}
			s[i] = '-';
		}
		i++;
	}
	return (-1);
}

int				parse_links(t_list *input, t_list **rooms, t_info *info)
{
	int		r;

	while (input)
	{
		if (is_link(input->content))
		{
			if (!(r = handle_link(input, rooms)))
				return (0);
			if (r == -1)
			{
				info->in_end = input;
				return (-1);
			}
			input = input->next;
		}
		else if (input->content && ((char*)input->content)[0] == '#')
			input = input->next;
		else
			return (-1);
		info->in_end = input;
	}
	return (1);
}
