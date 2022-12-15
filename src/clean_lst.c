/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:31:34 by aharrass          #+#    #+#             */
/*   Updated: 2022/11/27 20:33:56 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	clean_lst(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack)
		return ;
	temp = *stack;
	while ((*stack)->next)
	{
		(*stack) = (*stack)->next;
		free(temp);
		temp = *stack;
	}
}

int	get_index(t_stack *stack_a, int element)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (stack_a->element == element)
			return (i);
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}
