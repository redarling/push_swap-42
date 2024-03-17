/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:30:57 by asyvash           #+#    #+#             */
/*   Updated: 2024/01/24 14:43:25 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_if_correct(t_stack **a, t_stack **b)
{
	if ((*b) && (*b)->value > get_last_elem(*a) \
		&& (*b)->value < (*a)->value)
		pa(b, a);
	else if (stack_size(*b) > 1 && (*b)->next->value > get_last_elem(*a) \
		&& (*b)->next->value < (*a)->value)
	{
		sb(b);
		pa(b, a);
	}
}

static void	rotate_and_push(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while ((*a)->value < (*b)->value)
	{
		ra(a);
		i++;
	}
	pa(b, a);
	if ((*b) && (*b)->value > (*a)->value)
		rotate_and_push(a, b);
	else if (stack_size(*b) > 1 && (*b)->next->value > (*a)->value)
	{
		sb(b);
		rotate_and_push(a, b);
	}
	while (i > 0)
	{
		rra(a);
		push_if_correct(a, b);
		i--;
	}
}

static void	rotate_and_swap(t_stack **a, t_stack **b)
{
	if (stack_size(*b) > 2 && ((*b)->next->value < (*b)->next->next->value))
	{
		rr(a, b);
		ss(a, b);
		rrr(a, b);
	}
	else
	{
		ra(a);
		sa(a);
		rra(a);
	}
}

static void	push_back_to_a(t_stack **a, t_stack **b, int i)
{
	while (i > 0)
	{
		rrb(b);
		i--;
	}
	simple_sort(a, stack_size(*a));
	while ((*b))
	{
		if (is_sorted(*a) && (*b)->value > (*a)->value \
			&& (*b)->value > (*a)->next->value)
			rotate_and_push(a, b);
		else
		{
			pa(b, a);
			if ((*a)->value > (*a)->next->value \
				&& stack_size(*b) > 1 && ((*b)->value < (*b)->next->value))
				ss(a, b);
			if ((*a)->value > (*a)->next->value)
				sa(a);
			if (!is_sorted(*a))
				rotate_and_swap(a, b);
		}
	}
}

void	push_to_b(t_stack **a, t_stack **b, int threshold[2], int j)
{
	int	full_size;

	full_size = stack_size(*a);
	while (stack_size(*a) > 3)
	{
		if ((*a)->index < threshold[1] && (*a)->index < full_size - 3)
		{
			pb(a, b);
			threshold[1]++;
		}
		else if ((*a)->index > threshold[0] && (*a)->index < full_size - 3)
		{
			pb(a, b);
			if ((*a)->index >= threshold[1] && (*a)->index <= threshold[0])
				rr(a, b);
			else
				rb(b);
			j++;
			threshold[0]--;
		}
		else
			finding_index(a, b, full_size - 3, full_size);
	}
	push_back_to_a(a, b, j);
}
