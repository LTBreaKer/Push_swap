/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:56:40 by aharrass          #+#    #+#             */
/*   Updated: 2022/12/15 23:39:04 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	medium_if(int *j, int *i, int n, int ok)
{
	(*j) -= ok / n;
	if ((*j) < 0)
		*j = 0;
	*i += ok / n;
	if (*i > ok - 1)
		*i = ok - 1;
}

int	medium_cut(int k, int lst_c, t_stack **stack_a, t_stack **stack_b)
{
	if (k <= lst_c / 2)
	{
		while (k)
		{
			ft_ra(stack_a);
			k--;
		}
	}
	else
	{
		while (lst_c - k)
		{
			ft_rra(stack_a);
			k++;
		}
	}
	ft_pb(stack_b, stack_a);
	return (--lst_c);
}

void	medium_last(t_stack **stack_b, int *arr, int ok)
{
	if ((*stack_b)->next)
		if ((*stack_b)->element <= arr[ok / 2])
			ft_rb(stack_b);
}

void	push_big(t_stack **stack_a, t_stack **stack_b, int big, int *i)
{
	while ((*stack_b)->element != big)
	{
		if ((*stack_b)->element == big - 1)
		{
			ft_pa(stack_a, stack_b);
			*i = 1;
		}
		else
			ft_rrb(stack_b);
	}
}

void	push_big2(t_stack **stack_a, t_stack **stack_b, int big, int *i)
{
	while ((*stack_b)->element != big)
	{
		if ((*stack_b)->element == big - 1)
		{
			ft_pa(stack_a, stack_b);
			*i = 1;
		}
		else
			ft_rb(stack_b);
	}
}
