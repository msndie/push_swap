/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclam <sclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:10:55 by sclam             #+#    #+#             */
/*   Updated: 2021/11/29 16:52:09 by sclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				numb;
	int				new_numb;
	char			pos;
	struct s_node	*next;
}	t_node;

typedef struct s_file
{
	t_node	*stack_a;
	t_node	*stack_b;
}			t_file;

int		ft_atoi_w_err(const char *str, t_file *point);
t_node	*ft_lst_new(void);
t_node	*ft_lst_last(t_node *lst);
int		ft_lst_add_back(t_node **lst, t_node *new);
int		ft_lst_add_front(t_node **lst, t_node *new);
void	ft_lst_clear(t_node **lst);
void	ft_clear_struct(t_file *point);
int		ft_lst_size(t_node *lst);
t_node	*ft_lst_copy(t_file *point);
void	ft_clean_exit(t_file *point, int n);
void	ft_pa(t_file *point, int bonus);
void	ft_pb(t_file *point, int bonus);
void	ft_s_a_b(t_node *lst, int n);
void	ft_ss(t_node *lst_a, t_node *lst_b, int bonus);
void	ft_ra(t_file *point, int n);
void	ft_rb(t_file *point, int n);
void	ft_rr(t_file *point, int bonus);
void	ft_rra(t_file *point, int n);
void	ft_rrb(t_file *point, int n);
void	ft_rrr(t_file *point, int bonus);
t_file	*ft_init_struct(int argc, char **argv, int bonus);
void	ft_rec_argv(t_file *point, int argc, char **argv, int bonus);
void	ft_strs_to_numb(char **strs, t_file *point);
void	ft_check_value(int n, t_file *point);
int		ft_sorted(t_file *point, char c);
int		ft_is_sorted_helper(t_node *lst, int num, char c);
void	ft_sort_small(t_file *point);
void	ft_sort_medium(t_file *point);
void	ft_sort_large(t_file *point);
int		ft_find_pos(t_node *lst, int numb);
int		ft_min(t_node *lst);
int		ft_largest(t_node *lst);

#endif /*PUSH_SWAP_H*/
