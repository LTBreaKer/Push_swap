/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:40:50 by aharrass          #+#    #+#             */
/*   Updated: 2022/12/03 14:27:30 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_small(t_stack **stack_a)
{
	int	count;

	if (is_sorted(*stack_a))
		return ;
	count = lst_count(*stack_a);
	if (count == 3)
	{
		if ((*stack_a)->element < (*stack_a)->next->element
			&& (*stack_a)->element < (*stack_a)->next->next->element)
		{
			ft_rra(stack_a);
			ft_sa(stack_a);
		}
		else if ((*stack_a)->element > (*stack_a)->next->element
			&& (*stack_a)->element < (*stack_a)->next->next->element)
			ft_sa(stack_a);
		else if ((*stack_a)->element < (*stack_a)->next->element
			&& (*stack_a)->element > (*stack_a)->next->next->element)
			ft_rra(stack_a);
		else if ((*stack_a)->element > (*stack_a)->next->element
			&& (*stack_a)->element > (*stack_a)->next->next->element
			&& (*stack_a)->next->element < (*stack_a)->next->next->element)
			ft_ra(stack_a);
		else
		{
			ft_sa(stack_a);
			ft_rra(stack_a);
		}
	}
}
