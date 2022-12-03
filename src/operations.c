/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 02:13:56 by aharrass          #+#    #+#             */
/*   Updated: 2022/12/03 14:11:36 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_sa(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = (*stack_a)->next->next;
	tmp2 = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	(*stack_a)->next = tmp2;
	(*stack_a)->next->next = tmp;
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = (*stack_b)->next->next;
	tmp2 = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	(*stack_b)->next = tmp2;
	(*stack_b)->next->next = tmp;
	ft_putstr_fd("sb\n", 1);
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp2;

	tmp2 = (*stack_a);
	if (!*stack_b)
		return ;
	(*stack_a) = (*stack_b);
	(*stack_b)->next = tmp2;
	(*stack_b) = (*stack_b)->next;
	ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = (*stack_b);
	if (!*stack_a)
		return ;
	(*stack_b) = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	(*stack_b)->next = tmp;
	ft_putstr_fd("sb\n", 1);
}

void	ft_ra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp2 = find_last(*stack_a);
	tmp = *stack_a;
	*stack_a = tmp->next;
	tmp->next = NULL;
	tmp2->next = tmp;
	ft_putstr_fd("ra\n", 1);
}
