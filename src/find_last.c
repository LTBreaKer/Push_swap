/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:28:23 by aharrass          #+#    #+#             */
/*   Updated: 2022/12/01 23:35:45 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_stack	*find_last(t_stack *stack)
{
	
	if (!stack)
		return (NULL);
		
	while (stack->next)
		stack = stack->next;
	return (stack);
}