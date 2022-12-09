/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:40:50 by aharrass          #+#    #+#             */
/*   Updated: 2022/12/09 16:08:33 by aharrass         ###   ########.fr       */
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

	j = 0;
	l = 0;
	k = 0;
	i = 0;
	lst_c = lst_count(*stack_a);
	arr = malloc(sizeof(int) * lst_c);
	tmp = *stack_a;
	while (i < lst_c)
	{
		arr[i++] = tmp->element;
		tmp = tmp->next;
	}
	quick_sort(arr, 0, lst_c - 1);
	i = 0;
	while (arr[i])
		printf("%d ", arr[i++]);
	printf("\n");
	i = lst_c / 5;
	while (*stack_a)
	{
		while (*stack_a)
		{
			k = find_from_start(*stack_a, arr, j, i);
			l = find_from_end(*stack_a, arr, j, i);
			printf("start %d back %d\n", k, l);
			if (k >= lst_c - i && l >= lst_c - i)
			{
				j += i;
				i += lst_c / 5;
				break ;
			}
			if (k <= l)
			{
				while (k > 0)
				{
					ft_ra(stack_a);
					k--;
				}
				ft_pb(stack_b, stack_a);
			}
			else
			{
				while (l >= 0)
				{
					ft_rra(stack_a);
					l--;
				}
				ft_pb(stack_b, stack_a);
			}
			tmp = *stack_a;
			printf("----------------\n");
			while (tmp)
			{
				printf("%d\n", tmp->element);
				tmp = tmp->next;
			}
			printf("----------------\n");
		}
	}
	//printf("progress :%d\n", (*stack_b)->element);
}
