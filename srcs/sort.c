/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:08:25 by sclam             #+#    #+#             */
/*   Updated: 2021/11/26 19:35:43 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_sorted_helper(t_node *lst, int num, char c)
{
	t_node	*tmp;

	tmp = lst;
	while (tmp && c == 'a')
	{
		if (num > tmp->numb)
			return (1);
		tmp = tmp->next;
	}
	while (tmp && c == 'b')
	{
		if (num < tmp->numb)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_sorted(t_file *point, char c)
{
	t_node	*tmp;

	if (c == 'a')
	{
		tmp = point->stack_a;
		while (tmp)
		{
			if (ft_is_sorted_helper(tmp->next, tmp->numb, 'a') == 1)
				return (1);
			tmp = tmp->next;
		}
		return (0);
	}
	tmp = point->stack_b;
	while (tmp)
	{
		if (ft_is_sorted_helper(tmp->next, tmp->numb, 'b') == 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_sort_small(t_file *point)
{
	int	pos;

	if (ft_sorted(point, 'a') == 0)
		return ;
	pos = ft_find_pos(point->stack_a, ft_largest(point->stack_a));
	if (pos == 3)
		ft_s_a_b(point->stack_a, 1);
	if (pos == 1 && ft_find_pos(point->stack_a, ft_min(point->stack_a)) == 3)
	{
		ft_s_a_b(point->stack_a, 1);
		ft_rra(point, 1);
	}
	if (pos == 1 && ft_find_pos(point->stack_a, ft_min(point->stack_a)) == 2)
		ft_ra(point, 1);
	if (pos == 2 && ft_find_pos(point->stack_a, ft_min(point->stack_a)) == 1)
	{
		ft_s_a_b(point->stack_a, 1);
		ft_ra(point, 1);
	}
	if (pos == 2 && ft_find_pos(point->stack_a, ft_min(point->stack_a)) == 3)
		ft_rra(point, 1);
}

static void	ft_sort_helper(t_file *point)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = point->stack_a;
	while (tmp && tmp->numb < point->stack_b->numb)
	{
		tmp = tmp->next;
		i++;
	}
	if (i == ft_lst_size(point->stack_a) || i == 0)
	{
		ft_rra(point, 1);
		return ;
	}
	if (i <= ft_lst_size(point->stack_a) / 2)
	{
		while (i-- > 0)
			ft_ra(point, 1);
		ft_pa(point, 0);
		return ;
	}
	while (i++ < ft_lst_size(point->stack_a))
		ft_rra(point, 1);
	ft_pa(point, 0);
}

void	ft_sort_medium(t_file *point)
{
	ft_sort_small(point);
	while (point->stack_b->pos != 'e')
	{
		if (point->stack_b->numb < point->stack_a->numb
			&& ft_find_pos(point->stack_a, ft_min(point->stack_a)) == 1)
			ft_pa(point, 0);
		else if (point->stack_b->numb > ft_lst_last(point->stack_a)->numb
			&& ft_find_pos(point->stack_a, ft_largest(point->stack_a))
			== ft_lst_size(point->stack_a))
		{
			ft_pa(point, 0);
			ft_ra(point, 1);
		}
		else if (point->stack_b->numb > point->stack_a->numb
			&& point->stack_b->numb < point->stack_a->next->numb)
		{
			ft_pa(point, 0);
			ft_s_a_b(point->stack_a, 1);
		}
		else if (point->stack_b->numb < point->stack_a->numb
			&& point->stack_b->numb > ft_lst_last(point->stack_a)->numb)
			ft_pa(point, 0);
		else
			ft_sort_helper(point);
	}
}
