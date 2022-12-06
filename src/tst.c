/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:40:50 by aharrass          #+#    #+#             */
/*   Updated: 2022/12/05 13:15:19 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_sort_three(t_stack **stack_a)
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
void	ft_small(t_stack **stack_a, t_stack **stack_b)
{
	int	count;
	int	index_small;
	int i;
	
	i = 0;
	if (is_sorted(*stack_a))
		return ;
	count = lst_count(*stack_a);
	if (count == 2)
	{
		ft_sa(stack_a);
		return ;
	}
	index_small = get_index(*stack_a, find_smallest(*stack_a));
	while (count > 3)
	{
		if (index_small > (lst_count(*stack_a) / 2))
		{
			while ((*stack_a)->element != find_smallest(*stack_a))
				ft_rra(stack_a);
		}
		else if (index_small <= (lst_count(*stack_a) / 2))
		{
			while ((*stack_a)->element != find_smallest(*stack_a))
				ft_ra(stack_a);
		}
		ft_pb(stack_b, stack_a);
		count--;
	}
	ft_sort_three(stack_a);
	while (*stack_b)
		ft_pa(stack_a, stack_b);
}