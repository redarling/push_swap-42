/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:31:02 by asyvash           #+#    #+#             */
/*   Updated: 2024/01/24 16:09:34 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	indexing(t_stack *stack_a, int size)
{
	t_stack	*temp;
	t_stack	*biggest;
	int		val;

	while (--size > 0)
	{
		temp = stack_a;
		val = -2147483648;
		biggest = NULL;
		while (temp)
		{
			if (temp->value == -2147483648 && temp->index == 0)
				temp->index = 1;
			if (temp->value > val && temp->index == 0)
			{
				val = temp->value;
				biggest = temp;
				temp = stack_a;
			}
			else
				temp = temp->next;
		}
		if (biggest != NULL)
			biggest->index = size;
	}
}

static int	check_input(int argc, char **argv, int i)
{
	int	j;

	while (i++, i < argc)
	{
		j = 0;
		while ((argv[i][j] >= 9 && argv[i][j] <= 13) \
				|| argv[i][j] == ' ')
			j++;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (-1);
			j++;
		}
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
				return (-1);
			j++;
		}
	}
	return (0);
}

static t_stack	*stack_init(int argc, char **argv)
{
	int		i;
	t_stack	*stack;
	t_stack	*current;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		error_occured(&stack, NULL);
	current = stack;
	i = 1;
	while (i < argc)
	{
		current->value = ft_atoi(argv[i]);
		current->index = 0;
		if (i + 1 < argc)
		{
			current->next = (t_stack *)malloc(sizeof(t_stack));
			if (!current->next)
				error_occured(&stack, NULL);
			current = current->next;
		}
		i++;
	}
	current->next = NULL;
	return (stack);
}

static void	sort_init(t_stack **a, t_stack **b, int size)
{
	int	threshold[2];

	if (size < 4)
		simple_sort(a, size);
	else
	{
		if (size > 250)
		{
			threshold[0] = size - 18;
			threshold[1] = 13;
			push_to_b(a, b, threshold, 0);
		}
		else
		{
			threshold[0] = size - 9;
			threshold[1] = 6;
			push_to_b(a, b, threshold, 0);
		}
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 2)
		return (0);
	if (check_input(argc, argv, 0) == -1)
	{
		write(2, "Error\n", 6);
		error_occured(NULL, NULL);
	}
	stack_b = NULL;
	stack_a = stack_init(argc, argv);
	if (is_sorted(stack_a))
		error_occured(&stack_a, &stack_b);
	indexing(stack_a, argc - 1);
	sort_init(&stack_a, &stack_b, argc - 1);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
