/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:40:10 by aharrass          #+#    #+#             */
/*   Updated: 2022/12/15 15:40:59 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_sa(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp2 = (*stack_a);
	tmp = (*stack_a)->next->next;
	(*stack_a)->next->prev = NULL;
	(*stack_a)->prev = (*stack_a)->next;
	if (tmp)
		tmp->prev = (*stack_a);
	(*stack_a) = tmp2->next;
	(*stack_a)->next = tmp2;
	(*stack_a)->next->next = tmp;
}

void	ft_sb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp2 = (*stack_b);
	tmp = (*stack_b)->next->next;
	(*stack_b)->next->prev = NULL;
	(*stack_b)->prev = (*stack_b)->next;
	if (tmp)
		tmp->prev = (*stack_b);
	(*stack_b) = tmp2->next;
	(*stack_b)->next = tmp2;
	(*stack_b)->next->next = tmp;
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!*stack_b)
		return ;
	tmp = (*stack_b)->next;
	tmp2 = (*stack_a);
	(*stack_a) = (*stack_b);
	(*stack_a)->next = tmp2;
	if ((*stack_a)->next)
		(*stack_a)->next->prev = (*stack_a);
	(*stack_b) = tmp;
	if ((*stack_b))
		(*stack_b)->prev = NULL;
	(*stack_a)->prev = NULL;
}

void	ft_pb(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!*stack_a)
		return ;
	tmp = (*stack_b);
	tmp2 = (*stack_a)->next;
	(*stack_b) = (*stack_a);
	(*stack_b)->next = tmp;
	if ((*stack_b)->next)
		(*stack_b)->next->prev = (*stack_b);
	(*stack_a) = tmp2;
	if ((*stack_a))
		(*stack_a)->prev = NULL;
	(*stack_b)->prev = NULL;
}

void	ft_ra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!*stack_a)
		return ;
	tmp2 = find_last(*stack_a);
	tmp = *stack_a;
	(*stack_a)->prev = tmp2;
	*stack_a = tmp->next;
	(*stack_a)->prev = NULL;
	tmp->next = NULL;
	tmp2->next = tmp;
}
