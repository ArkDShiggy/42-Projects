/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 13:07:54 by jcatinea          #+#    #+#             */
/*   Updated: 2017/03/03 11:07:20 by cfabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parse_line(char *str, t_position *pos, t_env *env)
{
	t_list		*node;
	t_command	*command;

	skip_whitespace(str, pos);
	if (is_label(str, pos))
	{
		check_label(str, pos, env);
		skip_whitespace(str, pos);
		if (str[pos->col - 1] == 0)
			return ;
	}
	command = (t_command *)ft_memalloc(sizeof(t_command));
	check_instruction(str, pos, command);
	skip_whitespace(str, pos);
	check_arguments(str, pos, env, command);
	if ((command->op).coding_byte == 0)
		pos->byte += 1;
	else
		pos->byte += 2;
	skip_whitespace(str, pos);
	check_endline(str, pos);
	node = ft_lstnew(command, sizeof(t_command));
	ft_lstappend(env->to_write, node);
	free(command);
}

int		is_label(char *str, t_position *pos)
{
	int i;

	i = 0;
	while (str[pos->col - 1 + i] && is_whitespace(str[pos->col - 1 + i]) == 0)
	{
		if (i > 0)
			if (ft_strinc(str[pos->col - 2 + i], LABEL_CHARS) == 0)
				return (0);
		i++;
	}
	if (str[pos->col - 2 + i] == LABEL_CHAR)
		return (1);
	else
		return (0);
}

void	check_label(char *str, t_position *pos, t_env *env)
{
	int		i;
	char	*sub;

	i = 0;
	while (str[pos->col - 1 + i] && is_whitespace(str[pos->col - 1 + i]) == 0)
		i++;
	sub = ft_strsub(str, pos->col - 1, i - 1);
	if (label_exists(env, sub) == 0)
	{
		add_defined_label(env, sub, pos->byte);
	}
	else
	{
		ft_putstr_fd("Warning: Line ", 2);
		ft_putnbr_fd(pos->line, 2);
		ft_putstr_fd(", Col ", 2);
		ft_putnbr_fd(pos->col, 2);
		ft_putstr_fd("\nThe following label was already defined.\n", 2);
		ft_putstr_fd("Second definition is ignored\n", 2);
	}
	free(sub);
	pos->col += i;
}

void	check_instruction(char *str, t_position *pos, t_command *command)
{
	int		i;
	char	*sub;

	i = 0;
	while (is_whitespace(str[pos->col - 1 + i]) == 0)
		i++;
	sub = ft_strsub(str, pos->col - 1, i);
	command->op = get_op_from_name(sub);
	if ((command->op).arg_num == 0)
	{
		if (sub[i] == LABEL_CHAR)
			parse_error("Label use wrong character", pos);
		else
			parse_error("Invalid instruction", pos);
	}
	pos->col += i;
	free(sub);
}
