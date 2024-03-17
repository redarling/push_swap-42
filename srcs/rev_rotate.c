/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:31:10 by asyvash           #+#    #+#             */
/*   Updated: 2024/01/24 13:32:37 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_revrotate(t_stack **stack)
{
	t_stack	*last_elem;
	t_stack	*temp;

	if (stack_size(*stack) < 2)
		return ;
	temp = *stack;
	while (temp->next)
	{
		last_elem = temp;
		temp = temp->next;
	}
	last_elem->next = NULL;
	stack_add_front(stack, temp);
}

void	rra(t_stack **stack_a)
{
	stack_revrotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	stack_revrotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	stack_revrotate(stack_a);
	stack_revrotate(stack_b);
	write (1, "rrr\n", 4);
}
