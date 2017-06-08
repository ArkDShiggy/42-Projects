/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:11:27 by jcatinea          #+#    #+#             */
/*   Updated: 2017/06/08 15:11:36 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "get_next_line.h"

typedef struct	s_stack
{
	int			size;
	int			max_size;
	int			*stack;
}				t_stack;

void			read_instructions(t_stack *a, t_stack *b);
void			read_instructions_two(char *line, t_stack *a, t_stack *b);

t_stack			*new_stack(int max_size);
void			add_to_stack(int a, t_stack *stack);
int				is_ordered(t_stack *stack);
void			print_stack(t_stack *s);

void			stack_push(t_stack *s1, t_stack *s2);
void			stack_rotate(t_stack *s);
void			stack_rev_rotate(t_stack *s);
void			stack_swap(t_stack *s);

#endif
