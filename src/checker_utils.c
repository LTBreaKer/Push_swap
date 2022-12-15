/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:45:11 by aharrass          #+#    #+#             */
/*   Updated: 2022/12/15 23:52:33 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/get_next_line.h"
#include "../header/push_swap.h"

void	checker_help(char *tmp, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(tmp, "sa\n"))
		ft_sa(stack_a);
	else if (!ft_strcmp(tmp, "sb\n"))
		ft_sb(stack_b);
	else if (!ft_strcmp(tmp, "ss\n"))
		ft_ss(stack_a, stack_b);
	else if (!ft_strcmp(tmp, "pa\n"))
		ft_pa(stack_a, stack_b);
	else if (!ft_strcmp(tmp, "pb\n"))
		ft_pb(stack_b, stack_a);
	else if (!ft_strcmp(tmp, "ra\n"))
		ft_ra(stack_a);
	else if (!ft_strcmp(tmp, "rb\n"))
		ft_rb(stack_b);
	else if (!ft_strcmp(tmp, "rr\n"))
		ft_rr(stack_a, stack_b);
	else if (!ft_strcmp(tmp, "rra\n"))
		ft_rra(stack_a);
	else if (!ft_strcmp(tmp, "rrb\n"))
		ft_rrb(stack_b);
	else if (!ft_strcmp(tmp, "rrr\n"))
		ft_rrr(stack_a, stack_b);
	else
		exit_checker(stack_a, stack_b, &tmp);
}

void	exit_checker(t_stack **stack_a, t_stack **stack_b, char **tmp)
{
	ft_putendl_fd("Error", 2);
	free(*tmp);
	clean_lst(stack_a);
	clean_lst(stack_b);
	exit(1);
}
