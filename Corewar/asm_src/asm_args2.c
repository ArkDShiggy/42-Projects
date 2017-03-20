/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_args2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:00:33 by jcatinea          #+#    #+#             */
/*   Updated: 2017/03/06 16:18:47 by cfabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		valid_numeric_arg(char *str, t_position *pos)
{
	int i;
	int value;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (ft_strinc(str[i], "0123456789") == 0)
			parse_error("Expecting a number", pos);
		i++;
	}
	value = ft_secure_atoi(str);
	return (value);
}

void	valid_arg(char *str, t_position *pos, t_env *env, t_arg *arg)
{
	int i;

	i = 0;
	arg->label = NULL;
	arg->value = pos->byte;
	if (str[0] == LABEL_CHAR)
	{
		arg->numeric = 0;
		while (str[++i])
		{
			if (ft_strinc(str[i], LABEL_CHARS) == 0)
				parse_error("Wrong character in label", pos);
		}
		arg->label = (char *)ft_memalloc(sizeof(char) * ft_strlen(str));
		ft_strcpy(arg->label, str + 1);
		add_used_label(env, str + 1);
	}
	else
	{
		arg->numeric = 1;
		arg->value = valid_numeric_arg(str, pos);
	}
}

t_arg	*get_arg(char *str, t_position *pos, t_env *env)
{
	t_arg	*arg;
	int		a;

	arg = (t_arg *)ft_memalloc(sizeof(t_arg));
	arg->label = NULL;
	if (str[0] == 'r')
	{
		arg->code = REG_CODE;
		a = ft_secure_atoi(str + 1);
		if (a >= 1 && a <= REG_NUMBER)
			arg->value = a;
		else
			parse_error("Register number is invalid", pos);
	}
	else if (str[0] == DIRECT_CHAR)
	{
		arg->code = DIR_CODE;
		valid_arg(str + 1, pos, env, arg);
	}
	else
	{
		arg->code = IND_CODE;
		valid_arg(str, pos, env, arg);
	}
	return (arg);
}

int		label_to_value(char *name, t_list **list)
{
	t_list	*node;
	t_label	*label;

	node = *list;
	while (node)
	{
		label = (t_label *)(node->content);
		if (ft_strequ(name, label->name) == 1)
			return (label->byte);
		node = node->next;
	}
	error("Can't find label");
	return (0);
}
