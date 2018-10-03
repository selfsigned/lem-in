/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 06:30:03 by xperrin           #+#    #+#             */
/*   Updated: 2018/10/03 14:43:55 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdlib.h>

int		read_input(t_list **list)
{
	char	*line;
	t_list	*next;
	t_list	*tmp;

	if (get_next_line(0, &line) <= 0)
		return (0);
	if (!(*list = ft_lstnew(line, sizeof(char) * (ft_strlen(line) + 1))))
		return (0);
	tmp = *list;
	free(line);
	while (get_next_line(0, &line) > 0)
	{
		if (!(next = ft_lstnew(line, sizeof(char) * (ft_strlen(line) + 1))))
			return (0);
		tmp->next = next;
		tmp = tmp->next;
		free(line);
	}
	return (1);
}

size_t	parse_ant_number(t_list *input, t_info *info)
{
	char	*tmp;
	char	*c;
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
			if (tmp[0] != '-' && (r = ft_atoi(tmp)) > 0 && !is_room(tmp))
			{
				if (!(c = ft_itoa(r)) || strcmp(c, tmp))
				{
					free(c);
					return (0);
				}
				free(c);
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
