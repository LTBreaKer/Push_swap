/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:29:44 by aharrass          #+#    #+#             */
/*   Updated: 2022/12/15 23:12:44 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*print;
	int		n;

	n = 8;
	if (ac > 1)
	{
		stack_a = make_stack_2(ac, av);
		stack_b = NULL;
		if (is_sorted(stack_a))
		{
			clean_lst(&stack_a);
			return (0);
		}
		if (lst_count(stack_a) >= 150)
			n = 18;
		if (lst_count(stack_a) <= 16)
			ft_small(&stack_a, &stack_b);
		else
			ft_medium(&stack_a, &stack_b, n, lst_count(stack_a));
		clean_lst(&stack_a);
	}
}
