/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:31:44 by asyvash           #+#    #+#             */
/*   Updated: 2024/01/24 13:47:13 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_push_a(t_stack **popped_stack, t_stack **pushed_stack)
{
	t_stack	*temp;
	t_stack	*new_element;

	if (!*popped_stack)
		return ;
	temp = *popped_stack;
	*popped_stack = (*popped_stack)->next;
	new_element = (t_stack *)malloc(sizeof(t_stack));
	if (!new_element)
		error_occured(popped_stack, pushed_stack);
	new_element->value = temp->value;
	new_element->next = *pushed_stack;
	*pushed_stack = new_element;
	free(temp);
}

static void	stack_push_b(t_stack **popped_stack, t_stack **pushed_stack)
{
	t_stack	*temp;
	t_stack	*new_element;

	if (!*popped_stack)
		return ;
	temp = *popped_stack;
	*popped_stack = (*popped_stack)->next;
	new_element = (t_stack *)malloc(sizeof(t_stack));
	if (!new_element)
		error_occured(popped_stack, pushed_stack);
	new_element->value = temp->value;
	new_element->next = NULL;
	stack_add_front(pushed_stack, new_element);
	free(temp);
}

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	stack_push_a(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	stack_push_b(stack_a, stack_b);
	write(1, "pb\n", 3);
}
