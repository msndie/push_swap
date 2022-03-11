/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:38:22 by sclam             #+#    #+#             */
/*   Updated: 2022/01/27 15:05:46 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_execute(t_file *point, char *cmd)
{
	if (ft_strncmp(cmd, "sa\n", ft_strlen(cmd)) == 0)
		ft_s_a_b(point->stack_a, 3);
	else if (ft_strncmp(cmd, "sb\n", ft_strlen(cmd)) == 0)
		ft_s_a_b(point->stack_b, 3);
	else if (ft_strncmp(cmd, "ss\n", ft_strlen(cmd)) == 0)
		ft_ss(point->stack_a, point->stack_b, 1);
	else if (ft_strncmp(cmd, "pa\n", ft_strlen(cmd)) == 0)
		ft_pa(point, 1);
	else if (ft_strncmp(cmd, "pb\n", ft_strlen(cmd)) == 0)
		ft_pb(point, 1);
	else if (ft_strncmp(cmd, "ra\n", ft_strlen(cmd)) == 0)
		ft_ra(point, 0);
	else if (ft_strncmp(cmd, "rb\n", ft_strlen(cmd)) == 0)
		ft_rb(point, 0);
	else if (ft_strncmp(cmd, "rr\n", ft_strlen(cmd)) == 0)
		ft_rr(point, 1);
	else if (ft_strncmp(cmd, "rra\n", ft_strlen(cmd)) == 0)
		ft_rra(point, 0);
	else if (ft_strncmp(cmd, "rrb\n", ft_strlen(cmd)) == 0)
		ft_rrb(point, 0);
	else if (ft_strncmp(cmd, "rrr\n", ft_strlen(cmd)) == 0)
		ft_rrr(point, 1);
	else
		return (1);
	return (0);
}

void	ft_exec(t_file *point, char **cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
	{
		if (cmds[i][ft_strlen(cmds[i]) - 1] != '\n')
		{
			ft_free_arr(cmds);
			ft_clean_exit(point, 1);
		}
		if (ft_execute(point, cmds[i]) == 1)
		{
			ft_free_arr(cmds);
			ft_clean_exit(point, 1);
		}
		i++;
	}
}

static char	**ft_read_from_0(t_file *point, int i)
{
	char	**cmds;

	cmds = (char **)malloc(sizeof(char *));
	if (!cmds)
		ft_clean_exit(point, 2);
	cmds[i] = get_next_line(0);
	if (!cmds[i])
	{
		free(cmds);
		i = ft_sorted(point, 'a');
		if (i == 0)
			ft_putendl_fd("OK", 1);
		if (i != 0)
			ft_putendl_fd("KO", 1);
		ft_clear_struct(point);
		exit(EXIT_SUCCESS);
	}
	while (cmds[i])
	{
		cmds = ft_realloc(cmds, sizeof(char *) * (++i + 1));
		if (!cmds)
			ft_clean_exit(point, 2);
		cmds[i] = get_next_line(0);
	}
	return (cmds);
}

int	main(int argc, char **argv)
{
	t_file	*point;
	char	**cmds;
	int		i;

	i = 0;
	if (argc < 2)
		exit(EXIT_FAILURE);
	point = ft_init_struct(argc, argv, 1);
	cmds = ft_read_from_0(point, i);
	ft_exec(point, cmds);
	if (ft_sorted(point, 'a') == 0 && point->stack_b->pos == 'e')
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_free_arr(cmds);
	ft_clean_exit(point, EXIT_SUCCESS);
}
