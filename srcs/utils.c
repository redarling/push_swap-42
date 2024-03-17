/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:31:35 by asyvash           #+#    #+#             */
/*   Updated: 2024/01/24 14:41:06 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	is_neg;
	long	res;

	if (!str)
		error_occured(NULL, NULL);
	i = 0;
	is_neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		is_neg = -1;
	if (is_neg == -1 || str[i] == '+')
		i++;
	if (str[i] == '\0' || (str[i] == '0' && str[i + 1] != '\0'))
		ft_error();
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	if (res * is_neg < -2147483648 || res * is_neg > 2147483647)
		ft_error();
	return ((int)(res * is_neg));
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	stack_add_front(t_stack **stack, t_stack *new)
{
	if (*stack)
	{
		new->next = *stack;
		*stack = new;
	}
	else
		*stack = new;
}

int	stack_size(t_stack *stack)
{
	int	size;

	if (!stack)
		return (0);
	size = 1;
	while (stack->next)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
