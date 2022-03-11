/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:51:03 by sclam             #+#    #+#             */
/*   Updated: 2021/11/27 15:59:56 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi_w_err(const char *str, t_file *point)
{
	int		m;
	long	result;

	result = 0;
	m = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			m = -1;
		str++;
		if (*str == '-' || *str == '+')
			ft_clean_exit(point, EXIT_FAILURE);
	}
	if (!(*str <= '9' && *str >= '0'))
		ft_clean_exit(point, EXIT_FAILURE);
	while (*str <= '9' && *str >= '0')
		result = result * 10 + (*str++ - '0');
	if (*str != '\0')
		ft_clean_exit(point, EXIT_FAILURE);
	result *= m;
	if (result < -2147483648 || result > 2147483647)
		ft_clean_exit(point, EXIT_FAILURE);
	return (result);
}

void	ft_strs_to_numb(char **strs, t_file *point)
{
	t_node	*tmp;
	int		j;

	j = 0;
	tmp = ft_lst_last(point->stack_a);
	tmp->numb = ft_atoi_w_err(strs[j], point);
	ft_check_value(tmp->numb, point);
	tmp->pos = 'a';
	while (strs[++j])
	{
		if (ft_lst_add_back(&point->stack_a, ft_lst_new()) != 0)
			ft_clean_exit(point, EXIT_FAILURE);
		tmp = tmp->next;
		tmp->numb = ft_atoi_w_err(strs[j], point);
		ft_check_value(tmp->numb, point);
		tmp->pos = 'a';
	}
	ft_free_arr(strs);
}

void	ft_rec_argv(t_file *point, int argc, char **argv, int bonus)
{
	int		i;
	int		n;
	int		j;
	char	**args;

	i = 1;
	n = 0;
	j = 0;
	while (argc - 1 > n)
	{
		args = ft_split(argv[i++], ' ');
		if (!args || !args[0])
			ft_clean_exit(point, EXIT_FAILURE);
		if (args[0] != NULL)
			ft_strs_to_numb(args, point);
		if (n++ + 1 != argc - 1)
		{
			if (ft_lst_add_back(&point->stack_a, ft_lst_new()) != 0)
				ft_clean_exit(point, EXIT_FAILURE);
		}
	}
	if (ft_sorted(point, 'a') == 0 && bonus == 0)
		ft_clean_exit(point, EXIT_SUCCESS);
}

t_file	*ft_init_struct(int argc, char **argv, int bonus)
{
	t_file	*point;

	point = malloc(sizeof(t_file));
	point->stack_a = ft_lst_new();
	if (!point->stack_a)
	{
		free(point);
		exit(EXIT_FAILURE);
	}
	point->stack_b = ft_lst_new();
	if (!point->stack_b)
	{
		ft_lst_clear(&point->stack_a);
		free(point);
		exit(EXIT_FAILURE);
	}
	point->stack_b->pos = 'e';
	ft_rec_argv(point, argc, argv, bonus);
	return (point);
}
