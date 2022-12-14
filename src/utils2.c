/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:15:39 by aharrass          #+#    #+#             */
/*   Updated: 2022/12/18 21:39:47 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	check_args2(char **av, int j)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	i--;
	while (i >= 0)
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		if (j && !av[i][j])
			exit_error();
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				exit_error();
			j++;
		}
		i--;
	}
	ft_free_av(av);
}

void	check_dup(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*save;

	save = *stack_a;
	while ((*stack_a))
	{
		temp = (*stack_a)->next;
		while (temp)
		{
			if ((*stack_a)->element != temp->element)
			{
				temp = temp->next;
			}
			else if ((*stack_a) && temp)
			{
				clean_lst(stack_a);
				exit_error();
			}
		}
		(*stack_a) = (*stack_a)->next;
	}
	*stack_a = save;
}

t_stack	*push_to_stack(t_stack **st, long long element)
{
	t_stack	*next;

	if (element > INT_MAX || element < INT_MIN)
	{
		clean_lst(st);
		exit_error();
	}
	next = ft_lstnew((int)element);
	ft_lstadd_front(st, next);
	return (*st);
}

void	exit_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	*make_arr(t_stack *stack_a)
{
	int	*arr;
	int	lst_c;
	int	i;

	i = 0;
	lst_c = lst_count(stack_a);
	arr = malloc(sizeof(int) * lst_c);
	if (!arr)
	{
		clean_lst(&stack_a);
		exit(1);
	}
	while (i < lst_c)
	{
		arr[i++] = stack_a->element;
		stack_a = stack_a->next;
	}
	quick_sort(arr, 0, lst_c - 1);
	return (arr);
}
