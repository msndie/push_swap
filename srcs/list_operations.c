/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:26:51 by sclam             #+#    #+#             */
/*   Updated: 2021/11/25 20:34:13 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_lst_new(void)
{
	t_node	*tmp;

	tmp = malloc(sizeof(t_node));
	if (tmp == NULL)
		return (0);
	tmp->next = NULL;
	return (tmp);
}

int	ft_lst_size(t_node *lst)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_node	*ft_lst_last(t_node *lst)
{
	t_node	*tmp;

	tmp = lst;
	while (lst && tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

int	ft_lst_add_back(t_node **lst, t_node *new)
{
	t_node	*tmp;

	if (!new)
		return (-1);
	if (!*lst)
	{
		*lst = new;
		return (0);
	}
	else
	{
		tmp = ft_lst_last(*lst);
		tmp->next = new;
	}
	return (0);
}

int	ft_lst_add_front(t_node **lst, t_node *new)
{
	if (!new)
		return (-1);
	new->next = *lst;
	*lst = new;
	return (0);
}
