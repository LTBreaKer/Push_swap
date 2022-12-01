/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:52:49 by aharrass          #+#    #+#             */
/*   Updated: 2022/11/27 19:08:58 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	tmp = *lst;
	*lst = new;
	new->next = tmp;
}
