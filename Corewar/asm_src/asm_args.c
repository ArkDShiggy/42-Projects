/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 13:26:24 by jcatinea          #+#    #+#             */
/*   Updated: 2017/03/03 10:21:30 by cfabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	move_position_byte(t_command *command, t_position *pos)
{
	int	i;
	int	code;

	i = 0;
	while (i < (command->op).arg_num)
	{
		code = (command->args)[i].code;
		if (code == REG_CODE)
			pos->byte += 1;
		else if (code == DIR_CODE || code == IND_CODE)
		{
			if ((command->op).label_size == 1 || code == IND_CODE)
				pos->byte += 2;
			else
				pos->byte += 4;
		}
		else
			error("Wrong argument codes have been used");
		i++;
	}
}

int		code_to_type(int code)
{
	if (code == REG_CODE)
		return (T_REG);
	else if (code == DIR_CODE)
		return (T_DIR);
	else if (code == IND_CODE)
		return (T_IND);
	error("Wrong argument codes have been used");
	return (0);
}

t_arg	*check_arg(char *str, t_position *pos, int alleged_type, t_env *env)
{
	int		i;
	int		type;
	t_arg	*arg;
	char	*sub;

	i = 0;
	while (str[pos->col - 1 + i] && is_whitespace(str[pos->col - 1 + i]) == 0
		&& str[pos->col - 1 + i] != SEPARATOR_CHAR)
		i++;
	sub = ft_strsub(str, pos->col - 1, i);
	arg = get_arg(sub, pos, env);
	(pos->col) += i;
	type = code_to_type(arg->code);
	if ((alleged_type & type) == 0)
		parse_error("Wrong type of argument", pos);
	free(sub);
	return (arg);
}

void	add_arg_to_command(t_command *command, t_arg *arg, int i)
{
	if (arg)
	{
		if (i == 0)
			command->code = arg->code;
		else
			command->code += arg->code;
		ft_memcpy(command->args + i, arg, sizeof(t_arg));
	}
	command->code *= 4;
}

void	check_arguments(char *str, t_position *pos, t_env *env,
	t_command *command)
{
	int		i;
	t_arg	*arg;

	i = 0;
	arg = check_arg(str, pos, (command->op).args[i], env);
	add_arg_to_command(command, arg, i);
	free(arg);
	while (++i < (command->op).arg_num)
	{
		skip_whitespace(str, pos);
		if (str[pos->col - 1] != SEPARATOR_CHAR)
			parse_error("Expected separator char", pos);
		(pos->col)++;
		skip_whitespace(str, pos);
		arg = check_arg(str, pos, (command->op).args[i], env);
		add_arg_to_command(command, arg, i);
		free(arg);
	}
	while (++i < 4)
		add_arg_to_command(command, NULL, i);
	move_position_byte(command, pos);
}
