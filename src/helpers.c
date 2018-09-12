/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 03:48:44 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/12 13:48:24 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "printf.h"

t_room		*get_room(t_list *rooms, char *name)
{
	t_room	*content;

	while (rooms)
	{
		content = rooms->content;
		if (content)
		{
			if (!ft_strcmp(content->name, name))
				return (content);
		}
		rooms = rooms->next;
	}
	return (NULL);
}

int			print_error(char *msg, t_info info)
{
	if (info.debug)
		ft_putendl(msg);
	else
		ft_putendl(ERROR_S);
	return (1);
}
