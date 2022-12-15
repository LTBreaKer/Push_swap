/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:28:23 by aharrass          #+#    #+#             */
/*   Updated: 2022/12/14 17:04:26 by aharrass         ###   ########.fr       */
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
	if (stack_a)
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
	}
	return (0);
}

int	find_smallest(t_stack *stack_a)
{
	int		tmp;
	t_stack	*tmp2;

	tmp2 = stack_a;
	if (!stack_a)
		exit(1);
	tmp = stack_a->element;
	while (stack_a->next)
	{
		stack_a = stack_a->next;
		if (stack_a->element < tmp)
			tmp = stack_a->element;
	}
	return (tmp);
}

int	find_biggest(t_stack *stack_b)
{
	int		tmp;
	t_stack	*tmp2;

	tmp2 = stack_b;
	if (!stack_b)
		exit(1);
	tmp = stack_b->element;
	while (stack_b->next)
	{
		stack_b = stack_b->next;
		if (stack_b->element > tmp)
			tmp = stack_b->element;
	}
	return (tmp);
}
