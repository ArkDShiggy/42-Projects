/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 11:52:08 by jcatinea          #+#    #+#             */
/*   Updated: 2017/02/28 11:52:09 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_command(void *stuff, size_t size)
{
	t_command	*command;
	t_op		op;
	int			i;

	i = 0;
	command = (t_command *)stuff;
	op = command->op;
	while (i < op.arg_num)
	{
		free((command->args[i]).label);
		i++;
	}
	free(command);
	size++;
}

void	free_label(void *stuff, size_t size)
{
	t_label *label;

	label = (t_label*)stuff;
	free(label->name);
	free(label);
	size++;
}

void	free_env(t_env *env)
{
	free(env->header);
	ft_lstdel(env->to_write, &free_command);
	ft_lstdel(env->defined_labels, &free_label);
	ft_lstdel(env->used_labels, &free_label);
	free(env->to_write);
	free(env->defined_labels);
	free(env->used_labels);
	free(env);
}
