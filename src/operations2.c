/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:19:44 by aharrass          #+#    #+#             */
/*   Updated: 2022/12/08 15:49:28 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_rb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp2 = find_last(*stack_b);
	tmp = *stack_b;
	(*stack_b)->prev = tmp2;
	*stack_b = tmp->next;
	(*stack_b)->prev = NULL;
	tmp->next = NULL;
	tmp2->next = tmp;
	ft_putstr_fd("rb\n", 1);
}

void	ft_rra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack_a;
	tmp2 = find_last(*stack_a);
	while ((*stack_a)->next->next)
		(*stack_a) = (*stack_a)->next;
	(*stack_a)->next = NULL;
	(*stack_a) = tmp2;
	(*stack_a)->next = tmp;
	(*stack_a)->next = tmp2->next;
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack_b;
	tmp2 = find_last(*stack_b);
	while ((*stack_b)->next->next)
		(*stack_b) = (*stack_b)->next;
	(*stack_b)->next = NULL;
	(*stack_b) = tmp2;
	(*stack_b)->next = tmp;
	(*stack_b)->next = tmp2->next;
	ft_putstr_fd("rrb\n", 1);
}
