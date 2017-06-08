/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:12:43 by jcatinea          #+#    #+#             */
/*   Updated: 2017/06/08 15:12:45 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(0);
}

void	valid_arg(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i += 1;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			error("Error");
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	a = new_stack(argc);
	b = new_stack(argc);
	i = 1;
	while (i < argc)
	{
		valid_arg(argv[i]);
		add_to_stack(ft_atoi(argv[i]), a);
		i++;
	}
	print_stack(a);
	print_stack(b);
	read_instructions(a, b);
	if (b->size == 0 && is_ordered(a))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	print_stack(a);
	print_stack(b);
	return (0);
}

void	read_instructions(t_stack *a, t_stack *b)
{
	char *line;

	while (get_next_line(0, &line) == 1)
	{
		ft_putendl(line);
		if (ft_strequ(line, "pa"))
			stack_push(b, a);
		else if (ft_strequ(line, "pb"))
			stack_push(a, b);
		else if (ft_strequ(line, "ra"))
			stack_rotate(a);
		else if (ft_strequ(line, "rb"))
			stack_rotate(b);
		else if (ft_strequ(line, "rra"))
			stack_rev_rotate(a);
		else if (ft_strequ(line, "rrb"))
			stack_rev_rotate(b);
		else
			read_instructions_two(line, a, b);
		//free(line);
	}
}

void	read_instructions_two(char *line, t_stack *a, t_stack *b)
{
	if (ft_strequ(line, "sa"))
		stack_swap(a);
	else if (ft_strequ(line, "sb"))
		stack_swap(b);
	else if (ft_strequ(line, "ss"))
	{
		stack_swap(a);
		stack_swap(b);
	}
	else if (ft_strequ(line, "rr"))
	{
		stack_rotate(a);
		stack_rotate(b);
	}
	else if (ft_strequ(line, "rrr"))
	{
		stack_rev_rotate(a);
		stack_rev_rotate(b);
	}
	else
		error("Error");
}
