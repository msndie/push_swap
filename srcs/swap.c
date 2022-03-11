/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:08:37 by sclam             #+#    #+#             */
/*   Updated: 2021/11/26 19:35:53 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_s_a_b(t_node *lst, int n)
{
	t_node	*tmp;
	int		tmp1;
	int		tmp2;

	if (lst->next == NULL || lst->pos == 'e')
		return ;
	tmp = lst->next;
	tmp1 = lst->numb;
	tmp2 = lst->new_numb;
	lst->numb = tmp->numb;
	lst->new_numb = tmp->new_numb;
	tmp->numb = tmp1;
	tmp->new_numb = tmp2;
	if (n == 1)
		ft_putendl_fd("sa", 1);
	if (n == 2)
		ft_putendl_fd("sb", 1);
}

void	ft_ss(t_node *lst_a, t_node *lst_b, int bonus)
{
	ft_s_a_b(lst_a, 3);
	ft_s_a_b(lst_b, 3);
	if (bonus == 0)
		ft_putendl_fd("ss", 1);
}
