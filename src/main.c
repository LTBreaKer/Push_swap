/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:29:44 by aharrass          #+#    #+#             */
/*   Updated: 2022/12/09 13:33:22 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*print;

	if (ac > 1)
	{
		
		stack_a = make_stack(ac, av);
		stack_b = NULL;
		// ft_ra(&stack_a);
		// print = stack_a;
		// printf("-------------------\n");
		// while (print->next)
		// {
		// 	printf("%d\n", print->element);
		// 	print = print->next;
		// }
		// printf("%d\n", print->element);
		// printf("--------------------\n");
		// while (print)
		// {
		// 	printf("%d\n", print->element);
		// 	print = print->prev;
		// }
		if (is_sorted(stack_a))
		{
			clean_lst(&stack_a);
			return (0);
		}
		//ft_small(&stack_a, &stack_b);
		// print = stack_a;
		// printf("-------------------\n");
		// while (print->next)
		// {
		// 	printf("%d\n", print->element);
		// 	print = print->next;
		// }
		// printf("%d\n", print->element);
		// printf("--------------------\n");
		// while (print)
		// {
		// 	printf("%d\n", print->element);
		// 	print = print->prev;
		// }
		ft_medium(&stack_a, &stack_b);
		clean_lst(&stack_a);
	}
	//system("leaks push_swap");
}
