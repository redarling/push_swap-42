/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:31:50 by asyvash           #+#    #+#             */
/*   Updated: 2024/01/24 13:35:28 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_swap(t_stack **stack)
{
	t_stack	*first_elem;
	t_stack	*second_elem;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first_elem = *stack;
	second_elem = (*stack)->next;
	first_elem->next = second_elem->next;
	second_elem->next = first_elem;
	*stack = second_elem;
}

void	sa(t_stack **stack_a)
{
	stack_swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	stack_swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	stack_swap(stack_a);
	stack_swap(stack_b);
	write (1, "ss\n", 3);
}
