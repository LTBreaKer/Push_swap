/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:48:48 by aharrass          #+#    #+#             */
/*   Updated: 2022/12/08 15:32:12 by aharrass         ###   ########.fr       */
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
	if (j)
	{
		ft_free_av(av, j);
	}
	check_dup(&stack_a);
	return (stack_a);
}

void	ft_free_av(char **res, int sub_index)
{
	if (res[sub_index - 1])
	{
		while (sub_index - 1 >= 0)
			free(res[(sub_index--) - 1]);
		free(res);
		return ;
	}
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
		check_args1(ac, av, j);
	else
		check_args2(ac, av, j);
}
