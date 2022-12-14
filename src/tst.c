/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:40:50 by aharrass          #+#    #+#             */
/*   Updated: 2022/12/14 16:20:21 by aharrass         ###   ########.fr       */
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

void	ft_medium(t_stack **stack_a, t_stack **stack_b)
{
	int		lst_c;
	int		*arr;
	t_stack	*tmp;
	int		i;
	int		k;
	int		l;
	int		j;
	int		offset;
	int		ok;
	int		n;

	l = 0;
	k = 0;
	i = 0;
	lst_c = lst_count(*stack_a);
	ok = lst_c;
	arr = malloc(sizeof(int) * lst_c);
	tmp = *stack_a;
	while (i < lst_c)
	{
		arr[i++] = tmp->element;
		tmp = tmp->next;
	}
	quick_sort(arr, 0, lst_c - 1);
	// i = 0;
	// while (arr[i])
	// 	printf("%d ", arr[i++]);
	// printf("\n");
	if (lst_c < 150)
		n = 8;
	else
		n = 18;
	offset = lst_c / n;
	i = (lst_c - 1) / 2 + offset;
	j = (lst_c - 1) / 2 - offset;
	while (*stack_a)
	{
		while (*stack_a)
		{
			k = find_from_start(*stack_a, arr, j, i);
			// printf("start = %d, end = %d\n", j, i);
			// printf("k = %d\n", k);
			if (k == lst_c)
			{
				j -= offset;
				if (j < 0)
					j = 0;
				i += offset;
				if (i > ok - 1)
					i = ok - 1;
				break ;
			}
			if (k <= lst_c / 2)
				while (k)
				{
					ft_ra(stack_a);
					k--;
				}
			else if (k > lst_c / 2)
				while (lst_c - k)
				{
					ft_rra(stack_a);
					k++;
				}
			//printf("found --> %d\n", (*stack_a)->element);
			ft_pb(stack_b, stack_a);
			lst_c--;
			if ((*stack_b)->next)
				if ((*stack_b)->element <= arr[ok / 2])
					ft_rb(stack_b);
		// 	tmp = *stack_a;
		// 	printf("----------------\n");
		// 	while (tmp)
		// 	{
		// 		printf("%d\n", tmp->element);
		// 		tmp = tmp->next;
		// 	}
		// 	printf("----------------\n");
		}
	}
	free(arr);
	ft_medium_help(stack_a, stack_b);
	// tmp = *stack_b;
	// printf("----------------\n");
	// while (tmp)
	// {
	// 	printf("%d\n", tmp->element);
	// 	tmp = tmp->next;
	// }
	// printf("----------------\n");
	//printf("progress :%d\n", (*stack_b)->element);
}

void	ft_medium_help(t_stack **stack_a, t_stack **stack_b)
{
	int	index_big;
	int	big;
	int	i;

	while (*stack_b)
	{
		i = 0;
		big = find_biggest(*stack_b);
		index_big = get_index(*stack_b, big);
		if (index_big > (lst_count(*stack_b) / 2))
			while ((*stack_b)->element != big)
			{
				if ((*stack_b)->element == big - 1)
				{
					ft_pa(stack_a, stack_b);
					i = 1;
				}
				else
					ft_rrb(stack_b);
			}
		else if (index_big <= (lst_count(*stack_b) / 2))
			while ((*stack_b)->element != big)
			{
				if ((*stack_b)->element == big - 1)
				{
					ft_pa(stack_a, stack_b);
					i = 1;
				}
				else
					ft_rb(stack_b);
			}
		ft_pa(stack_a, stack_b);
		if (i)
			ft_sa(stack_a);
	}
}
