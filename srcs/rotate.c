/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:31:17 by asyvash           #+#    #+#             */
/*   Updated: 2024/01/24 13:43:33 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_rotate(t_stack **stack)
{
	t_stack	*first_elem;
	t_stack	*temp;

	if (stack_size(*stack) < 2)
		return ;
	first_elem = *stack;
	*stack = (*stack)->next;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	first_elem->next = NULL;
	temp->next = first_elem;
}

void	ra(t_stack **stack_a)
{
	stack_rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	stack_rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	stack_rotate(stack_a);
	stack_rotate(stack_b);
	write (1, "rr\n", 3);
}
