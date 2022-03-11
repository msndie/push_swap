/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:06:00 by sclam             #+#    #+#             */
/*   Updated: 2021/11/26 19:33:29 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rra(t_file *point, int n)
{
	t_node	*tmp;
	t_node	*tmp1;

	if (point->stack_a->pos == 'e' || point->stack_a->next == NULL)
		return ;
	tmp1 = point->stack_a;
	tmp = ft_lst_last(point->stack_a);
	if (ft_lst_add_front(&point->stack_a, ft_lst_new()) != 0)
		ft_clean_exit(point, 2);
	point->stack_a->numb = tmp->numb;
	point->stack_a->new_numb = tmp->new_numb;
	point->stack_a->pos = tmp->pos;
	while (tmp1->next != tmp)
		tmp1 = tmp1->next;
	free(tmp);
	tmp1->next = NULL;
	if (n == 1)
		ft_putendl_fd("rra", 1);
}

void	ft_rrb(t_file *point, int n)
{
	t_node	*tmp;
	t_node	*tmp1;

	if (point->stack_b->pos == 'e' || point->stack_b->next == NULL)
		return ;
	tmp1 = point->stack_b;
	tmp = ft_lst_last(point->stack_b);
	if (ft_lst_add_front(&point->stack_b, ft_lst_new()) != 0)
		ft_clean_exit(point, 2);
	point->stack_b->numb = tmp->numb;
	point->stack_b->new_numb = tmp->new_numb;
	point->stack_b->pos = tmp->pos;
	while (tmp1->next != tmp)
		tmp1 = tmp1->next;
	free(tmp);
	tmp1->next = NULL;
	if (n == 1)
		ft_putendl_fd("rrb", 1);
}

void	ft_rrr(t_file *point, int bonus)
{
	ft_rra(point, 0);
	ft_rrb(point, 0);
	if (bonus == 0)
		ft_putendl_fd("rrr", 1);
}
