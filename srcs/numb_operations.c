/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numb_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:09:38 by sclam             #+#    #+#             */
/*   Updated: 2021/11/25 20:34:15 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_check_value(int n, t_file *point)
{
	t_node	*tmp;

	tmp = point->stack_a;
	while (tmp->next != NULL)
	{
		if (n == tmp->numb)
			ft_clean_exit(point, EXIT_FAILURE);
		tmp = tmp->next;
	}
}

int	ft_find_pos(t_node *lst, int numb)
{
	t_node	*tmp;
	int		pos;

	pos = 1;
	tmp = lst;
	while (tmp)
	{
		if (numb == tmp->numb)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}

int	ft_largest(t_node *lst)
{
	t_node	*tmp;
	int		numb;

	tmp = lst;
	numb = tmp->numb;
	while (tmp)
	{
		if (numb < tmp->numb)
			numb = tmp->numb;
		tmp = tmp->next;
	}
	return (numb);
}

int	ft_min(t_node *lst)
{
	t_node	*tmp;
	int		numb;

	tmp = lst;
	numb = tmp->numb;
	while (tmp)
	{
		if (numb > tmp->numb)
			numb = tmp->numb;
		tmp = tmp->next;
	}
	return (numb);
}
