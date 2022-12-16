/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:40:50 by aharrass          #+#    #+#             */
/*   Updated: 2022/12/16 23:27:54 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_sort_three(t_stack **stack_a)
{
	if (is_sorted(*stack_a))
		return ;
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

void	ft_small(t_stack **stack_a, t_stack **stack_b)
{
	int	count;
	int	index_small;
	int	i;

	i = 0;
	count = lst_count(*stack_a);
	if (count == 2)
		return (ft_sa(stack_a));
	index_small = get_index(*stack_a, find_smallest(*stack_a));
	while (count > 3)
	{
		if (index_small > (lst_count(*stack_a) / 2))
			while ((*stack_a)->element != find_smallest(*stack_a))
				ft_rra(stack_a);
		else if (index_small <= (lst_count(*stack_a) / 2))
			while ((*stack_a)->element != find_smallest(*stack_a))
				ft_ra(stack_a);
		ft_pb(stack_b, stack_a);
		count--;
	}
	ft_sort_three(stack_a);
	while (*stack_b)
		ft_pa(stack_a, stack_b);
}

void	ft_medium(t_stack **stack_a, t_stack **stack_b, int n, int lst_c)
{
	int	*arr;
	int	i;
	int	k;
	int	j;
	int	ok;

	ok = lst_c;
	arr = make_arr(*stack_a);
	i = (lst_c - 1) / 2 + ok / n;
	j = (lst_c - 1) / 2 - ok / n;
	while (*stack_a)
	{
		while (*stack_a)
		{
			k = find_from_start(*stack_a, arr, j, i);
			if (k == lst_c)
			{
				medium_if(&j, &i, n, ok);
				break ;
			}
			lst_c = medium_cut(k, lst_c, stack_a, stack_b);
			medium_last(stack_b, arr, ok);
		}
	}
	return (ft_medium_help(stack_a, stack_b, arr), free(arr));
}

void	ft_medium_help(t_stack **stack_a, t_stack **stack_b, int *arr)
{
	int	index_big;
	int	big;
	int	i;
	int	j;

	while (*stack_b)
	{
		i = 0;
		big = find_biggest(*stack_b);
		while (arr[i] != big)
			i++;
		index_big = get_index(*stack_b, big);
		if (index_big > (lst_count(*stack_b) / 2))
			j = push_big(stack_a, stack_b, big, arr[i - 1]);
		else if (index_big <= (lst_count(*stack_b) / 2))
			j = push_big2(stack_a, stack_b, big, arr[i - 1]);
		ft_pa(stack_a, stack_b);
		if (j)
			ft_sa(stack_a);
	}
}
