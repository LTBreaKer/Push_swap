/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:39:46 by aharrass          #+#    #+#             */
/*   Updated: 2022/12/08 13:55:57 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void	quick_sort(int arr[], int start, int end)
{
	int	piv_index;

	if (start < end)
	{
		piv_index = part(arr, start, end);
		quick_sort(arr, start, piv_index - 1);
		quick_sort(arr, piv_index + 1, end);
	}
}

int	part(int arr[], int start, int end)
{
	int	pv;
	int	i;
	int	j;

	pv = arr[end];
	i = start;
	j = i;
	while (j < end)
	{
		if (arr[j] <= pv)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
		j++;
	}
	swap(&arr[i], &arr[end]);
	return (i);
}
