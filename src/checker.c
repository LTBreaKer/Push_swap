/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:01:00 by aharrass          #+#    #+#             */
/*   Updated: 2022/12/16 15:47:20 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/get_next_line.h"
#include "../header/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*tmp;

	if (ac > 1)
	{
		stack_a = make_stack_2(ac, av);
		stack_b = NULL;
		while (get_next_line(0, &tmp))
		{
			checker_help(tmp, &stack_a, &stack_b);
			free(tmp);
		}
		if (is_sorted(stack_a) && !stack_b)
			printf("OK\n");
		else
			printf("KO\n");
	}
	clean_lst(&stack_a);
	clean_lst(&stack_b);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}
