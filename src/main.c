/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:49:38 by xperrin           #+#    #+#             */
/*   Updated: 2018/07/10 19:44:48 by xperrin          ###   ########.fr       */
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

int				print_error(void)
{
	ft_putstr(ERROR_S);
	return (1);
}

int				main(void)
{
	t_info	i;

	if (!(i.ants = parse_ant_number()))
		return (print_error());
	ft_printf("%d\n", i.ants);
	return (0);
}
