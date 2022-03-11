/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:09:14 by sclam             #+#    #+#             */
/*   Updated: 2021/11/26 19:34:04 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pa(t_file *point, int bonus)
{
	t_node	*tmp;

	if (point->stack_b->pos == 'e')
		return ;
	if (point->stack_a->pos != 'e')
	{
		if (ft_lst_add_front(&point->stack_a, ft_lst_new()) != 0)
			ft_clean_exit(point, 2);
	}
	if (bonus == 0)
		ft_putendl_fd("pa", 1);
	if (point->stack_b->next != NULL)
	{
		tmp = point->stack_b;
		point->stack_b = point->stack_b->next;
		point->stack_a->numb = tmp->numb;
		point->stack_a->new_numb = tmp->new_numb;
		point->stack_a->pos = 'a';
		return (free(tmp));
	}
	point->stack_a->numb = point->stack_b->numb;
	point->stack_a->new_numb = point->stack_b->new_numb;
	point->stack_a->pos = 'a';
	point->stack_b->pos = 'e';
}

void	ft_pb(t_file *point, int bonus)
{
	t_node	*tmp;

	if (point->stack_a->pos == 'e')
		return ;
	if (point->stack_b->pos != 'e')
	{
		if (ft_lst_add_front(&point->stack_b, ft_lst_new()) != 0)
			ft_clean_exit(point, 2);
	}
	if (bonus == 0)
		ft_putendl_fd("pb", 1);
	if (point->stack_a->next != NULL)
	{
		tmp = point->stack_a;
		point->stack_a = point->stack_a->next;
		point->stack_b->numb = tmp->numb;
		point->stack_b->new_numb = tmp->new_numb;
		point->stack_b->pos = 'b';
		return (free(tmp));
	}
	point->stack_b->numb = point->stack_a->numb;
	point->stack_b->new_numb = point->stack_a->new_numb;
	point->stack_b->pos = 'b';
	point->stack_a->pos = 'e';
}
