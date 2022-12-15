/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:30:09 by aharrass          #+#    #+#             */
/*   Updated: 2022/12/15 23:51:08 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct st
{
	int			element;
	struct st	*next;
	struct st	*prev;
}				t_stack;

t_stack			*ft_lstnew(int element);

void			ft_lstadd_front(t_stack **lst, t_stack *new);
void			check_args2(char **av, int j);
void			check_args_2(int ac, char **av);
t_stack			*push_to_stack(t_stack **st, long long element);
void			check_dup(t_stack **stack_a);
void			clean_lst(t_stack **stack);
t_stack			*make_stack_2(int ac, char **av);
void			help_push(int i, char **av, t_stack **a);
t_stack			*find_last(t_stack *stack);
int				lst_count(t_stack *stack_a);
int				is_sorted(t_stack *stack_a);
void			ft_sa(t_stack **stack_a);
void			ft_sb(t_stack **stack_b);
void			ft_ss(t_stack **stack_a, t_stack **stack_b);
void			ft_pa(t_stack **stack_a, t_stack **stack_b);
void			ft_pb(t_stack **stack_b, t_stack **stack_a);
void			ft_ra(t_stack **stack_a);
void			ft_rb(t_stack **stack_b);
void			ft_rr(t_stack **stack_a, t_stack **stack_b);
void			ft_rra(t_stack **stack_a);
void			ft_rrb(t_stack **stack_b);
void			ft_rrr(t_stack **stack_a, t_stack **stack_b);
void			ft_small(t_stack **stack_a, t_stack **stack_b);
void			ft_sort_three(t_stack **stack_a);
int				find_smallest(t_stack *stack_a);
int				get_index(t_stack *stack_a, int element);
void			ft_free_av(char **res);
void			exit_error(void);
void			ft_medium(t_stack **stack_a, t_stack **stack_b, int n,
					int lst_c);
void			swap(int *x, int *y);
void			quick_sort(int arr[], int start, int end);
int				part(int arr[], int start, int end);
int				find_from_start(t_stack *stack_a, int arr[], int start,
					int end);
int				find_biggest(t_stack *stack_b);
void			ft_medium_help(t_stack **stack_a, t_stack **stack_b);
int				ft_strcmp(char *s1, char *s2);
int				*make_arr(t_stack *stack_a);
void			medium_if(int *j, int *i, int n, int ok);
int				medium_cut(int k, int lst_c, t_stack **stack_a,
					t_stack **stack_b);
void			medium_last(t_stack **stack_b, int *arr, int ok);
void			push_big(t_stack **stack_a, t_stack **stack_b, int big, int *i);
void			push_big2(t_stack **stack_a, t_stack **stack_b, int big,
					int *i);
void			checker_help(char *tmp, t_stack **stack_a, t_stack **stack_b);
void			exit_checker(t_stack **stack_a, t_stack **stack_b, char **tmp);
#endif
