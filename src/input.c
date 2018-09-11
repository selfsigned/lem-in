/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 06:30:03 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/11 15:57:15 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdlib.h>

size_t	parse_ant_number(void)
{
	char	*tmp;
	int		r;

	tmp = NULL;
	while (get_next_line(0, &tmp) >= 0)
	{
		if (!tmp)
			break ;
		if (tmp[0] == '#')
		{
			free(tmp);
			continue ;
		}
		else
		{
			r = ft_atoi(tmp);
			free(tmp);
			if (r > 0)
				return ((size_t)r);
			else
				break ;
		}
	}
	return (0);
}

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
