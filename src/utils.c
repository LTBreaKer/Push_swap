/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:48:48 by aharrass          #+#    #+#             */
/*   Updated: 2022/12/03 14:28:48 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_stack	*make_stack(int ac, char **av)
{
	t_stack	*stack_a;
	int		i;
	int		j;

	j = 0;
	i = ac - 1;
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		while (av[j])
			j++;
		ac = j;
		i = ac - 1;
	}
	check_args(ac, av, j);
	stack_a = NULL;
	help_push(i, av, &stack_a);
	check_dup(&stack_a);
	return (stack_a);
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

void	check_args(int ac, char **av, int j)
{
	int	i;

	i = ac - 1;
	if (j == 0)
	{
		while (i > 0)
		{
			j = 0;
			if (av[i][j] == '-' || av[i][j] == '+')
				j++;
			while (av[i][j])
			{
				if (!ft_isdigit(av[i][j]))
				{
					ft_putendl_fd("ERROR1", 2);
					exit(1);
				}
				j++;
			}
			i--;
		}
	}
	else
	{
		while (i >= 0)
		{
			j = 0;
			if (av[i][j] == '-' || av[i][j] == '+')
				j++;
			while (av[i][j])
			{
				if (!ft_isdigit(av[i][j]))
				{
					ft_putendl_fd("ERROR1", 2);
					exit(1);
				}
				j++;
			}
			i--;
		}
	}
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
				ft_putendl_fd("ERROR2", 2);
				exit(1);
			}
		}
		(*stack_a) = (*stack_a)->next;
	}
	*stack_a = save;
}

t_stack	*push_to_stack(t_stack **st, long long element)
{
	t_stack	*next;

	if (element > INT_MAX)
	{
		clean_lst(st);
		ft_putendl_fd("ERROR3", 2);
		exit(1);
	}
	next = ft_lstnew((int)element);
	ft_lstadd_front(st, next);
	return (*st);
}
