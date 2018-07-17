/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:49:38 by xperrin           #+#    #+#             */
/*   Updated: 2018/07/21 15:25:01 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdlib.h>

static	size_t	parse_ant_number(void)
{
	char	*tmp;
	int		r;

	if (get_next_line(0, &tmp) >= 0)
	{
		r = ft_atoi(tmp);
		free(tmp);
		if (r > 0)
			return ((size_t)r);
	}
	return (0);
}

static int		read_input(t_list **list)
{
	char	*line;
	t_list	*next_list;
	t_list	*tmp_list;

	if (get_next_line(0, &line) <= 0)
	{
		free(line);
		return (0);
	}
	*list = ft_lstnew(line,  sizeof(char) * ft_strlen(line));
	tmp_list = *list;
	free(line);
	while (get_next_line(0, &line) > 0)
	{
		next_list = ft_lstnew(line, sizeof(char) * ft_strlen(line));
		tmp_list->next = next_list;
		tmp_list = tmp_list->next;
		free(line);
	}
	return (1);
}

int				print_error(void)
{
	ft_putstr(ERROR_S);
	return (1);
}

int				main(void)
{
	t_info	i;
	t_list	rooms;
	t_list	*input;

	if (!(i.ants = parse_ant_number()))
		return (print_error());
	ft_printf("%d\n", i.ants);
	read_input(&input);
	while (input)
	{
		ft_printf("content: %s next:%p\n", input->content, input->next);
		input = input->next;
	}
	return (0);
}
