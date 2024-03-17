/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:31:30 by asyvash           #+#    #+#             */
/*   Updated: 2024/01/24 14:44:06 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_pos(t_stack *stack, int index)
{
	t_stack	*temp;
	int		pos;

	pos = 0;
	temp = stack;
	while (temp)
	{
		if (temp->index == index)
			break ;
		pos++;
		temp = temp->next;
	}
	return (pos);
}

static int	indx_exist(t_stack *stack, int indx)
{
	t_stack	*temp;

	temp = stack;
	while (temp->index != indx)
	{
		if (temp->next == NULL && temp->index != indx)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	finding_index(t_stack **a, t_stack **b, int threshold, int size)
{
	static int	indx;

	if (!indx)
		indx = 0;
	while (indx_exist(*a, indx) == 1 && indx < threshold)
		indx++;
	if (get_pos(*a, indx) <= (threshold / 2) + 1)
		ra(a);
	else
		rra(a);
	if (stack_size(*a) == size && is_sorted(*a))
	{
		free_stack(a);
		free_stack(b);
		exit (0);
	}
}

int	is_sorted(t_stack *stack)
{
	int	value;

	value = stack->value;
	stack = stack->next;
	while (stack)
	{
		if (stack->value > value)
		{
			value = stack->value;
			stack = stack->next;
		}
		else
			return (0);
	}
	return (1);
}

int	get_last_elem(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return (1);
	temp = stack;
	while (temp->next)
		temp = temp->next;
	return (temp->value);
}
