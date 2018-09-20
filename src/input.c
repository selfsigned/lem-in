/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 06:30:03 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/20 18:54:13 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdlib.h>

int		read_input(t_list **list)
{
	char	*line;
	t_list	*next_list;
	t_list	*tmp_list;

	if (get_next_line(0, &line) <= 0)
		return (0);
	*list = ft_lstnew(line, sizeof(char) * (ft_strlen(line) + 1));
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

size_t	parse_ant_number(t_list *input, t_info *info)
{
	char	*tmp;
	int		r;

	while (input)
	{
		tmp = input->content;
		if (!tmp || !tmp[0])
			break ;
		if (tmp[0] == '#')
			input = input->next;
		else
		{
			if ((r = ft_atoi(tmp)) > 0 && !is_room(tmp))
			{
				info->ants = r;
				info->in_rooms = input->next;
				return (1);
			}
			else
				break ;
		}
	}
	return (0);
}
