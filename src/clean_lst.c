/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:31:34 by aharrass          #+#    #+#             */
/*   Updated: 2022/11/27 20:33:56 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	clean_lst(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack)
		return ;
	temp = (*stack)->next;
	while (temp)
	{
		free(*stack);
		*stack = temp;
		temp = (*stack)->next;
	}
}
