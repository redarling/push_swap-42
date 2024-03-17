/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:31:21 by asyvash           #+#    #+#             */
/*   Updated: 2024/01/24 13:36:17 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_pos(t_stack *stack)
{
	t_stack	*temp;
	int		max_val;
	int		max_pos;

	max_pos = 1;
	temp = stack;
	max_val = temp->value;
	temp = temp->next;
	while (temp)
	{
		if (max_val < temp->value)
			max_val = temp->value;
		temp = temp->next;
	}
	while (stack->value != max_val)
	{
		stack = stack->next;
		max_pos++;
	}
	return (max_pos);
}

void	simple_sort(t_stack **a, int size)
{
	int	max_pos;

	if (size > 3)
		return ;
	max_pos = get_max_pos(*a);
	if (size == 2 && !is_sorted(*a))
		sa(a);
	else if (size == 3 && !is_sorted(*a))
	{
		if (max_pos == 2)
		{
			rra(a);
			if (!is_sorted(*a))
				sa(a);
		}
		else
		{
			if (max_pos == 1)
				ra(a);
			if (!is_sorted(*a))
				sa(a);
		}
	}
}
