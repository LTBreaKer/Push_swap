/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:30:09 by aharrass          #+#    #+#             */
/*   Updated: 2022/12/08 14:49:52 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct st
{
	int			element;
	struct st	*next;
	struct st *prev;
}				t_stack;

t_stack			*ft_lstnew(int element);

void			ft_lstadd_front(t_stack **lst, t_stack *new);
void			check_args1(int ac, char **av, int j);
void			check_args2(int ac, char **av, int j);
void			check_args(int ac, char **av, int j);
t_stack			*push_to_stack(t_stack **st, long long element);
void			check_dup(t_stack **stack_a);
void			clean_lst(t_stack **stack);
t_stack			*make_stack(int ac, char **av);
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
void			ft_free_av(char **res, int sub_index);
void			exit_error(void);
void			ft_medium(t_stack **stack_a, t_stack **stack_b);
void			swap(int *x, int *y);
void			quick_sort(int arr[], int start, int end);
int				part(int arr[], int start, int end);
#endif
