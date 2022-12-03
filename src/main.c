/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:29:44 by aharrass          #+#    #+#             */
/*   Updated: 2022/12/03 14:23:18 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	//t_stack	*print;

	if (ac == 1)
	{
		ft_putendl_fd("ERROR", 2);
		exit(1);
	}
	stack_a = make_stack(ac, av);
	stack_b = NULL;
	//print = stack_a;
	// printf("stack a:\n");
	// while (print)
	// {
	// 	printf("%d\n", print->element);
	// 	print = print->next;
	// }
	// printf("-------------------\n");
	// print = stack_b;
	// printf("stack_b:\n");
	// while (print)
	// {
	// 	printf("%d\n", print->element);
	// 	print = print->next;
	// }
	ft_small(&stack_a);
	clean_lst(&stack_a);
}
