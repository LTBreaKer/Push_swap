/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:28:23 by aharrass          #+#    #+#             */
/*   Updated: 2022/12/03 14:27:46 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	lst_count(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

int	is_sorted(t_stack *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->element < stack_a->next->element)
			stack_a = stack_a->next;
		else
			break ;
	}
	if (!stack_a->next)
		return (1);
	return (0);
}
