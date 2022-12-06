/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:29:44 by aharrass          #+#    #+#             */
/*   Updated: 2022/12/05 18:51:15 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	stack_a = make_stack(ac, av);
	stack_b = NULL;
	ft_small(&stack_a, &stack_b);
	clean_lst(&stack_a);
	//system("leaks push_swap");
}
