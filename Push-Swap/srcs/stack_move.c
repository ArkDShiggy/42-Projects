/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 16:27:30 by jcatinea          #+#    #+#             */
/*   Updated: 2017/06/08 16:27:31 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(t_stack *s1, t_stack *s2)
{
	int tmp;
	int i;

	tmp = s1->stack[0];
	i = 0;
	while (i < s1->size - 1)
	{
		s1->stack[i] = s1->stack[i + 1];
		i++;
	}
	i = s2->size;
	while (i > 0)
	{
		s2->stack[i] = s2->stack[i - 1];
		i--;
	}
	s2->stack[0] = tmp;
	s2->size += 1;
	s1->size -= 1;
}

void	stack_rotate(t_stack *s)
{
	int i;
	int tmp;

	i = 0;
	tmp = s->stack[0];
	while (i < s->size - 1)
	{
		s->stack[i] = s->stack[i + 1];
		i++;
	}
	s->stack[s->size - 1] = tmp;

}

void	stack_rev_rotate(t_stack *s)
{
	int i;
	int tmp;

	i = s->size - 1;
	tmp = s->stack[s->size - 1];
	while (i > 0)
	{
		s->stack[i] = s->stack[i - 1];
		i--;
	}
	s->stack[0] = tmp;
}

void	stack_swap(t_stack *s)
{
	int tmp;

	tmp = s->stack[0];
	s->stack[0] = s->stack[1];
	s->stack[1] = tmp;
}
