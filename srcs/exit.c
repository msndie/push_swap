/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:50:07 by sclam             #+#    #+#             */
/*   Updated: 2021/11/25 20:35:35 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lst_clear(t_node **lst)
{
	t_node	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			free((*lst));
			(*lst) = tmp;
		}
		lst = NULL;
	}
}

void	ft_clear_struct(t_file *point)
{
	ft_lst_clear(&point->stack_a);
	ft_lst_clear(&point->stack_b);
	free(point);
}

void	ft_clean_exit(t_file *point, int n)
{
	if (n == 2)
	{
		ft_clear_struct(point);
		ft_putstr_fd("Malloc error\n", 2);
		exit (EXIT_FAILURE);
	}
	else if (n == 1)
	{
		ft_clear_struct(point);
		ft_putstr_fd("Error\n", 2);
		exit(n);
	}
	else if (n == 0)
	{
		ft_clear_struct(point);
		exit(n);
	}
}
