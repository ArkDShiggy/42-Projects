/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 13:35:55 by jcatinea          #+#    #+#             */
/*   Updated: 2017/02/14 13:35:57 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	reverse_write(int fd, void *stuff, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		write(fd, ((char *)stuff) + (len - 1 - i), 1);
		i++;
	}
}

void	write_header(int fd, t_header *header)
{
	unsigned int magic;
	unsigned int size;

	magic = COREWAR_EXEC_MAGIC;
	reverse_write(fd, &magic, 4);
	write(fd, header->prog_name, PROG_NAME_LENGTH);
	size = 0;
	write(fd, &size, 4);
	size = header->prog_size;
	reverse_write(fd, &size, 4);
	write(fd, header->comment, COMMENT_LENGTH);
	size = 0;
	write(fd, &size, 4);
}

void	write_args(int fd, t_command *command, int arg_num, t_list **label_list)
{
	int		i;
	t_arg	arg;
	int		value;
	int		code;

	i = 0;
	while (i < arg_num)
	{
		arg = command->args[i];
		if (arg.code == REG_CODE || arg.numeric == 1)
			value = arg.value;
		else
			value = label_to_value(arg.label, label_list) - arg.value;
		code = arg.code;
		if (code == REG_CODE)
			write(fd, &value, 1);
		else if (code == DIR_CODE || code == IND_CODE)
		{
			if ((command->op).label_size == 1 || code == IND_CODE)
				reverse_write(fd, &value, 2);
			else
				reverse_write(fd, &value, 4);
		}
		i++;
	}
}

void	write_body(int fd, t_list **body, t_list **labels)
{
	t_list		*node;
	t_command	*command;
	char		printed_char;
	t_op		op;

	node = *(body);
	while (node)
	{
		command = (t_command *)(node->content);
		op = command->op;
		printed_char = op.opcode;
		write(fd, &printed_char, 1);
		if (op.coding_byte == 1)
		{
			printed_char = command->code;
			write(fd, &printed_char, 1);
		}
		write_args(fd, command, op.arg_num, labels);
		node = node->next;
	}
}

void	write_file(int fd2, t_env *env)
{
	write_header(fd2, env->header);
	write_body(fd2, env->to_write, env->defined_labels);
	close(fd2);
}
