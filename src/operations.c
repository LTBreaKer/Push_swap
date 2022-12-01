/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 02:13:56 by aharrass          #+#    #+#             */
/*   Updated: 2022/12/01 23:42:04 by aharrass         ###   ########.fr       */
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
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
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
	 
}

void	ft_ra(t_stack	**stack_a)
{
	t_stack *tmp;
	t_stack *tmp2;
	
	tmp2 = find_last(*stack_a);
	tmp = *stack_a;
	*stack_a = tmp->next;
	tmp->next = NULL; 
	tmp2->next = tmp;
}

void	ft_rb(t_stack **stack_b)
{
	t_stack *tmp;
	t_stack *tmp2;

	tmp2 = find_last(*stack_b);
	tmp = *stack_b;
	*stack_b = tmp->next;
	tmp->next = NULL;
	tmp2->next = tmp;	
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
}