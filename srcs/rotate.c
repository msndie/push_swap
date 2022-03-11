/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 20:00:57 by sclam             #+#    #+#             */
/*   Updated: 2021/11/26 19:32:50 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_file *point, int n)
{
	t_node	*tmp;
	t_node	*tmp1;

	if (point->stack_a->pos == 'e' || point->stack_a->next == NULL)
		return ;
	tmp = ft_lst_new();
	if (!tmp)
		ft_clean_exit(point, 2);
	tmp->numb = point->stack_a->numb;
	tmp->new_numb = point->stack_a->new_numb;
	tmp->pos = point->stack_a->pos;
	tmp1 = ft_lst_last(point->stack_a);
	tmp1->next = tmp;
	tmp = point->stack_a;
	point->stack_a = point->stack_a->next;
	free(tmp);
	tmp = NULL;
	if (n == 1)
		ft_putendl_fd("ra", 1);
}

void	ft_rb(t_file *point, int n)
{
	t_node	*tmp;
	t_node	*tmp1;

	if (point->stack_b->pos == 'e' || point->stack_b->next == NULL)
		return ;
	tmp = ft_lst_new();
	if (!tmp)
		ft_clean_exit(point, 2);
	tmp->numb = point->stack_b->numb;
	tmp->new_numb = point->stack_b->new_numb;
	tmp->pos = point->stack_b->pos;
	tmp1 = ft_lst_last(point->stack_b);
	tmp1->next = tmp;
	tmp = point->stack_b;
	point->stack_b = point->stack_b->next;
	free(tmp);
	if (n == 1)
		ft_putendl_fd("rb", 1);
}

void	ft_rr(t_file *point, int bonus)
{
	ft_ra(point, 0);
	ft_rb(point, 0);
	if (bonus == 0)
		ft_putendl_fd("rr", 1);
}
