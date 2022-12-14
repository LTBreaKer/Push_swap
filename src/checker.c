/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:01:00 by aharrass          #+#    #+#             */
/*   Updated: 2022/12/14 14:52:13 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include "../get_next_line/get_next_line.h"

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	char *tmp;

	if (ac > 1)
	{
		stack_a = make_stack_2(ac, av);
		stack_b = NULL;
		
		// while (1)
		// {
			tmp = get_next_line(0);
			if (tmp[0] == 's' && tmp[1] == 'a')
				ft_sa(&stack_a);
		// }
		if (is_sorted(stack_a))
		{
			printf("OK\n");
		}
		else
			printf("KO\n");
	}
	return (0);
}