/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:01:12 by sclam             #+#    #+#             */
/*   Updated: 2021/11/26 19:34:36 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_file	*point;

	if (argc < 2)
		exit(EXIT_FAILURE);
	point = ft_init_struct(argc, argv, 0);
	if (ft_lst_size(point->stack_a) <= 3)
		ft_sort_small(point);
	else if (ft_lst_size(point->stack_a) <= 40)
	{
		while (ft_lst_size(point->stack_a) != 3 && ft_sorted(point, 'a') != 0)
			ft_pb(point, 0);
		ft_sort_medium(point);
		if (ft_find_pos(point->stack_a, ft_min(point->stack_a))
			>= ft_lst_size(point->stack_a) / 2)
		{
			while (ft_sorted(point, 'a') != 0)
				ft_rra(point, 1);
		}
		while (ft_sorted(point, 'a') != 0)
			ft_ra(point, 1);
	}
	else
		ft_sort_large(point);
	ft_clean_exit(point, EXIT_SUCCESS);
}
