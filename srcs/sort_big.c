/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:07:05 by sclam             #+#    #+#             */
/*   Updated: 2021/11/27 18:21:48 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_convert(t_file *point)
{
	t_node	*tmp;
	t_node	*tmp1;
	size_t	hm;

	tmp = point->stack_a;
	while (tmp)
	{
		hm = 0;
		tmp1 = point->stack_a;
		while (tmp1)
		{
			if (tmp1->numb < tmp->numb)
				hm++;
			tmp1 = tmp1->next;
		}
		tmp->new_numb = hm;
		tmp = tmp->next;
	}
}

static void	ft_iterations(t_file *point, int size, int i)
{
	int		j;
	int		num;

	j = 0;
	while (j < size)
	{
		num = point->stack_a->new_numb;
		if (((num >> i) & 1) == 1)
			ft_ra(point, 1);
		else
			ft_pb(point, 0);
		j++;
	}
}

void	ft_sort_large(t_file *point)
{
	int		size;
	int		max_bits;
	int		max_num;
	int		i;

	ft_convert(point);
	max_bits = 0;
	i = 0;
	size = ft_lst_size(point->stack_a);
	max_num = size - 1;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		ft_iterations(point, size, i++);
		while (point->stack_b->pos != 'e')
			ft_pa(point, 0);
	}
}
