/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:52:09 by asyvash           #+#    #+#             */
/*   Updated: 2024/01/24 14:44:19 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct stack
{
	int				value;
	int				index;
	struct stack	*next;
}	t_stack;

/*FREE STACKS AND EXIT WITH ERROR*/
void	free_stack(t_stack **stack);
void	error_occured(t_stack **stack_a, t_stack **stack_b);

/*SORTING ALGORITHYMS*/
void	push_to_b(t_stack **a, t_stack **b, int threshold[2], int j);
void	simple_sort(t_stack **a, int size);

/*UTILS FOR SORTING ALGORITHMS*/
int		is_sorted(t_stack *stack);
int		stack_size(t_stack *stack);
void	finding_index(t_stack **a, t_stack **b, int threshold, int size);
int		get_last_elem(t_stack *stack);

/*BASIC UTILS*/
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	stack_add_front(t_stack **stack, t_stack *new);

/*******OPERATIONS***********/
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_b, t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif
