/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:24:43 by jcatinea          #+#    #+#             */
/*   Updated: 2017/06/08 15:24:44 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack(int max_size)
{
	t_stack *new;

	new = (t_stack *)ft_malloc(sizeof(t_stack));
	new->size = 0;
	new->max_size = max_size;
	new->stack = (int *)ft_malloc(sizeof(int) * max_size);
	return (new);
}

void	add_to_stack(int a, t_stack *stack)
{
	stack->stack[stack->size] = a;
	stack->size += 1;
}

int		is_ordered(t_stack *stack)
{
	int i;

	i = 1;
	while (i < stack->size)
	{
		if (stack->stack[i] < stack->stack[i - 1])
			return (0);
		i++;
	}
	return (1);
}

void	print_stack(t_stack *s)
{
	int i;

	i = 0;
	while (i < s->size)
	{
		ft_putnbr(s->stack[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}
