/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:48:48 by aharrass          #+#    #+#             */
/*   Updated: 2022/12/14 17:03:31 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_free_av(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
	return ;
}

void	help_push(int i, char **av, t_stack **a)
{
	int	k;

	k = 0;
	while (av[0][k])
	{
		if (av[0][k] == '+' || av[0][k] == '-')
			k++;
		if (!ft_isdigit(av[0][k++]))
		{
			k = 0;
			break ;
		}
	}
	while (k == 0 && i > 0)
	{
		*a = push_to_stack(a, ft_atoi(av[i--]));
	}
	while (k != 0 && i >= 0)
	{
		*a = push_to_stack(a, ft_atoi(av[i--]));
	}
}

int	find_from_start(t_stack *stack_a, int arr[], int start, int end)
{
	int	steps;
	int	i;

	i = start;
	steps = 0;
	while (stack_a)
	{
		i = start;
		while (i <= end)
		{
			if (stack_a->element != arr[i])
				i++;
			else
				break ;
		}
		if (i <= end && arr[i] == stack_a->element)
			break ;
		stack_a = stack_a->next;
		steps++;
	}
	return (steps);
}

t_stack	*make_stack_2(int ac, char **av)
{
	t_stack	*stack_a;
	int		i;
	int		j;
	char	**tmp;

	j = 0;
	i = ac - 1;
	check_args_2(ac, av);
	stack_a = NULL;
	while (i > 0)
	{
		j = 0;
		tmp = ft_split(av[i], ' ');
		while (tmp[j])
			j++;
		if (j == 0)
			exit_error();
		j--;
		while (j >= 0)
			push_to_stack(&stack_a, ft_atoi(tmp[j--]));
		i--;
		ft_free_av(tmp);
	}
	check_dup(&stack_a);
	return (stack_a);
}

void	check_args_2(int ac, char **av)
{
	int	i;

	i = ac - 1;
	while (i > 0)
	{
		check_args2(ft_split(av[i--], ' '), 0);
	}
}
