/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:49:38 by xperrin           #+#    #+#             */
/*   Updated: 2018/09/12 19:16:50 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "printf.h"
#include <stdlib.h>

static	void	init_info(t_info *info)
{
	info->error = 0;
	info->debug = 0;
	info->quiet = 0;
	info->ants = 0;
	info->start = NULL;
	info->end = NULL;
}

static	int		logic(t_info *info)
{
	t_list	*input;
	t_list	*rooms;

	if (!(info->ants = parse_ant_number()))
		return (print_error(ERROR_ANTS, *info));
	if (!read_input(&input))
		return (print_error(ERROR_INPUT, *info));
	if (!parse_rooms(input, info, &rooms))
	{
		ft_lstdel(&input, del_lst_string);
		return (print_error(ERROR_ROOMS, *info));
	}
	if (!parse_links(input, &rooms))
	{
		ft_lstdel(&input, del_lst_string);
		ft_lstdel(&rooms, del_room);
		return (print_error(ERROR_LINKS, *info));
	}
	/* TODO memory */
	if (!dijkstra(&rooms, info))
	{
		return (print_error(ERROR_ALGO, *info));
	}
	if (!(print_n_path(&input, info)))
		return (print_error(ERROR_ALGO, *info));
	ft_lstdel(&input, del_lst_string);
	ft_lstdel(&rooms, del_room);
	return (0);
}

int				main(int ac, char **av)
{
	t_info	info;

	init_info(&info);
	if (ac > 1)
		while (ac-- != 0)
		{
			if (!ft_strcmp(DEBUG_A, av[ac]) || !ft_strcmp("-d", av[ac]))
				info.debug = 1;
			if (!ft_strcmp(QUIET_A, av[ac]) || !ft_strcmp("-q", av[ac]))
				info.quiet = 1;
			if (!ft_strcmp(HELP_A, av[ac]) || !ft_strcmp("-h", av[ac]))
			{
				ft_putendl(HELP_FULL);
				return (0);
			}
		}
	return (logic(&info));
}
