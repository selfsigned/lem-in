/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 16:13:55 by xperrin           #+#    #+#             */
/*   Updated: 2018/08/08 04:08:29 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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

int		parse_links(t_list *input, t_list **rooms)
{
	while (input)
	{
		if (is_link(input->content))
		{
			ft_putendl(input->content);
		}
		input = input->next;
	}

	/* DEBUG */
	t_room *tmp;
	if ((tmp = get_room_by_name(*rooms, "7")))
	{
		ft_printf("room %s found, addr: %p\n", tmp->name, tmp);
	}

	return (1);
}
